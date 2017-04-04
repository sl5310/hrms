<?php 

include 'components/system.php.inc';
include_once 'class/leave_application.php.inc'; 
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new leave_application();
$o->form();
require_once 'components/footer.php';