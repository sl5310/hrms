<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/employee_list.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"
$o = new employee_list();

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


  case 'deactive':
  if($o->deactive($employee_id)===true){
    header("Location: employee_list.php");
  }else{
    header("Location: employee_list.php");
  }
  break;
  
  default:
     $o->listform();
    break;
}



require_once 'components/footer.php';
?>