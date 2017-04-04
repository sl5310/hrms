<?php 
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/set_overtime_rate.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new set_overtime_rate();
 $action="";
  if(isset($_POST['action'])){
      $action=$_POST['action'];
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
  }else
      $action="";

	if(isset($_POST['overtime_rate'])){
      $o->overtime_rate=mysql_real_escape_string($_POST['overtime_rate']);
	}

	if(isset($_POST['hours_week'])){
	  $o->hours_week=mysql_real_escape_string($_POST['hours_week']);
	}

  if(isset($_POST['flag'])){
    $flag=$_POST['flag'];

      if($flag=="Y" or $flag=="on" )
       $o->flag=1;
      else
      $o->flag=0;
  }




switch ($action) {

  case 'save':

    if($o->save()===true){
      header("Location: set_overtime_rate.php");
      exit;
    }else{
      header("Location: set_overtime_rate.php");
      exit;
    }
    break;

  case 'update':
    if($o->update()===true){
     header("Location: set_overtime_rate.php");
      exit;
    }else{
      header("Location: set_overtime_rate.php");
      exit;
    }
    break;

  default:
  		 $o->checkexist();
  		 $o->fetch();
		 $o->inputform();
	 break;
}
 require_once 'components/footer.php';
?>