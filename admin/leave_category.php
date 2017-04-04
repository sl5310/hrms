<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/leave_category.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new leave_category();
 $action="";

  if(isset($_POST['action'])){
      $action=$_POST['action'];
 
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];

  }else
      $action="";

      if(isset($_POST['category'])){
      $o->category=mysql_real_escape_string($_POST['category']);}

      if(isset($_POST['isactive'])){
      $isactive=mysql_real_escape_string($_POST['isactive']);

      if($isactive=="Y" or $isactive=="on" )
       $o->isactive=1;
      else
      $o->isactive=0;}

      if(isset($_GET['leave_category_id'])){
      $o->leave_category_id=$_GET['leave_category_id'];
  		}
  	if(isset($_POST['leave_category_id'])){
      $o->leave_category_id=$_POST['leave_category_id'];
  		}

switch ($action) {

	case 'save':
		if($o->save()===true){
		header("Location: leave_category.php",500);
          exit;
		}else{
				header("Location: leave_category.php",500);
          exit;
		}
		break;
	
	case 'edit':

		$o->edit();
		$o->inputform("edit");
		break;

	case 'update':

		if ($o->update() === true){
		header("Location: leave_category.php",500);
          exit;
		}else{
		header("Location: leave_category.php",500);
          exit;
		}

		break;

	case 'delete':
	if ($o->checkDel() === true){
		if ($o->delete() === true){
		header("Location: leave_category.php",500);
          exit;
		}else{
		header("Location: leave_category.php",500);
          exit;
		}
	}else{
		header("Location: leave_category.php",500);
          exit;
    }
		break;
	

	default:
		 $o->inputform("new");
		break;
}

 require_once 'components/footer.php';