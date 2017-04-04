<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/add_employee.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new add_employee();
 $action="";
  if(isset($_POST['action'])){
      $action=$_POST['action'];
  if (isset($_POST['employee_id']))  
      $o->employee_id=$_POST['employee_id'];
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];
   if (isset($_GET['employee_id']))  
      $o->employee_id=$_GET['employee_id'];
  }else
      $action="";

      if (isset($_POST['employment_id']))    
      {$o->employment_id=mysql_real_escape_string($_POST["employment_id"]);}   

      if (isset($_POST['first_name']))    
      {$o->first_name=mysql_real_escape_string($_POST["first_name"]);}   

      if (isset($_POST['last_name']))    
      {$o->last_name=mysql_real_escape_string($_POST["last_name"]);}   

      if (isset($_POST['date_of_birth']))    
      {$o->date_of_birth=mysql_real_escape_string($_POST["date_of_birth"]);}    

      if (isset($_POST['gender']))    
      {$o->gender=mysql_real_escape_string($_POST["gender"]);}   

      if (isset($_POST['marital_status']))    
      {$o->marital_status=mysql_real_escape_string($_POST["marital_status"]);}

      if (isset($_POST['father_name']))    
      {$o->father_name=mysql_real_escape_string($_POST["father_name"]);}   

      if (isset($_POST['nationality']))    
      {$o->nationality=mysql_real_escape_string($_POST["nationality"]);} 

      if (isset($_POST['identity_no']))    
      {$o->identity_no=mysql_real_escape_string($_POST["identity_no"]);}   

      if (isset($_POST['work_pass_category_id']))    
      {$o->work_pass_category_id=mysql_real_escape_string($_POST["work_pass_category_id"]);}   
    
      if (isset($_POST['photo']))    
      {$o->photo=mysql_real_escape_string($_POST["photo"]);}   

      if (isset($_POST['present_address']))    
      {$o->present_address=mysql_real_escape_string($_POST["present_address"]);}   

      if (isset($_POST['city']))    
      {$o->city=mysql_real_escape_string($_POST["city"]);}   

      if (isset($_POST['country_id']))    
      {$o->country_id=mysql_real_escape_string($_POST["country_id"]);}   

      if (isset($_POST['mobile']))    
      {$o->mobile=mysql_real_escape_string($_POST["mobile"]);}   

      if (isset($_POST['phone']))    
      {$o->phone=mysql_real_escape_string($_POST["phone"]);}   

      if (isset($_POST['email']))    
      {$o->email=mysql_real_escape_string($_POST["email"]);}   

      if (isset($_POST['emergency_contact']))    
      {$o->emergency_contact=mysql_real_escape_string($_POST["emergency_contact"]);}   

      if (isset($_POST['department']))    
      {$o->department=mysql_real_escape_string($_POST["department"]);}   

      if (isset($_POST['designation_id']))    
      {$o->designation_id=mysql_real_escape_string($_POST["designation_id"]);}   

      if (isset($_POST['joining_date']))    
      {$o->joining_date=mysql_real_escape_string($_POST["joining_date"]);}   

      if (isset($_POST['probation']))    
      {$o->probation=mysql_real_escape_string($_POST["probation"]);}   

      if (isset($_POST['last_date']))    
      {$o->last_date=mysql_real_escape_string($_POST["last_date"]);}   

      if (isset($_POST['confirmation_date']))    
      {$o->confirmation_date=mysql_real_escape_string($_POST["confirmation_date"]);}   

      if (isset($_POST['isactive']))    
      {$isactive=$_POST["isactive"];
      if($isactive=="Y" or $isactive=="on" )
            $o->isactive=1;
            else
      $o->isactive=0;
      }

      if (isset($_POST['bank_name']))    
      {$o->bank_name=mysql_real_escape_string($_POST["bank_name"]);}   

      if (isset($_POST['branch_name']))    
      {$o->branch_name=mysql_real_escape_string($_POST["branch_name"]);}   

      if (isset($_POST['account_name']))    
      {$o->account_name=mysql_real_escape_string($_POST["account_name"]);}   

      if (isset($_POST['account_number']))    
      {$o->account_number=mysql_real_escape_string($_POST["account_number"]);}   

     if (isset($_POST['employee_user']))    
      {$o->employee_user=mysql_real_escape_string($_POST["employee_user"]);}   

      if (isset($_POST['employee_pass']))    
      {$o->employee_pass=mysql_real_escape_string($_POST["employee_pass"]);} 


    /// EMPLOYEE SALARY
      if (isset($_POST['basic_salary']))    
      {$o->basic_salary=mysql_real_escape_string($_POST["basic_salary"]);}

    if (isset($_POST['employee_cpf_percent']))    
      {$o->employee_cpf_percent=mysql_real_escape_string($_POST["employee_cpf_percent"]);} 

    if (isset($_POST['employer_cpf_percent']))
      {$o->employer_cpf_percent=mysql_real_escape_string($_POST["employer_cpf_percent"]);} 

    if (isset($_POST['sdl_payable']))
      {$o->sdl_payable=mysql_real_escape_string($_POST["sdl_payable"]);} 

    if (isset($_POST['leave_category']))
      {$o->leave_category=mysql_real_escape_string($_POST["leave_category"]);} 

    if (isset($_POST['leave_days']))
      {$o->leave_days=mysql_real_escape_string($_POST["leave_days"]);} 

    


