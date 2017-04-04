<?php
include 'components/system.php.inc'; 
include_once 'components/menu.php';
include_once 'class/make_payment.php.inc';
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE); //display error when found"

$o = new make_payment();
 $action="";

  if(isset($_POST['action'])){
      $action=$_POST['action'];
 
  }elseif(isset($_GET['action'])){
      $action=$_GET['action'];

  }else
      $action="";

      if(isset($_POST['employee_id'])){
      $o->employee_id=mysql_real_escape_string($_POST['employee_id']);}

      if(isset($_GET['employee_id'])){
      $o->employee_id=mysql_real_escape_string($_GET['employee_id']);}

      if(isset($_POST['payment_id'])){
      $o->payment_id=mysql_real_escape_string($_POST['payment_id']);}

      if(isset($_GET['payment_id'])){
      $o->payment_id=mysql_real_escape_string($_GET['payment_id']);}

      if(isset($_POST['payment_month'])){
      $o->payment_month=mysql_real_escape_string($_POST['payment_month']);}

      if(isset($_POST['basic_salary'])){
      $o->basic_salary=mysql_real_escape_string($_POST['basic_salary']);}


      if(isset($_POST['total_ot_pay'])){
      $o->total_ot_pay=mysql_real_escape_string($_POST['total_ot_pay']);}

      if(isset($_POST['ot_hours_worked'])){
      $o->ot_hours_worked=mysql_real_escape_string($_POST['ot_hours_worked']);}

      if(isset($_POST['employee_cpf'])){
      $o->employee_cpf=mysql_real_escape_string($_POST['employee_cpf']);}

      if(isset($_POST['employer_cpf'])){
      $o->employer_cpf=mysql_real_escape_string($_POST['employer_cpf']);}

      if(isset($_POST['sdl_payable'])){
      $o->sdl_payable=mysql_real_escape_string($_POST['sdl_payable']);}

      if(isset($_POST['net_salary'])){
      $o->net_salary=mysql_real_escape_string($_POST['net_salary']);}

      if(isset($_POST['payment_amount'])){
      $o->payment_amount=mysql_real_escape_string($_POST['payment_amount']);}

      if(isset($_POST['payment_type'])){
      $o->payment_type=mysql_real_escape_string($_POST['payment_type']);}

      if(isset($_POST['payment_date'])){
      $o->payment_date=mysql_real_escape_string($_POST['payment_date']);}

      if(isset($_POST['comments'])){
      $o->comments=mysql_real_escape_string($_POST['comments']);}

      //ARRAY AT BELOW

      if(isset($_POST['item_cpf_remark'])){
      $item_cpf_remark=$_POST['item_cpf_remark'];}

      if(isset($_POST['item_cpf_amount'])){
      $item_cpf_amount=$_POST['item_cpf_amount'];}

      if(isset($_POST['item_NON_cpf_remark'])){
      $item_NON_cpf_remark=$_POST['item_NON_cpf_remark'];}

      if(isset($_POST['item_NON_cpf_amount'])){
      $item_NON_cpf_amount=$_POST['item_NON_cpf_amount'];}

      if(isset($_POST['deduc_remark'])){
      $deduc_remark=$_POST['deduc_remark'];}

      if(isset($_POST['deduc_amount'])){
      $deduc_amount=$_POST['deduc_amount'];}

      if(isset($_POST['gross_salary'])){
      $o->gross_salary=$_POST['gross_salary'];}

      if(isset($_POST['hidden_deduction'])){
      $o->hidden_deduction=$_POST['hidden_deduction'];}


