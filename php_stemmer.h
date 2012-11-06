#ifndef PHP_STEMMER_PHP_H
#define PHP_STEMMER_PHP_H 1

#define PHP_STEMMER_VERSION "1.0"
#define PHP_STEMMER_EXTNAME "stemmer"

PHP_FUNCTION(stemword);

extern zend_module_entry stemmmer_module_entry;
#define phpext_stemmer_ptr &stemmer_module_entry

#endif
