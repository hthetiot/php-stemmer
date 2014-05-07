php-stemmer
===========

This stem extension for PHP provides stemming capability for a variety of
languages using Dr. M.F. Porter's Snowball API.

It has a much simpler API than the stem extension found in pecl.

Usage Example
--------------------

    <?php
        echo stemword('cats', 'english', 'UTF_8');      # cat
        echo stemword('stemming', 'english', 'UTF_8');  # stem
    ?>

Install
--------------------

The stemmer PHP extension can be installed following the instructions about
building PHP extensions using phpize as described in the [PHP manual](http://www.php.net/manual/en/install.pecl.phpize.php).

To build this extension, you need to have the PHP development tools installed.
For ubuntu/debian you can use apt-get install php5-dev.

The phpize command is used to prepare the build environment for a PHP extension.

In the following sample, the sources for an extension are in a directory named stemmer-php:

     # git clone https://github.com/hthetiot/php-stemmer.git
     # cd php-stemmer
     # phpize
     # ./configure
     # make -C libstemmer_c
     # make
     # [sudo] make install

Edit you php.ini file and add the line extension=stemmer.so

About libstemmer_c
--------------------

The stemmer PHP extension uses a modified version of libstemmer_c.

It has replaced the default Dutch stemming algorithm with the much better Kraaij-Pohlmann Dutch stemming algorithm.
The modified version of this lib can be downloaded from [mysqludf.com](http://www.mysqludf.org/lib_mysqludf_stem/).

Original Source
--------------------

This version is a fork of php-stemmer hosted on Google Code orinaly made by
Javeline B.V and available here: http://code.google.com/p/php-stemmer/

Licence
--------------------
[New BSD License](http://opensource.org/licenses/BSD-3-Clause)

See License file for details
