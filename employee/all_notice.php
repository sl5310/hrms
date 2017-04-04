<?php 

include 'components/system.php.inc';
include_once 'class/all_notice.php.inc'; 
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new all_notice();
$o->form();
require_once 'components/footer.php';