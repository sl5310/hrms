<?php 

include 'components/system.php.inc';
include_once 'class/change_password.php.inc'; 
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new change_password();
 $action="";
  if(isset($_POST['action'])){
      $action=$_POST['action'];
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];

  }else
      $action="";

     if (isset($_POST['old_password']))    
      {$o->old_password=$_POST["old_password"];}   

      if (isset($_POST['new_password']))    
      {$o->new_password=$_POST["new_password"];}

switch ($action) {
	case 'update':
		if ($o->checkpass() === true){
			if($o->update() === true){
				 header("Location: change_password.php");
		      exit;
		  }else{
		  	 header("Location: change_password.php");
		      exit;
		  }
		     
		}else{
			header("Location: change_password.php");
	     	 exit;
		}
		break;
	
	default:
		$o->form();
		break;
}

require_once 'components/footer.php';