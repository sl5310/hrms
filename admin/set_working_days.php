<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/set_working_days.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new set_working_days();
 $action="";

  if(isset($_POST['action'])){
      $action=$_POST['action'];
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
  }else
      $action="";


      if (isset($_POST['day']))    
      {$o->day=$_POST["day"];} 

switch ($action) {

	case 'save':
		if($o->save()===true){
		header("Location: set_working_days.php",500);
          exit;
		}else{
				header("Location: set_working_days.php",500);
          exit;
		}
		break;
	
	default:
		 $o->inputform();
		break;
	}	

 require_once 'components/footer.php';