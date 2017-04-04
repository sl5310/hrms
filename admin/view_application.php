<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/view_application.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"
$o = new view_application();

  $action="";


  if(isset($_POST['action'])){
      $action=$_POST['action']; 
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
  }else
      $action="";

    if (isset($_POST['application_id']))  
      $o->application_id=mysql_real_escape_string($_POST['application_id']);

    if (isset($_GET['application_id']))  
      $o->application_id=mysql_real_escape_string($_GET['application_id']);

    if (isset($_POST['application_status']))  
      $o->application_status=mysql_real_escape_string($_POST['application_status']);
    
    if (isset($_POST['total_days']))  
      $o->total_days=mysql_real_escape_string($_POST['total_days']);

switch ($action) {


  case 'update':
  if($o->update()===true){
    header("Location: application_list.php");
    exit;
  }else{
    header("Location: application_list.php");
    exit;
  }
  break;
  
  default:
    $o->fetch();
    $o->inputform();
    break;
}



require_once 'components/footer.php';
?>