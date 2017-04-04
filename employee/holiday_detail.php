<?php 

include 'components/system.php.inc';
include_once 'class/holiday_detail.php.inc'; 
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new holiday_detail();

 if (isset($_GET['holiday_id']))  
$o->holiday_id=mysql_real_escape_string($_GET['holiday_id']);

$o->get_holiday_detail();
$o->form();
require_once 'components/footer.php';