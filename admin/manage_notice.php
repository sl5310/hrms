<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/manage_notice.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"
$o = new manage_notice();

  $action="";


  if(isset($_POST['action'])){
      $action=$_POST['action'];
        if (isset($_POST['notice_id']))  
      $o->notice_id=mysql_real_escape_string($_POST['notice_id']);
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
      if (isset($_GET['notice_id']))  
      $o->notice_id=mysql_real_escape_string($_GET['notice_id']);
  }else
      $action="";


switch ($action) {


  case 'delete':

      if ($o->delete() === true){
              //redirect after completed
        header("Location: manage_notice.php",500);
          exit;
    }else{
              //redirect after completed
        header("Location: manage_notice.php",500);
          exit;
    }
      break;

  default:
     $o->listform();
    break;
}



require_once 'components/footer.php';
?>