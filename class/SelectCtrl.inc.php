<?php
class SelectCtrl{
    
    Public function getSelectCountries($id,$showNull){
        global $db;
                
                $selectctl = "";
                $sql="SELECT * FROM countries where country_id>0 order by country_id";
             
                if ($showNull=='Y')
                $selectctl=$selectctl.'<OPTION value="" SELECTED=SELECTED>...</OPTION>';
                $query=mysqli_query($db,$sql);
                while($row=mysqli_fetch_assoc($query)){
                $country_id=$row['country_id'];
                $countryName=$row['countryName'];
            
                if($id==$country_id)
                  $SELECTED='SELECTED=SELECTED';
                else
                $SELECTED='';
                $selectctl=$selectctl."<OPTION value='$country_id' $SELECTED>$countryName</OPTION>";
                }
                return $selectctl;
    }	


    Public function getSelectCurrency($id,$showNull){
        global $db;
                
                $selectctl = "";
                $sql="SELECT * FROM currency where currency_id>0 order by currency_id";
             
                if ($showNull=='Y')
                $selectctl=$selectctl.'<OPTION value="" SELECTED=SELECTED>...</OPTION>';
                $query=mysqli_query($db,$sql);
                while($row=mysqli_fetch_assoc($query)){
                $currency_id=$row['currency_id'];
                $currency_name=$row['currency_name'];
            
                if($id==$currency_id)
                  $SELECTED='SELECTED=SELECTED';
                else
                $SELECTED='';
                $selectctl=$selectctl."<OPTION value='$currency_id' $SELECTED>$currency_name</OPTION>";
                }
                return $selectctl;
    }   

    Public function getSelectGender($id,$showNull){
        global $db;
                
                $selectctl = "";
                $sql="SELECT * FROM gender where gender_id>0 order by gender_id";
             
                if ($showNull=='Y')
                $selectctl=$selectctl.'<OPTION value="" SELECTED=SELECTED>...</OPTION>';
                $query=mysqli_query($db,$sql);
                while($row=mysqli_fetch_assoc($query)){
                $gender_id=$row['gender_id'];
                $gender_name=$row['gender_name'];
            
                if($id==$gender_id)
                  $SELECTED='SELECTED=SELECTED';
                else
                $SELECTED='';
                $selectctl=$selectctl."<OPTION value='$gender_id' $SELECTED>$gender_name</OPTION>";
                }
                return $selectctl;
    }  

    Public function getSelectMStatus($id,$showNull){
        global $db;
                
                $selectctl = "";
                $sql="SELECT * FROM marital_status where marital_id>0 order by marital_id";
             
                if ($showNull=='Y')
                $selectctl=$selectctl.'<OPTION value="" SELECTED=SELECTED>...</OPTION>';
                $query=mysqli_query($db,$sql);
                while($row=mysqli_fetch_assoc($query)){
                $marital_id=$row['marital_id'];
                $marital_name=$row['marital_name'];
            
                if($id==$marital_id)
                  $SELECTED='SELECTED=SELECTED';
                else
                $SELECTED='';
                $selectctl=$selectctl."<OPTION value='$marital_id' $SELECTED>$marital_name</OPTION>";
                }
                return $selectctl;
    }    

    Public function getSelectProbation($id,$showNull){
        global $db;
                
                $selectctl = "";
                $sql="SELECT * FROM probation where probation_id>0 order by probation_id";
             
                if ($showNull=='Y')
                $selectctl=$selectctl.'<OPTION value="" SELECTED=SELECTED>...</OPTION>';
                $query=mysqli_query($db,$sql);
                while($row=mysqli_fetch_assoc($query)){
                $probation_id=$row['probation_id'];
                $probation_name=$row['probation_name'];
            
                if($id==$probation_id)
                  $SELECTED='SELECTED=SELECTED';
                else
                $SELECTED='';
                $selectctl=$selectctl."<OPTION value='$probation_id' $SELECTED>$probation_name</OPTION>";
                }
                return $selectctl;
    }

        Public function getSelectDepartment($id,$showNull){
        global $db;
                
                $selectctl = "";
                $sql="SELECT * FROM hrms_department where department_id>0 order by department_id";
             
                if ($showNull=='Y')
                $selectctl=$selectctl.'<OPTION value="" SELECTED=SELECTED>...</OPTION>';
                $query=mysqli_query($db,$sql);
                while($row=mysqli_fetch_assoc($query)){
                $department_id = $row['department_id'];
                $department_name = $row['department_name'];
                $department_code = $row['department_code'];
            
                if($id==$department_id)
                  $SELECTED='SELECTED=SELECTED';
                else
                $SELECTED='';
                $selectctl=$selectctl."<OPTION value='$department_id' $SELECTED>$department_name - $department_code</OPTION>";
                }
                return $selectctl;
    }

