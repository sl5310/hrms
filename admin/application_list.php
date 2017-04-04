<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/application_list.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"
$o = new application_list();

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

if (isset($_POST['mark_application_id']))  
      $mark_application_id=($_POST['mark_application_id']);

switch ($action) {


  case 'deactive':
  if($o->deactive($employee_id)===true){
    header("Location: employee_list.php");
  }else{
    header("Location: employee_list.php");
  }
  break;
  
  default:
  print_r($mark_application_id);
     $o->form();
    break;
}



require_once 'components/footer.php';
?>