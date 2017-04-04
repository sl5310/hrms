
<?php
error_reporting(E_ALL ^ E_NOTICE);

include "class/css_js.php";
include_once "class/login.php";


  $o = new Login();
  $action="";
  $username ="";
  $password="";

  if(isset($_POST['action'])){
      $action=$_POST['action'];
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
  }else
      $action="";
      $username=$_POST["username"];
      $password=$_POST["password"];

  
 

switch ($action) {
  case 'login':

  $o->verifylogin($username,$password);

  $o->loginform();
    break;
  
  default:
     $o->loginform();
    break;
}
?>
