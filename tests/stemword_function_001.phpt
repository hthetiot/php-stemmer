--TEST--
stemword() function - basic test for stemword()
--FILE--
<?php
/* Do not change this test it is a README.TESTING example. */
var_dump(implode(', ', stemword(array('dakpannen','balletje'), 'dutch', 'UTF_8' )));
?>
--EXPECT--
string(11) "dakpan, bal"