        Public function getSelectDesignation($id,$showNull){
        global $db;
                
                $selectctl = "";
                $sql="SELECT * FROM hrms_designations where designations_id>0 order by designations_id";
             
                if ($showNull=='Y')
                $selectctl=$selectctl.'<OPTION value="" SELECTED=SELECTED>...</OPTION>';
                $query=mysqli_query($db,$sql);
                while($row=mysqli_fetch_assoc($query)){
                $designations_id=$row['designations_id'];
                $designations=$row['designations'];
            
                if($id==$designations_id)
                  $SELECTED='SELECTED=SELECTED';
                else
                $SELECTED='';
                $selectctl=$selectctl."<OPTION value='$designations_id' $SELECTED>$designations</OPTION>";
                }
                return $selectctl;
    }

        Public function getSelectWorkPassCat($id,$showNull){
        global $db;
                
                $selectctl = "";
                $sql="SELECT * FROM hrms_work_pass_category where work_pass_category_id>0 order by work_pass_category_id";
             
                if ($showNull=='Y')
                $selectctl=$selectctl.'<OPTION value="" SELECTED=SELECTED>...</OPTION>';
                $query=mysqli_query($db,$sql);
                while($row=mysqli_fetch_assoc($query)){
                $work_pass_category_id=$row['work_pass_category_id'];
                $category=$row['category'];
            
                if($id==$work_pass_category_id)
                  $SELECTED='SELECTED=SELECTED';
                else
                $SELECTED='';
                $selectctl=$selectctl."<OPTION value='$work_pass_category_id' $SELECTED>$category</OPTION>";
                }
                return $selectctl;
    }
        Public function getSelectLeaveCat($id,$showNull){
        global $db;
                
                $selectctl = "";
                $sql="SELECT * FROM hrms_leave_category where leave_category_id>0 order by leave_category_id";
             
                if ($showNull=='Y')
                $selectctl=$selectctl.'<OPTION value="" SELECTED=SELECTED>...</OPTION>';
                $query=mysqli_query($db,$sql);
                while($row=mysqli_fetch_assoc($query)){
                $leave_category_id=$row['leave_category_id'];
                $category=$row['category'];
            
                if($id==$leave_category_id)
                  $SELECTED='SELECTED=SELECTED';
                else
                $SELECTED='';
                $selectctl=$selectctl."<OPTION value='$leave_category_id' $SELECTED>$category</OPTION>";
                }
                return $selectctl;
    }
    Public function getSelectPaymentType($id,$showNull){
        global $db;
                
                $selectctl = "";
                $sql="SELECT * FROM hrms_payment_type where payment_type_id>0 order by payment_type_id";
             
                if ($showNull=='Y')
                $selectctl=$selectctl.'<OPTION value="" SELECTED=SELECTED>...</OPTION>';
                $query=mysqli_query($db,$sql);
                while($row=mysqli_fetch_assoc($query)){
                $payment_type_id=$row['payment_type_id'];
                $payment_type=$row['payment_type'];
            
                if($id==$payment_type_id)
                  $SELECTED='SELECTED=SELECTED';
                else
                $SELECTED='';
                $selectctl=$selectctl."<OPTION value='$payment_type_id' $SELECTED>$payment_type</OPTION>";
                }
                return $selectctl;
    }

        Public function getSelectEmployeeLeave($id,$showNull){
        global $db,$user_id;
                
                $selectctl = "";
                $sql="SELECT hrms_leave_category.leave_category_id, hrms_leave_category.category
                FROM hrms_employee_leave
                INNER JOIN hrms_leave_category ON hrms_leave_category.leave_category_id = hrms_employee_leave.leave_category_id
                WHERE employee_id = $user_id
                ORDER BY leave_category_id";

                if ($showNull=='Y')
                $selectctl=$selectctl.'<OPTION value="" SELECTED=SELECTED>...</OPTION>';
                $query=mysqli_query($db,$sql);
                while($row=mysqli_fetch_assoc($query)){
                $leave_category_id=$row['leave_category_id'];
                $category=$row['category'];
            
                if($id==$leave_category_id)
                  $SELECTED='SELECTED=SELECTED';
                else
                $SELECTED='';
                $selectctl=$selectctl."<OPTION value='$leave_category_id' $SELECTED>$category</OPTION>";
                }
                return $selectctl;
    }
            Public function getSelectApplicationStatus($id,$showNull){
        global $db,$user_id;
                
                $selectctl = "";
                $sql="SELECT * FROM application_status where application_status_id  >0 order by application_status_id";

                if ($showNull=='Y')
                $selectctl=$selectctl.'<OPTION value="" SELECTED=SELECTED>...</OPTION>';
                $query=mysqli_query($db,$sql);
                while($row=mysqli_fetch_assoc($query)){
                $application_status_id=$row['application_status_id'];
                $application_status=$row['application_status'];
            
                if($id==$application_status_id)
                  $SELECTED='SELECTED=SELECTED';
                else
                $SELECTED='';
                $selectctl=$selectctl."<OPTION value='$application_status_id' $SELECTED>$application_status</OPTION>";
                }
                return $selectctl;
    }
}
