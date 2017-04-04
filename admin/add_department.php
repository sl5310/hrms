<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/add_department.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new add_department();
 $action="";


  if(isset($_POST['action'])){
      $action=$_POST['action'];
      if (isset($_POST['department_id']))  
      $o->department_id=mysql_real_escape_string($_POST['department_id']);
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
      if (isset($_GET['department_id']))  
      $o->department_id=mysql_real_escape_string($_GET['department_id']);
  }else
      $action="";

      if (isset($_POST['department_name']))    
      {$o->department_name=mysql_real_escape_string($_POST["department_name"]);}   

      if (isset($_POST['department_code']))    
      {$o->department_code=mysql_real_escape_string($_POST["department_code"]);}   


      if (isset($_POST['designations']))    
      {$arr_designation=$_POST["designations"];}

    if (isset($_POST['arr_designation_id']))    
      {$arr_designation_id=$_POST["arr_designation_id"];}

      if (isset($_POST['designation_id']))    
      {$designation_id=$_POST["designation_id"];}  

switch ($action) {

  case 'save':
   
    if ($o->save_department()===true) {
            //check array unique key and case sensitive
      $designations = array_intersect_key($arr_designation, array_unique(array_map('strtolower', $arr_designation)));

     foreach ($designations as $key=>$value ) {
        //if array value is null
        if(empty($value) || $value = NULL || $value = ""){
          continue;
        }

      //assign desination from array
      $o->designations=mysql_real_escape_string($designations[$key]);
      // save designation
      $o->save_designation();

    }

    //redirect after complated
    header("Location: department_list.php",500);
          exit;
    }
    break;
  
  case 'edit':
    if(isset($o->department_id)){
      $o->fetch();
      $o->inputform("edit");
  }
  break;

  case 'update':
  if ($o->update_department()===true) {

    $i= 0;
       //check array unique key and case sensitive
      $designations = array_intersect_key($arr_designation, array_unique(array_map('strtolower', $arr_designation)));
     foreach ($designations as $key=>$value ) {
  
        //if array value is null
        if(empty($value) || $value = NULL || $value = ""){
          continue;
        }
      //assign desination from array
      $o->designations = $designations[$key];

      // save designation
      $o->update_designation($arr_designation_id[$i]);
    $i++;
    }
    //redirect after complated
    header("Location: department_list.php",500);
          exit;
    }

  break;

  case 'delete':
     if ($o->delete($designation_id)===true) {
      $o->fetch();
      $o->inputform("edit");
    }
  break;
 
  default:
     $o->inputform("new","");
  break;
}





require_once 'components/footer.php';
?>