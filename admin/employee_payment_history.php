<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/employee_payment_history.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"
$o = new employee_payment_history();

  $action="";


  if(isset($_POST['action'])){
      $action=$_POST['action'];
        if (isset($_POST['employee_id']))  
      $employee_id=mysql_real_escape_string($_POST['employee_id']);
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
      if (isset($_GET['employee_id']))  
      $employee_id=mysql_real_escape_string($_GET['employee_id']);
  }else
      $action="";


switch ($action) {
  default:
     $o->listform();
    break;
}



require_once 'components/footer.php';
?>