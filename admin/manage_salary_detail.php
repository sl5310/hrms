<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/manage_salary_detail.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new manage_salary_detail();
 $action="";
  if(isset($_POST['action'])){
      $action=$_POST['action'];
  if (isset($_POST['employee_id']))  
      $employee_id=$_POST['employee_id'];
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
  }else
      $action="";

 if (isset($_GET['employee_id']))  
      $employee_id=$_GET['employee_id'];

switch ($action) {
  case 'value':
    # code...
    break;
  
  default:
    if ($o->fetch($employee_id) === true){
      $o->inputform();
    }else{
      die;
    }
    
    break;
}
  require_once 'components/footer.php';
?>