<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/update_profile.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new update_profile();
 $action="";
  if(isset($_POST['action'])){
      $action=$_POST['action'];
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
  }else
      $action="";


  if(isset($_POST['first_name'])){
      $o->first_name=mysql_real_escape_string($_POST['first_name']);
  }

  if(isset($_POST['last_name'])){
      $o->last_name=mysql_real_escape_string($_POST['last_name']);
  }

  if(isset($_POST['user_name'])){
      $o->user_name=mysql_real_escape_string($_POST['user_name']);
  }

  if(isset($_POST['old_password'])){
      $o->old_password=($_POST['old_password']);
  }

  if(isset($_POST['new_password'])){
      $o->new_password=($_POST['new_password']);
  }



switch ($action) {

  case 'update_profile':
  if ($o->check_user_name() === true){
    if($o->update_info()===true){
      header("Location: update_profile.php");
      exit;
    }else{
      header("Location: update_profile.php");
      exit;
    }
  }else{
       header("Location: update_profile.php");
      exit;
  }
    break;

  case 'update_password':
    if ($o->checkpass() === true){
      if($o->update_pass() === true){
         header("Location: update_profile.php");
          exit;
      }else{
         header("Location: update_profile.php");
          exit;
      }
         
    }else{
      header("Location: update_profile.php");
         exit;
    }
    break;

  default:
  $o->fetch_info();
		 $o->inputform();
	 break;
}
 require_once 'components/footer.php';
?>