switch ($action) {

	 case 'save':
if($o->checkuser("new")===true){
   if($o->save()===true){
      header("Location: employee_list.php");
       exit;
    }else{
      header("Location: add_employee.php");
      exit;
    }
}else{
   $o->inputform("new");
}
  	 break;

    case 'edit':
       if (isset($o->employee_id)){
         if($o->fetch()===true){
            $o->inputform("edit");
          }else{
          header("Location: employee_list.php");
           exit;
          }
        
      }  
     break;

    case 'update':
    if($o->checkuser("update")===true){
       if (isset($o->employee_id)){
          if($o->update()===true){
          header("Location: add_employee.php?action=edit&employee_id=$o->employee_id");
           exit;
            }else{
          header("Location: add_employee.php?action=edit&employee_id=$o->employee_id");
           exit;
          }
      }
    }else{
        header("Location: add_employee.php?action=edit&employee_id=$o->employee_id");
           exit;
      }
      break;

    case 'del':

        if (isset($_GET['value']))    
      {$value=$_GET["value"];} 
       if (isset($o->employee_id) && isset($value) ){
          if($o->updateDoc($value)===true){
           header("Location: add_employee.php?action=edit&employee_id=$o->employee_id");
           exit;
            }
      }else{
           header("Location: add_employee.php?action=edit&employee_id=$o->employee_id");
           exit;
      }
      break;

    case 'get_designation':
      if (isset($_POST['department_id']))    
      {$department_id=$_POST["department_id"];}   
            echo $o->getDesignation($department_id);die;
      break;

    case 'updatePass':
          if (isset($_POST['change_pass']))    
      {$o->change_pass=$_POST["change_pass"];} 
      $o->updatePass();die;
      break;

//MANAGE SALARY
    case 'update_salary':
    if (isset($o->employee_id)){
        $o->updateSalary();
         header("Location: add_employee.php?action=edit&employee_id=$o->employee_id#manage_salary");
           exit;
    }
        break;

//MANAGE LEAVE
     case 'save_leave':
        if (isset($o->employee_id)){
        $o->save_leave();
         header("Location: add_employee.php?action=edit&employee_id=$o->employee_id#manage_leave");
           exit;
        }
        break;

    case 'updateDays':
     if (isset($_POST['employee_leave_id']))    
        {$employee_leave_id=$_POST["employee_leave_id"];
         
          if (isset($_POST['change_days']))    
          {$change_days=$_POST["change_days"];
          $o->update_leave_days($employee_leave_id,$change_days);die;
          }
      }

    case 'delete_leave':
       if (isset($_GET['employee_leave_id']))    
        {$employee_leave_id=$_GET["employee_leave_id"];
          if($o->delete_leave($employee_leave_id) ===true){
                 header("Location: add_employee.php?action=edit&employee_id=$o->employee_id#manage_leave");
                  exit;
         }else{
               header("Location: add_employee.php?action=edit&employee_id=$o->employee_id#manage_leave");
                exit;
         }
      }
      break;

      break;

    default:
		 $o->inputform("new","");
	  break;
}
 require_once 'components/footer.php';
?>