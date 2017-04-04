<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/set_holidays.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new set_holidays();
 $action="";
  if(isset($_POST['action'])){
      $action=$_POST['action'];
    if(isset($_POST['holiday_id'])){
      $o->holiday_id=$_POST['holiday_id'];
      }
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
    if(isset($_GET['holiday_id'])){
      $o->holiday_id=$_GET['holiday_id'];
      }

  }else
      $action="";


  if(isset($_POST['event_name'])){
      $o->event_name=mysql_real_escape_string($_POST['event_name']);
  }

  if(isset($_POST['description'])){
      $o->description=mysql_real_escape_string($_POST['description']);
  }

  if(isset($_POST['event_date'])){
      $o->event_date=mysql_real_escape_string($_POST['event_date']);
  }


switch ($action) {

  case 'save':

    if($o->save()===true){
      header("Location: set_holidays.php");
      exit;
    }else{
      header("Location: set_holidays.php");
      exit;
    }
    break;

  case 'refresh':
  $o->inputform("new","");
    break;

  case 'edit':

   if($o->edit()===true){
    
     $o->inputform("edit");
    }else{
      header("Location: set_holidays.php");
      exit;
    }
    break;

  case 'update':

    if($o->update()===true){
     $o->inputform("edit");
    }else{
      header("Location: set_holidays.php");
      exit;
    }
    break;

  case 'delete':
    if($o->delete()===true){
       header("Location: set_holidays.php");
      exit;
    }else{
      header("Location: set_holidays.php");
      exit;
    }
    break;

  default:
		 $o->inputform("new");
	 break;
}
 require_once 'components/footer.php';
?>