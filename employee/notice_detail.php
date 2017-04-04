<?php 

include 'components/system.php.inc';
include_once 'class/notice_detail.php.inc'; 
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new notice_detail();

 if (isset($_GET['notice_id']))  
$o->notice_id=mysql_real_escape_string($_GET['notice_id']);

$o->get_notice_detail();
$o->form();
require_once 'components/footer.php';