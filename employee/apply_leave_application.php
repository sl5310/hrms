<?php
include 'components/system.php.inc';
include_once 'class/apply_leave_application.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new apply_leave_application();
 $action="";

 if(isset($_POST['action'])){
      $action=$_POST['action'];
      if (isset($_POST['application_id']))  
      $o->application_id=mysql_real_escape_string($_POST['application_id']);
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
      if (isset($_GET['application_id']))  
      $o->application_id=mysql_real_escape_string($_GET['application_id']);
  }else
    $action="";

 	if (isset($_POST['leave_category_id']))  
    $o->leave_category_id=mysql_real_escape_string($_POST['leave_category_id']);

 	if (isset($_POST['start_date']))
    $o->start_date=mysql_real_escape_string($_POST['start_date']);

 	if (isset($_POST['end_date']))
    $o->end_date=mysql_real_escape_string($_POST['end_date']);

  if (isset($_POST['reason']))
    $o->reason=mysql_real_escape_string($_POST['reason']);
      

switch ($action) {
	case 'save':
		if ($o->save() === true){
        //redirect after completed
    	  header("Location: apply_leave_application.php",500);
          exit;
		}else{
			        //redirect after completed
    	  header("Location: apply_leave_application.php",500);
          exit;
		}
		break;
	
  case 'view':
    if(isset($o->application_id)){
      $o->fetch();
      $o->inputform("edit");
    }
    break;

  case 'update':
    if ($o->update() === true) {
        header("Location: leave_application.php",500);
          exit;
    }else{
              //redirect after completed
        header("Location: leave_application.php",500);
          exit;
    }
    break;

  case 'delete':
    if($o->delete() === true){
      header("Location: leave_application.php",500);
          exit;
    }else{
      header("Location: leave_application.php",500);
          exit;
    }
    break;

  case 'countLeaveDays':

  if (isset($_POST['start_date']))
    $start_date=mysql_real_escape_string($_POST['start_date']);

  if (isset($_POST['end_date']))
    $end_date=mysql_real_escape_string($_POST['end_date']);

   echo $o->countLeaveDays($start_date,$end_date);die;
    break;
	default:
		$o->inputform("new");
		break;
	}
require_once 'components/footer.php';
?>