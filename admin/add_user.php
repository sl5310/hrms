<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/add_user.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new add_user();
 $action="";
  if(isset($_POST['action'])){
      $action=$_POST['action'];
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];

  }else
      $action="";

     if (isset($_POST['first_name']))    
      {$o->first_name=$_POST["first_name"];}   

      if (isset($_POST['last_name']))    
      {$o->last_name=$_POST["last_name"];}   

      if (isset($_POST['username']))    
      {$o->username=$_POST["username"];}   

      if (isset($_POST['password']))    
      {$o->password=$_POST["password"];}   

      if (isset($_POST['permission']))    
      {$o->permission=$_POST["permission"];}   

      if (isset($_POST['prm_add']))    
      {$prm_add=$_POST["prm_add"];
      if($prm_add=="Y" or $prm_add=="on" )
         $o->prm_add=1;
            else
        $o->prm_add=0;
    }   




     if (isset($_POST['prm_update']))    
      {$prm_update=$_POST["prm_update"];
     if($prm_update=="Y" or $prm_update=="on" )
           $o->prm_update=1;
              else
          $o->prm_update=0;
    }   

     
      

     if (isset($_POST['prm_delete']))    
      {$prm_delete=$_POST["prm_delete"];
       if($prm_delete=="Y" or $prm_delete=="on" )
             $o->prm_delete=1;
                else
            $o->prm_delete=0;
    }   

     if (isset($_POST['isactive']))    
      {$isactive=$_POST["isactive"];
   if($isactive=="Y" or $isactive=="on" )
         $o->isactive=1;
            else
        $o->isactive=0;}  

     
      



switch ($action) {

  case 'save':

if($o->checkuser()===true){
   if($o->save()===true){
      header("Location: add_user.php");
      exit;
    }else{
      header("Location: add_user.php");
      exit;
    }
}else{
   $o->inputform("new");
}
   
    break;
  
  default:
		 $o->inputform("new");
	 break;
}
 require_once 'components/footer.php';
?>