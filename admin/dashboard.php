<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/dashboard.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"
$o = new dashboard();

  $action="";


  if(isset($_POST['action'])){
      $action=$_POST['action'];
        if (isset($_POST['application_id']))  
      $application_id=mysql_real_escape_string($_POST['application_id']);
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
      if (isset($_GET['application_id']))  
      $application_id=mysql_real_escape_string($_GET['application_id']);
  }else
      $action="";


switch ($action) {

  default:
    $o->countEmployee();
    $o->countDepartment();
     $o->form();
    break;
}



require_once 'components/footer.php';
?>