switch ($action) {

  case 'save':

  if ($o->save() === true){

      //item with CPF
      if(!empty($item_cpf_remark)){
           foreach ($item_cpf_remark as $key=>$value ) {
              if(empty($value) || $value = NULL || $value = ""){       //if array value is null THEN SKIP
                continue;
              }
             $o->item_remark=mysql_real_escape_string($item_cpf_remark[$key]); //assign ITEM DETAI from array
             $o->item_amount=mysql_real_escape_string($item_cpf_amount[$key]); //assign ITEM DETAI from array
             $o->isCPF = 1;
             $o->isAdd = 1;
             $o->isDeduc = 0;
             $o->save_salary_item("new"); // save ITEM WITH CPF
            }
      }

      //item with Non-CPF
      if(!empty($item_NON_cpf_remark)){       //ISSET ITEM WITH CPF ELSE SKIP
           foreach ($item_NON_cpf_remark as $key=>$value ) {
              if(empty($value) || $value = NULL || $value = ""){       //if array value is null THEN SKIP
                continue;
              }
             $o->item_remark=mysql_real_escape_string($item_NON_cpf_remark[$key]); //assign ITEM DETAI from array
             $o->item_amount=mysql_real_escape_string($item_NON_cpf_amount[$key]); //assign ITEM DETAI from array
             $o->isCPF = 0;
             $o->isAdd = 1;
             $o->isDeduc = 0;
            $o->save_salary_item("new"); // save ITEM WITH CPF
            }
      }

      //item with Deduction
      if(!empty($deduc_remark)){       //ISSET ITEM WITH CPF ELSE SKIP
           foreach ($deduc_remark as $key=>$value ) {
              if(empty($value) || $value = NULL || $value = ""){       //if array value is null THEN SKIP
                continue;
              }
             $o->item_remark=mysql_real_escape_string($deduc_remark[$key]); //assign ITEM DETAI from array
             $o->item_amount=mysql_real_escape_string($deduc_amount[$key]); //assign ITEM DETAI from array
             $o->isCPF = 0;
             $o->isAdd = 0;
             $o->isDeduc = 1;
            $o->save_salary_item("new"); // save ITEM WITH CPF
            }
      }
          header("Location: make_payment.php?employee_id=$o->employee_id#payment_history",500);
          exit; 
    }else{
         header("Location: make_payment.php?employee_id=$o->employee_id",500);
          exit; 
    }
    break;
  case 'edit':
  $o->getinformation();
    $o->edit_fetch();
    $o->inputform("edit");
    break;

  case 'update':
      if ($o->update_payment() === true){
         if($o->delete_additional () === true){

                       //item with CPF
                      if(!empty($item_cpf_remark)){
                           foreach ($item_cpf_remark as $key=>$value ) {
                              if(empty($value) || $value = NULL || $value = ""){       //if array value is null THEN SKIP
                                continue;
                              }
                             $o->item_remark=mysql_real_escape_string($item_cpf_remark[$key]); //assign ITEM DETAI from array
                             $o->item_amount=mysql_real_escape_string($item_cpf_amount[$key]); //assign ITEM DETAI from array
                             $o->isCPF = 1;
                             $o->isAdd = 1;
                             $o->isDeduc = 0;
                             $o->save_salary_item("update"); // save ITEM WITH CPF
                            }
                      }
                      //item with Non-CPF
                      if(!empty($item_NON_cpf_remark)){       //ISSET ITEM WITH CPF ELSE SKIP
                           foreach ($item_NON_cpf_remark as $key=>$value ) {
                              if(empty($value) || $value = NULL || $value = ""){       //if array value is null THEN SKIP
                                continue;
                              }
                             $o->item_remark=mysql_real_escape_string($item_NON_cpf_remark[$key]); //assign ITEM DETAI from array
                             $o->item_amount=mysql_real_escape_string($item_NON_cpf_amount[$key]); //assign ITEM DETAI from array
                             $o->isCPF = 0;
                             $o->isAdd = 1;
                             $o->isDeduc = 0;
                              $o->save_salary_item("update"); // save ITEM WITH CPF
                            }
                      }
                      //item with Deduction
                      if(!empty($deduc_remark)){       //ISSET ITEM WITH CPF ELSE SKIP
                           foreach ($deduc_remark as $key=>$value ) {
                              if(empty($value) || $value = NULL || $value = ""){       //if array value is null THEN SKIP
                                continue;
                              }
                              $o->isCPF = 0;
                             $o->isAdd = 0;
                             $o->isDeduc = 1;
                             $o->item_remark=mysql_real_escape_string($deduc_remark[$key]); //assign ITEM DETAI from array
                             $o->item_amount=mysql_real_escape_string($deduc_amount[$key]); //assign ITEM DETAI from array
                             $o->save_salary_item("update"); // save ITEM WITH CPF
                            }
                      }
         }


          header("Location: make_payment.php?employee_id=$o->employee_id#payment_history",500);
          exit; 
      }else{
          header("Location: make_payment.php?employee_id=$o->employee_id#payment_history",500);
          exit; 
      }
    break;

  case 'delete':
    $o->delete_payment();die;
    break;
	default:
		$o->getinformation();
		 $o->inputform("new");
		break;
}

 require_once 'components/footer.php';