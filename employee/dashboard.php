<?php 

include 'components/system.php.inc';
include_once 'class/dashboard.php.inc'; 
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new dashboard();
$o->information();
$o->form();
require_once 'components/footer.php';