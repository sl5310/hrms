<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/department_list.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"
$o = new department_list();

  $action="";


  if(isset($_POST['action'])){
      $action=$_POST['action'];
      if (isset($_POST['department_id']))    
      {$o->department_id=mysql_real_escape_string($_POST["department_id"]);}  
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
      if (isset($_GET['department_id']))    
      {$o->department_id=mysql_real_escape_string($_GET["department_id"]);}  

  }else
      $action="";



switch ($action) {

  case 'delete':
  if($o->checkDel() === true){
    if($o->delete()===true){
          header("Location: department_list.php",500);
          exit;
      }else {
        header("Location: department_list.php",500);
          exit;
      }
  }else{
      header("Location: department_list.php",500);
          exit;
  }
  break;
  
  default:
     $o->listform();
    break;
}



require_once 'components/footer.php';
?>