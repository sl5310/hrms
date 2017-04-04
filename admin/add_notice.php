<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/add_notice.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new add_notice();
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
 	if (isset($_POST['title']))  
    $o->title=mysql_real_escape_string($_POST['title']);

 	if (isset($_POST['short_description']))
    $o->short_description=mysql_real_escape_string($_POST['short_description']);

 	if (isset($_POST['long_description']))
    $o->long_description=mysql_real_escape_string($_POST['long_description']);

 	if (isset($_POST['flag']) == 1){
       $o->flag=1;
      }else{
      	$o->flag=0;
      }
      

switch ($action) {
	case 'save':
		if ($o->save() === true){
        //redirect after completed
    	  header("Location: manage_notice.php",500);
          exit;
		}else{
			        //redirect after completed
    	  header("Location: manage_notice.php",500);
          exit;
		}
		break;
	
  case 'edit':
    if(isset($o->notice_id)){

      $o->fetch();
      $o->inputform("edit");
    }
    break;

  case 'update':
    if ($o->update() === true) {
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
		$o->inputform("new");
		break;
	}
require_once 'components/footer.php';
?>