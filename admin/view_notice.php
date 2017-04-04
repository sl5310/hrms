<?php 

include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/view_notice.php.inc'; 
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new view_notice();

 if (isset($_GET['notice_id']))  
$o->notice_id=mysql_real_escape_string($_GET['notice_id']);

$o->get_notice_detail();
$o->form();
require_once 'components/footer.php';