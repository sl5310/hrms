<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/work_pass_category.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new work_pass_category();
 $action="";

  if(isset($_POST['action'])){
      $action=$_POST['action'];
 
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];

  }else
      $action="";

      if(isset($_POST['category'])){
      $o->category=mysql_real_escape_string($_POST['category']);}

      if(isset($_POST['category_code'])){
      $o->category_code=mysql_real_escape_string($_POST['category_code']);}

      if(isset($_POST['isactive'])){
      $isactive=$_POST['isactive'];

      if($isactive=="Y" or $isactive=="on" )
       $o->isactive=1;
      else
      $o->isactive=0;}


      if(isset($_GET['work_pass_category_id'])){
      $o->work_pass_category_id=mysql_real_escape_string($_GET['work_pass_category_id']);}

      if(isset($_POST['work_pass_category_id'])){
      $o->work_pass_category_id=mysql_real_escape_string($_POST['work_pass_category_id']);}

switch ($action) {

	case 'save':
		if($o->save()===true){
		header("Location: work_pass_category.php",500);
          exit;
		}else{
				header("Location: work_pass_category.php",500);
          exit;
		}
		break;

	case 'edit':
		$o->edit();
		$o->inputform("edit");
		break;

	case 'update':

		if ($o->update() === true){
		header("Location: work_pass_category.php",500);
          exit;
		}else{
		header("Location: work_pass_category.php",500);
          exit;
		}
		break;

	case 'delete':

	if($o->checkDel() === true){
		if ($o->delete() === true){
		header("Location: work_pass_category.php",500);
          exit;
		}else{
		header("Location: work_pass_category.php",500);
          exit;
		}
	}else{
     	 header("Location: work_pass_category.php",500);
          exit;
  	}
		break;

	default:
		 $o->inputform("new");
		break;
}

 require_once 'components/footer.php';