<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/general_setting.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"
$o = new general_setting();

  $action="";


  if(isset($_POST['action'])){
      $action=$_POST['action'];
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
  }else
      $action="";

      if (isset($_POST['name']))    
      {$o->name=mysql_real_escape_string($_POST["name"]);}   

      if (isset($_POST['email']))    
      {$o->email=mysql_real_escape_string($_POST["email"]);}   

      if (isset($_POST['address']))    
      {$o->address=mysql_real_escape_string($_POST["address"]);}   

      if (isset($_POST['city']))    
      {$o->city=mysql_real_escape_string($_POST["city"]);}    

      if (isset($_POST['country_id']))    
      {$o->country_id=mysql_real_escape_string($_POST["country_id"]);}   

      if (isset($_POST['phone']))    
      {$o->phone=mysql_real_escape_string($_POST["phone"]);}

      if (isset($_POST['mobile']))    
      {$o->mobile=mysql_real_escape_string($_POST["mobile"]);}   

      if (isset($_POST['hotline']))    
      {$o->hotline=mysql_real_escape_string($_POST["hotline"]);} 

      if (isset($_POST['fax']))    
      {$o->fax=mysql_real_escape_string($_POST["fax"]);}   

      if (isset($_POST['website']))    
      {$o->website=mysql_real_escape_string($_POST["website"]);} 

      if (isset($_POST['currency']))    
      {$o->currency=mysql_real_escape_string($_POST["currency"]);} 




switch ($action) {

  case 'save':
      if($o->save()===true){
          header("Location: general_setting.php",500);
          exit;
      }else {
        $o->checkexist();
        $o->inputform();
      }
  break;

  case 'update':
      if($o->update()===true){
        
          header("Location: general_setting.php",500);
          exit;
      }else {
        $o->checkexist();
        $o->inputform();
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