#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_stemmer.h"
#include "libstemmer_c/include/libstemmer.h"

static function_entry stemmer_functions[] = {
    PHP_FE(stemword, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry stemmer_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_STEMMER_EXTNAME,
    stemmer_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_STEMMER_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_STEMMER
ZEND_GET_MODULE(stemmer)
#endif



PHP_FUNCTION(stemword)
{
    zval *lang, *enc, *arg;
    
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &arg,&lang,&enc) == FAILURE)RETURN_NULL();
      
    convert_to_string(lang);
    convert_to_string(enc);
                   
    struct sb_stemmer * stemmer;
    
    //char * language = "kraaij_pohlmann";
    //char * charenc = "UTF_8";
        
    stemmer = sb_stemmer_new(Z_STRVAL_P(lang),Z_STRVAL_P(enc));
    if(!stemmer) RETURN_NULL();
    
    if(Z_TYPE_P(arg) == IS_ARRAY)
    {
      array_init(return_value);
      zval **data;
      HashTable *arr_hash;
      HashPosition pointer;
      int array_count;
      arr_hash = Z_ARRVAL_P(arg);
      array_count = zend_hash_num_elements(arr_hash);
      for( zend_hash_internal_pointer_reset_ex(arr_hash,&pointer);
           zend_hash_get_current_data_ex(arr_hash,(void **)&data, &pointer)==SUCCESS;
           zend_hash_move_forward_ex(arr_hash,&pointer) ){
                  
          const sb_symbol *stemmed = "";
          if(Z_TYPE_PP(data) == IS_STRING){
            stemmed = sb_stemmer_stem(stemmer, Z_STRVAL_PP(data), Z_STRLEN_PP(data));
          }
          add_next_index_string(return_value,stemmed,1);         
      }
    }else{
      convert_to_string(arg);    
      const sb_symbol *stemmed = sb_stemmer_stem(stemmer, Z_STRVAL_P(arg), Z_STRLEN_P(arg));
      if(stemmed)ZVAL_STRING( return_value, stemmed, 1);
    }
    sb_stemmer_delete(stemmer);
    
   // RETURN_STRING(stemmed, 1);
   //return 1;
}


