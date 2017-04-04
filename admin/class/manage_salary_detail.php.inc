<?php
class manage_salary_detail{

 public $msg;
 public $basic_salary;
 public $first_name;
 public $last_name;
 public $employment_id;
 public $department_name;
 public $designations;
 public $joining_date;
 public $photo;

	public function inputform(){
		global $up_path;
    if (!empty($_SESSION['msg'])) {
   $this->msg = $_SESSION['msg'];
    }

echo<<<EOF

<div class="right_col" role="main">
  <div class="">
    <div class="clearfix"></div>
      <div class="row">
        <div class="col-md-12 col-sm-12 col-xs-12">
              <div id="msg">
              $this->msg                         
              </div>


            <div class="x_title">
                <h2>Employee Information</h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
					<div class="col-lg-2 col-sm-2">
					<img src="$up_path/$this->photo" alt="" style="width: 160px;height: 160px;border-radius: 5px;"/>
					</div>
					<div style="margin-left: 200px;">                                        
                                    <h3>$this->first_name $this->last_name</h3>
                                    <hr>
                                    <table style="border: none">
                                        <tbody><tr>
                                            <td><strong>Employee ID</strong></td>
                                            <td>&nbsp;&nbsp;&nbsp;</td>
                                            <td>$this->employment_id</td>
                                        </tr>
                                        <tr>
                                            <td><strong>Department</strong></td>
                                            <td>&nbsp;&nbsp;&nbsp;</td>
                                            <td>$this->department_name</td>
                                        </tr>
                                        <tr>
                                            <td><strong>Designation</strong></td>
                                            <td>&nbsp;&nbsp;&nbsp;</td>
                                            <td>$this->designations</td>
                                        </tr>                                                                                
                                        <tr>
                                            <td><strong>Joining Date</strong></td>
                                            <td>&nbsp;&nbsp;&nbsp;</td>
                                            <td>$this->joining_date</td>
                                        </tr>                                            
                                    </tbody></table>                                                                           
                                </div>

      			</div></div>

<!-- ***************** Salary Details  Start *********************-->
<div class="col-md-6 col-sm-6 col-xs-6">
            <div class="x_title">
                <h2>Salary Details</h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                    <form id="inputform" class="form-horizontal form-label-left" action="set_holidays.php" method="post">

                                  <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Employment Type<span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                   
                                            </div>
                                    </div>

                                    <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Basic Salary
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                              <input type="text" class="form-control col-md-7 col-xs-12" id="basic_salary" name="basic_salary" value="$this->basic_salary"> 
                                            </div>
                                    </div>

                                   
      	</div>
<!-- ***************** Salary Details  Ends *********************-->

 <!-- ******************-- Allowance Panel Start **************************-->
            <div class="x_title" style="margin-top:115px;">
                <h2>Allowances</h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                 
							<div class="">
                                <label class="control-label" >House Rent Allowance </label>
                                <input type="text" name="house_rent_allowance" class="form-control">
                            </div>
                            <div class="">
                                <label class="control-label" >Medical Allowance </label>
                                <input type="text" name="medical_allowance" class="form-control">
                            </div>
                            <div class="">
                                <label class="control-label" >Special Allowance </label>
                                <input type="text" name="special_allowance" class="form-control">
                            </div>
                            <div class="">
                                <label class="control-label" >Fuel Allowance </label>
                                <input type="text" name="fuel_allowance" class="form-control">
                            </div>
                            <div class="">
                                <label class="control-label" >Phone Bill Allowance </label>
                                <input type="text" name="phone_bill_allowance" class="form-control">
                            </div>
                            <div class="">
                                <label class="control-label" >Other Allowance </label>
                                <input type="text" name="other_allowance" class="form-control">
                            </div>

                                   
      	</div></div>
   <!-- ********************Allowance End ******************-->

   <!-- ******************-- Deductions Panel Start **************************-->

        <div class="col-md-6 col-sm-6 col-xs-6">

            <div class="x_title">
                <h2>Deductions</h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                 
							<div class="">
                            <label class="control-label" >Central Provident Fund </label>
                                <input type="text" name="central_provident_fund" class="form-control">
                            </div>
                            <div class="">
                                <label class="control-label" >SDL Payable</label>
                                <input type="text" name="SDL_Payable"  class="form-control">
                            </div>                            
                            <div class="">
                                <label class="control-label" >Other Deduction </label>
                                <input type="text" name="other_deduction" class="form-control">
                            </div>

                                   
      	</div>
   <!-- ********************Deductions End ******************-->

    <!-- ************** Total Salary Details Start  **************-->

		            <div class="x_title" style="margin-top:205px;">
		                <h2>Total Salary Details</h2>
		                 <div class="clearfix"></div>
		            </div>

               <div class="x_content">

                             <div class="">
                                <label class="control-label" >Gross Salary </label>
                                <input type="text" name="provident_fund" disabled class="form-control">
                            </div>
                            <div class="">
                                <label class="control-label" >Total Deduction </label>
                                <input type="text" name="tax_deduction" disabled class="form-control">
                            </div>                                                        
                            <div class="">
                                <label class="control-label" >Net Salary </label>
                                <input type="text" name="tax_deduction" disabled class="form-control">
                            </div>         
      	</div></div>
 <!-- ************** Total Salary Details End  **************-->
              <div class="col-sm-6 margin pull-right" style="margin-top:25px;">
                <button id="salery_btn" type="submit" class="btn btn-primary btn-block">Save</button>
            </div>  
 </form></div>


EOF;
$this->msg = null;
$_SESSION['msg'] = null;
	}
	public function fetch($employee_id){
		global $db,$employee_logo;

		$sql = "SELECT EMP.employee_id, employment_id, first_name, last_name, DES.designations, joining_date, DEP.department_name,photo
		FROM hrms_employee EMP
		INNER JOIN  hrms_designations DES ON DES.designations_id = EMP.designation_id
		INNER JOIN  hrms_department DEP ON DEP.department_id = DES.department_id
		LEFT JOIN hrms_employee_payroll PAY ON PAY.employee_id = EMP.employee_id
		WHERE EMP.employee_id = $employee_id";

		$query = mysqli_query($db,$sql);

			if (mysqli_num_rows($query) > 0){
				$row=mysqli_fetch_assoc($query);
				$this->first_name = $row['first_name'];
				$this->last_name = $row['last_name'];
				$this->employment_id = $row['employment_id'];
				$this->department_name = $row['department_name'];
				$this->designations = $row['designations'];
				$this->joining_date = $row['joining_date'];
				$this->photo = $row['photo'];

				if ($this->photo ==""){
					 $this->photo = $employee_logo;
				}
         return true;
			}else{


      $_SESSION['msg']="<div class='alert alert-info'>
           No Record Found!
          </div>";

      return false;
    }
 


	}
	
}