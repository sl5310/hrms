<?php

class add_employee{
	
    //employee info

	public $employee_id;
	public $employment_id;
	public $first_name;
	public $last_name;
	public $date_of_birth;
	public $gender;
    public $marital_status;
    public $father_name;
    public $nationality;
    public $identity_no;
    public $work_pass_category_id;

    public $photo;
    public $present_address;
    public $city;
    public $country_id;
    public $mobile;
    public $phone;
    public $email;
    public $emergency_contact;
    public $designation_id;
    public $joining_date;
    public $probation;
    public $last_date;
    public $confirmation_date;
    public $department;
	public $msg;
	public $designation;
	public $isactive=1;
	public $bank_name;
	public $branch_name;
	public $account_name;
	public $account_number;
	public $doc_identity;
	public $del_identity;

	public $doc_appointment;
	public $del_appointment;

	public $doc_confirmation;
	public $del_confirmation;

	public $doc_resignation;
	public $del_resignation;

	public $doc_other;
	public $del_other;
	public $employee_user;
	public $employee_pass;
	public $employee_confirmpass;
	public $employee_acisactive;

	public $change_pass;

    //EMPLOYEE SALARY
    public $basic_salary;
    public $sdl_payable;
    public $employee_cpf_percent;
    public $employer_cpf_percent;
    public $employee_cpf;
    public $employer_cpf;
    public $total_cpf_contribution;
    public $gross_salary;
    public $total_deduction;
    public $net_salary;

    //EMPLOYEE LEAVE
    public $leave_category;
    public $leave_days;

	public function inputform($type){

if (!empty($_SESSION['msg'])) {
   $this->msg = $_SESSION['msg'];
}


echo<<<EOF
<div class="right_col" role="main">
    <div class="">
      <div class="row">
         <div class="col-md-12 col-sm-12 col-xs-12">
           <h4><a href="add_employee.php"><i class="fa fa-plus"></i> New Employee</a></h4>
              <div id="msg">
              $this->msg                         
              </div>

                <div class="x_content">
                                        <ul class="nav nav-tabs bar_tabs right">
                                            <li><a href="#manage_leave" data-toggle="tab" ><i class="fa fa-suitcase"></i> Leave</a>
                                            </li>
                                            <li><a href="#manage_salary" data-toggle="tab" ><i class="fa fa-dollar"></i> Salary</a>
                                            </li>
                                            <li class="active"><a href="#employee_profile" data-toggle="tab" ><i class="fa fa-user"></i> Profile</a>
                                            </li>
                                        </ul>

                    <div class="tab-content">

                                        <div class="tab-pane active" id="employee_profile" >
EOF;
$this->employee_info($type);
echo<<<EOF
                                            </div>

                                            <div class="tab-pane" id="manage_salary">
EOF;
if($type=="new"){
    echo "<p>Please Complete Employee Information.</p>";
}else{
    $this->manage_salary_detail();
}
echo<<<EOF
                                            </div>

                                            <div class="tab-pane" id="manage_leave">
EOF;
if($type=="new"){
    echo "<p>Please Complete Employee Information.</p>";
}else{
    $this->manage_leave_detail();
}
echo<<<EOF
                                            </div>
                 </div>
          </div>
    </div>

     <!-- daterangepicker -->
    <script type="text/javascript" src="../asset/js/datepicker/daterangepicker.js"></script>

    <!-- icheck -->
        <script src="../asset/js/icheck/icheck.min.js"></script>
    <script>
        $(document).ready(function () {

            var hash = window.location.hash;
              hash && $('ul.nav a[href="' + hash + '"]').tab('show');

              $('.nav-tabs a').click(function (e) {
                $(this).tab('show');
                window.location.hash = this.hash;
                if(window.location.hash == "#manage_leave"){
                 location.reload();
                }
              });

$('#leave_usage').DataTable( {
    responsive: true
});
$('#all_application').DataTable( {
    responsive: true
});  
           $('#d_o_b').datepicker({
             format: "yyyy-mm-dd", // Notice the Extra space at the beginning
             autoclose: true,
             orientation: "top auto"
            });

            $('#joining_date').datepicker({
                format: "yyyy-mm-dd", // Notice the Extra space at the beginning
             autoclose: true,
             orientation: "top auto"
            });

            $('#confirmation_date').datepicker({
            format: "yyyy-mm-dd", // Notice the Extra space at the beginning
             autoclose: true,
             orientation: "top auto"
            });

            $('#last_day').datepicker({
            format: "yyyy-mm-dd", // Notice the Extra space at the beginning
             autoclose: true,
             orientation: "top auto"
            });

             $('input').iCheck({
                checkboxClass: 'icheckbox_flat-blue'
              });

        });


        function get_designation(value){

        $("#designation").empty();
        $("#employee_id").empty();
        
        data = "action=get_designation&department_id="+value;
        $.ajax({url:"add_employee.php",type:"POST",data:data,success:function(xml){
        $(xml).find('option').each(function() { 
            var value = $(this).attr('value');
              var label = $(this).text();
            $("#designation").append("<option value='"+ value +"'>"+label+"</option>");
        });

        }
        });
}

setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 2000); // <-- time in milliseconds

function readURL(input) {

            if (input.files && input.files[0]) {
                var reader = new FileReader();
                reader.onload = function (e) {
                    $('#preview').attr('src', e.target.result);
                }

                reader.readAsDataURL(input.files[0]);
            }
        }


$('#inputform').parsley(); //validate form

         function changePass(employee_id){
            
            var passwordval = document.getElementById('change_pass').value;
            var passwordField = $('#change_pass').parsley();


            var confirmpasswordval = document.getElementById('change_confirmpass').value;
            var ConfirmPasswordField = $('#change_confirmpass').parsley();


            if (passwordval.length < 1 ){
                window.ParsleyUI.removeError(passwordField, "EnterPassword");
            window.ParsleyUI.addError(passwordField, "EnterPassword", 'Please Enter Your New Password.');
                return false;
            }else{
            window.ParsleyUI.removeError(passwordField, "EnterPassword");
            }

            if(passwordval.length > 1 && confirmpasswordval.length < 1){
                    window.ParsleyUI.removeError(ConfirmPasswordField, "ConfirmPasswordField");
                    window.ParsleyUI.addError(ConfirmPasswordField, "ConfirmPasswordField", 'Please Confirm Your New Password.');
                    return false;
            }else{
                    window.ParsleyUI.removeError(ConfirmPasswordField, "ConfirmPasswordField");
            }

            if (passwordval != confirmpasswordval){
                window.ParsleyUI.removeError(ConfirmPasswordField, "ComparePassword");
                window.ParsleyUI.addError(ConfirmPasswordField, "ComparePassword", 'Password does not match the confirm password.');
                    return false;
            }else{
                window.ParsleyUI.removeError(ConfirmPasswordField, "ComparePassword");
            }



            var data="action=updatePass&employee_id="+employee_id+"&change_pass="+passwordval;
            $.ajax({url: "add_employee.php", type: "POST", data: data, cache: false, success: function (xml) {
            location.reload();
            }
            });
        }


    $(document).on("change", function() {

        var basic_salary = $("#basic_salary").val();
        var employee_cpf_percent = $("#employee_cpf_percent").val();
        var employer_cpf_percent = $("#employer_cpf_percent").val();
        var employee_total = basic_salary * employee_cpf_percent / 100;
        var employer_total = basic_salary * employer_cpf_percent / 100;

        $("#employee_cpf").val("");
        $("#employer_cpf").val("");
        $("#total_cpf_contribution").val("");

        if (employee_cpf_percent > 0){
        $("#employee_cpf").val(employee_total);
        }

        if (employer_cpf_percent > 0){
        $("#employer_cpf").val(employer_total);
        }
        
        if (employer_cpf_percent > 0 || employee_cpf_percent > 0){
        var total_cpf_contribution = employee_total + employer_total;
        $("#total_cpf_contribution").val(total_cpf_contribution);
        }

        var sum = 0;
        var deduc = 0;
        $(".salary").each(function() {
            sum += +$(this).val();
        });

        $(".deduction").each(function() {
            deduc += +$(this).val();
        });

        $("#total_deduction").val(deduc);
        var net_salary = 0;
        net_salary = (sum - deduc).toFixed(2);
        $("#net_salary").val(net_salary);
    


    });


    function change_days(value){
        $('#change_days').modal('show');
        // sets onclick using jQuery
        $("#anchor").attr('onclick', 'update_days('+value+')');
        var change_days_of_leave_field = $('#change_days_of_leave').parsley();
        window.ParsleyUI.removeError(change_days_of_leave_field, "EnterDays");
    }

    function update_days(value){

            var change_days_of_leave_value = $('#change_days_of_leave').val();
            var change_days_of_leave_field = $('#change_days_of_leave').parsley();


            if (change_days_of_leave_value.length < 1 ){
            window.ParsleyUI.removeError(change_days_of_leave_field, "EnterDays");
            window.ParsleyUI.addError(change_days_of_leave_field, "EnterDays", 'Please Enter Days of Leave.');
                return false;
            }else{
            window.ParsleyUI.removeError(change_days_of_leave_field, "EnterDays");
            }

            var data="action=updateDays&employee_leave_id="+value+"&change_days="+change_days_of_leave_value;
            $.ajax({url: "add_employee.php", type: "POST", data: data, cache: false, success: function (xml) {
            location.reload();
            }
            });
    }
</script>
EOF;
$this->msg = null;
$_SESSION['msg'] = null;

}

public function employee_info($type){
            global $selectcrtl,$up_path;

        $nationality = $selectcrtl->getSelectCountries($this->nationality,'Y');
        $gender = $selectcrtl->getSelectGender($this->gender,'Y');
        $marital_status = $selectcrtl->getSelectMStatus($this->marital_status,'Y');
        $countries = $selectcrtl->getSelectCountries($this->country_id,'Y');
        $probation = $selectcrtl->getSelectProbation($this->probation,'Y');
        $department = $selectcrtl->getSelectDepartment($this->department,'Y');
        $designation = $selectcrtl->getSelectDesignation($this->designation_id,'Y');
        
       $work_pass_category = $selectcrtl->getSelectWorkPassCat($this->work_pass_category_id,'Y');

        // $secret_key = "fs1dfs14d9a4sd85a8fewads";
        // $iv = mcrypt_create_iv(mcrypt_get_iv_size(MCRYPT_RIJNDAEL_256, MCRYPT_MODE_ECB), MCRYPT_RAND);
        // $employee_id = mcrypt_encrypt(MCRYPT_RIJNDAEL_256, $secret_key, $employee, MCRYPT_MODE_CBC, $iv);


        if($type=="new"){
            $checked="Checked";
            $action = "save";
            $hidden = " ";
            $title = "Add Employee";
            $password_col = " <div class=''>
                                    <label class='control-label'>Password</label>
                                    <input type='password' name='employee_pass' id='employee_pass' class='form-control' required='required'>
                                    </div>

                                    <div class=''>
                                    <label class='control-label'>Confirm Password</label>
                                    <input type='password' name='employee_confirmpass' id='employee_confirmpass' data-parsley-equalto='#employee_pass' required='required'
                                     class='form-control'>
                                    </div>";
        }else{
            $action = "update";
            $title = "Employee Information";
            $hidden = "<input type='hidden' value='$this->employee_id' name='employee_id'>";
            $password_col = " <button type='button' class='btn btn-default' data-toggle='modal' data-target='.bs-example-modal-sm'>Change Password</button>
                                <div class='modal fade bs-example-modal-sm' tabindex='-1' role='dialog' aria-hidden='true'>
                                    <div class='modal-dialog modal-sm'>
                                        <div class='modal-content'>

                                            <div class='modal-header'>
                                                <button type='button' class='close' data-dismiss='modal' aria-label='Close'><span aria-hidden='true'>×</span>
                                                </button>
                                                <h4 class='modal-title' id='myModalLabel2'>Change Password</h4>
                                            </div>
                                            <div class='modal-body'>
                                                <div class=''>
                                                <label class='control-label'>New Password</label>
                                                <input type='password' name='change_pass' id='change_pass' class='form-control'>
                                                </div>

                                                <div class=''>
                                                <label class='control-label'>Confirm Password</label>
                                                <input type='password' name='change_confirmpass' id='change_confirmpass' class='form-control'>
                                                </div>
                                            </div>
                                            <div class='modal-footer'>
                                                <button type='button' class='btn btn-default' data-dismiss='modal'>Close</button>
                                                <button type='button' class='btn btn-primary' onclick='changePass($this->employee_id)'>Save</button>
                                            </div>

                                        </div>
                                    </div>
                                </div>
                                <!-- /modals -->";
        }

        if($this->isactive == 0){
            $checked="";
        }else{
         $checked="Checked";
        }
echo<<<EOF
    <div class="col-md-12 col-sm-12 col-xs-12">
               <form id="inputform" action='add_employee.php' method='post' enctype="multipart/form-data"  data-parsley-validate>
                       <!-- ************************ Personal Information Panel Start ************************-->

                    <div class="col-md-6 col-sm-6 col-xs-12">
                                <div class="x_title">
                                    <h2>Personal Details</h2>
                                     <div class="clearfix"></div>
                                </div>

                        <div class="x_content">

                                    <div class="">
                                    <label class="control-label">First Name <span class="required"> *</span></label>
                                    <input type="text" name="first_name" value="$this->first_name" class="form-control" required="required">
                                    </div>

                                    <div class="">
                                    <label class="control-label">Last Name <span class="required"> *</span></label>
                                    <input type="text" name="last_name"  value="$this->last_name" class="form-control" required="required">
                                    </div>

                                    <div class="">
                                    <label class="control-label">Date of Birth <span class="required"> *</span></label>
                                    <input type="text" class="form-control" name="date_of_birth" value="$this->date_of_birth" id="d_o_b" aria-describedby="inputSuccess2Status2" 
                                    placeholder="yyyy-mm-dd" required="required" data-parsley-trigger="change" pattern="/^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$/">
                                    <span id="inputSuccess2Status2" class="sr-only">(success)</span>  
                                    </div>

                                    <div class="">
                                    <label class="control-label">Gender <span class="required"> *</span></label>
                                    <select name='gender' class="form-control" required="required">
                                    $gender
                                    </select>
                                    </div>

                                    <div class="">
                                    <label class="control-label">Marital Status <span class="required"> *</span></label>
                                    <select name='marital_status' class="form-control" required="required">
                                    $marital_status
                                    </select>
                                    </div>

                                    <div class="">
                                    <label class="control-label">Father's Name</label>
                                    <input type="text" name="father_name" value="$this->father_name" class="form-control">
                                    </div>

                                    <div class="">
                                    <label class="control-label">Nationality <span class="required"> *</span></label>
                                    <select name='nationality' class="form-control" required="required">
                                    $nationality
                                    </select>
                                    </div>

                                    <div class="">
                                    <label class="control-label">NRIC / Work Pass NO <span class="required"> *</span></label>
                                    <input type="text" name="identity_no" value="$this->identity_no" class="form-control" required="required">
                                    </div>

                                    <div class="">
                                    <label class="control-label">Work Pass Category</label>
                                    <select name='work_pass_category_id' class="form-control">
                                    $work_pass_category
                                    </select>
                                    </div>

                                    <div class="">
                                    <label class="control-label">Photo</label>
                                    <div class="fileupload-preview thumbnail" style="width: 200px; height: 150px;">
                                            <img id="preview" src="$up_path/photo/$this->photo" alt="Employee Photo" /></div>
                                            <span class="btn btn-default btn-file">
  
                                            <input id="photo" name="photo" type="file" class="file"  accept="image/*" onchange="readURL(this);">
                              
                                            </span>
                                    </div>

                        </div>
                   </div>
                      
                        <!-- ************************ Personal Information Panel End ************************-->


                       <!-- ************************ Contact Details Start ******************************* -->
                         <div class="col-md-6 col-sm-6 col-xs-12">
                                <div class="x_title">
                                    <h2>Contact Details</h2>
                                     <div class="clearfix"></div>
                                </div>

                                   <div class="x_content"> 

                                    <div class="">
                                    <label class="control-label">Present Address<span class="required"> *</span></label>
                                    <input type="text" name="present_address" value="$this->present_address" class="form-control" required="required">
                                    </div>

                                    <div class="">
                                    <label class="control-label">City <span class="required"> *</span></label>
                                    <input type="text" name="city" value="$this->city" class="form-control" required="required">
                                    </div>

                                    <div class="">
                                    <label class="control-label">Country <span class="required"> *</span></label>
                                    <select name='country_id' class="form-control" required="required">
                                    $countries
                                    </select>
                                    </div>

                                    <div class="">
                                    <label class="control-label">Mobile <span class="required"> *</span></label>
                                    <input type="number"  name="mobile" value="$this->mobile" class="form-control" required="required">
                                    </div>

                                    <div class="">
                                    <label class="control-label">Phone</label>
                                    <input type="number" name="phone" value="$this->phone" class="form-control">
                                    </div>

                                    <div class="">
                                    <label class="control-label">Email <span class="required"> *</span></label>
                                    <input type="email" name="email" value="$this->email" class="form-control" required="required">
                                    </div>

                                    <div class="">
                                    <label class="control-label">Emergency Contact <span class="required"> *</span></label>
                                    <input type="number" name="emergency_contact" value="$this->emergency_contact" class="form-control" required="required">
                                    </div>

                                </div>
                            </div>
                        <!-- ************************ Contact Details End ************************-->




                     <!-- ************************ Employee Documents Start ******************************* -->
                     <div class="col-md-6 col-sm-6 col-xs-12">
                                <div class="x_title">
                                    <h2>Employee Documents</h2>
                                     <div class="clearfix"></div>
                                </div>

                                   <div class="x_content">

                                <!-- NRIC / Work Pass Upload -->
                                        <div class="form-group">
                                            <label for="field-1" class="col-sm-3 control-label">NRIC / Work Pass</label>
                                           <label class="btn btn-success btn-upload" for="inputImage" title="Upload NRIC / Work Pass">
                                                <input name="doc_identity" type="file" class="file">
                                            </label>
                                             <p><a href="$up_path/document/$this->doc_identity" target="_blank">$this->doc_identity</a>
                                            $this->del_identity</p>
                                        </div>

                                <!-- Appointment Letter Upload -->
                                        <div class="form-group">
                                            <label for="field-1" class="col-sm-3 control-label">Appointment Letter</label>
                                            <label class="btn btn-success btn-upload" for="inputImage" title="Upload image file">
                                                <input id="inputImage" name="doc_appointment" type="file">
                                                <span class="docs-tooltip" data-toggle="tooltip" title="Upload Appointment Letter">
                                            </label>

                                         <p><a href="$up_path/document/$this->doc_appointment" target="_blank">$this->doc_appointment</a>
                                        $this->del_appointment</p>
                                        </div>

                                <!-- Confirmation Letter Upload -->
                                        <div class="form-group">
                                            <label for="field-1" class="col-sm-3 control-label">Confirmation Letter</label>
                                            <label class="btn btn-success btn-upload" for="inputImage" title="Upload image file">
                                                <input id="inputImage" name="doc_confirmation" type="file">
                                                <span class="docs-tooltip" data-toggle="tooltip" title="Upload Confirmation Letter">
                                            </label>

                                             <p><a href="$up_path/document/$this->doc_confirmation" target="_blank">$this->doc_confirmation</a>
                                        $this->del_confirmation</p>
                                        </div>

                                <!-- Resignation Letter Upload -->
                                        <div class="form-group">
                                            <label for="field-1" class="col-sm-3 control-label">Resignation Letter</label>
                                            <label class="btn btn-success btn-upload" for="inputImage" title="Upload image file">
                                                <input  id="inputImage" name="doc_resignation" type="file">
                                                <span class="docs-tooltip" data-toggle="tooltip" title="Upload Resignation Letter">
                                            </label>

                                            <p> <a href="$up_path/document/$this->doc_resignation" target="_blank">$this->doc_resignation</a>
                                        $this->del_resignation</p>
                                        </div>

                                <!-- Other Document Upload -->
                                        <div class="form-group">
                                            <label for="field-1" class="col-sm-3 control-label">Other Document</label>
                                            <label class="btn btn-success btn-upload" for="inputImage" title="Upload image file">
                                                <input id="inputImage" name="doc_other" type="file">
                                                <span class="docs-tooltip" data-toggle="tooltip" title="Upload Other Document">
                                            </label>

                                        <p> <a href="$up_path/document/$this->doc_other" target="_blank">$this->doc_other</a>
                                        $this->del_other</p>
                                        </div>
                                </div>
                        </div>
                    <!-- ************************  Employee Documents End ************************-->



                    <!-- ************************ Official Status Start ******************************* -->
                   <div class="col-md-6 col-sm-6 col-xs-12 pull-right">
                                <div class="x_title">
                                    <h2>Official Status</h2>
                                     <div class="clearfix"></div>
                                </div>

                                   <div class="x_content">                    


                                    <label class="control-label">Is active </label>
                                                    <label>
                                                        <input type="checkbox" name="isactive" class="flat" $checked>
                                                    </label>

                                    <div class="">
                                    <label class="control-label">Employee ID<span class="required"> *</span></label>
                                    <input type="text" name="employment_id" value="$this->employment_id" class="form-control" required="required">
                                    </div>

                                    <div class="">
                                    <label class="control-label">Department <span class="required"> *</span></label>
                                    <select onchange="get_designation(this.value)" name='department' class="form-control" required="required">
                                    $department
                                    </select>
                                    </div>

                                    <div class="">
                                    <label class="control-label">Designation <span class="required"> *</span></label>
                                    <select name='designation_id' id="designation" class="form-control" required="required">
                                    $designation
                                    </select>
                                    </div>

                                    <div class="">
                                    <label class="control-label">Joining Date <span class="required"> *</span></label>
                                    <input type="text" class="form-control" id="joining_date" name="joining_date" value="$this->joining_date"
                                    aria-describedby="inputSuccess2Status2" 
                                    placeholder="yyyy-mm-dd" required="required" data-parsley-trigger="change" pattern="/^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$/">
                                    <span id="inputSuccess2Status2" class="sr-only">(success)</span>  
                                    </div>


                                    <div class="">
                                    <label class="control-label">Probation Period <span class="required"> *</span></label>
                                    <select name='probation' class="form-control" required="required">
                                    $probation
                                    </select>
                                    </div>

                                    <div class="">
                                    <label class="control-label">Confirmation Date</label>
                                    <input type="text" class="form-control" id="confirmation_date" value="$this->confirmation_date" name="confirmation_date" placeholder="yyyy-mm-dd"
                                    aria-describedby="inputSuccess2Status2" pattern="/^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$/">
                                    <span id="inputSuccess2Status2" class="sr-only">(success)</span>  
                                    </div>

                                    <div class="">
                                    <label class="control-label">Last Day Date</label>
                                    <input type="text" class="form-control" id="last_day" name="last_date" value="$this->last_date" placeholder="yyyy-mm-dd" aria-describedby="inputSuccess2Status2" pattern="/^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$/">
                                    <span id="inputSuccess2Status2" class="sr-only">(success)</span>  
                                    </div>


                                </div>
                            </div>
                    <!-- ************************  Official Status End ************************-->
                              
                        <!-- ************************ Bank Information Start ******************************* -->
                     <div class="col-md-6 col-sm-6 col-xs-12" >
                                <div class="x_title">
                                    <h2>Bank Information</h2>
                                     <div class="clearfix"></div>
                                </div>

                                   <div class="x_content">

                                    <div class="">
                                    <label class="control-label">Bank Name</label>
                                    <input type="text" name="bank_name" value="$this->bank_name" class="form-control">
                                    </div>

                                    <div class="">
                                    <label class="control-label">Branch Name</label>
                                    <input type="text" name="branch_name" value="$this->branch_name" class="form-control">
                                    </div>

                                    <div class="">
                                    <label class="control-label">Account Name</label>
                                    <input type="text" name="account_name" value="$this->account_name" class="form-control">
                                    </div>

                                    <div class="">
                                    <label class="control-label">Account Number</label>
                                    <input type="text" name="account_number" value="$this->account_number" class="form-control">
                                    </div>

                                </div>
                  </div>
                    <!-- ************************  Bank Information End ************************-->
                    
                    <!-- ************************ Employee Login Start ******************************* -->
                        <div class="col-md-6 col-sm-6 col-xs-12">
                                <div class="x_title">
                                    <h2>Employee Login Information</h2>
                                     <div class="clearfix"></div>
                                </div>

                                   <div class="x_content">

                                    <div class="">
                                    <label class="control-label">User Name</label>
                                    <input type="text" name="employee_user" id="employee_user" value="$this->employee_user" class="form-control" pattern="^[A-Za-z0-9()\/-]+$"
                                   required="required">
                                    </div>

                                $password_col

                                </div>
                        </div>
                    <!-- ************************  Employee Login End ************************-->


                    <div class="col-md-6 col-sm-6 col-xs-12 pull-left" style="margin-top:20px">
                        <button id="btn_emp" type="submit" class="btn btn-primary btn-block">Save</button>
                        <input type='hidden' value='$action' name='action'>
                        $hidden
                    </div>    

                </form>
    </div>
EOF;
}




//save information to database
	public function save(){
 		global $user_id,$db,$upload_path;

      $timestamp= date("y/m/d H:i:s", time());


//check NRIC / Work Pass document
	if(!empty($_FILES['doc_identity']["name"])){
    $identity_name = $_FILES['doc_identity']['name'];
    $identity_size =$_FILES['doc_identity']['size'];
    $identity_tmp =$_FILES['doc_identity']['tmp_name'];

     	$name_only = pathinfo($identity_name,PATHINFO_FILENAME);
		$extension = pathinfo($identity_name, PATHINFO_EXTENSION);
		$i = 1;
		while(file_exists($upload_path."/document/".$identity_name))
		{           
		    $identity_name = (string)$name_only.$i;
		     $identity_name = $identity_name.".".$extension;
		    $i++;
		}
move_uploaded_file($identity_tmp,$upload_path."/document/".$identity_name);
	}else{
		$identity_name = NULL;
	}
					
//check Appointment Letter document
	if(!empty($_FILES['doc_appointment']["name"])){
    $appointment_name = $_FILES['doc_appointment']['name'];
    $appointment_size = $_FILES['doc_appointment']['size'];
    $appointment_tmp = $_FILES['doc_appointment']['tmp_name'];

        $name_only = pathinfo($appointment_name,PATHINFO_FILENAME);
		$extension = pathinfo($appointment_name, PATHINFO_EXTENSION);
		$i = 1;
		while(file_exists($upload_path."/document/".$appointment_name))
		{           
		    $appointment_name = (string)$name_only.$i;
		     $appointment_name = $appointment_name.".".$extension;
		    $i++;
		}
		move_uploaded_file($appointment_tmp,$upload_path."/document/".$appointment_name);
	}else{
		$appointment_name = NULL;
	}

//check Confirmation Letter document
	if(!empty($_FILES['doc_confirmation']["name"])){
    $confirmation_name = $_FILES['doc_confirmation']['name'];
    $confirmation_size = $_FILES['doc_confirmation']['size'];
    $confirmation_tmp = $_FILES['doc_confirmation']['tmp_name'];

        $name_only = pathinfo($confirmation_name,PATHINFO_FILENAME);
		$extension = pathinfo($confirmation_name, PATHINFO_EXTENSION);
		$i = 1;
		while(file_exists($upload_path."/document/".$confirmation_name))
		{           
		    $confirmation_name = (string)$name_only.$i;
		    $confirmation_name = $confirmation_name.".".$extension;
		    $i++;
		}
		move_uploaded_file($confirmation_tmp,$upload_path."/document/".$confirmation_name);
	}else{
		$confirmation_name = NULL;
	}

//check Confirmation Letter document
	if(!empty($_FILES['doc_resignation']["name"])){
    $resignation_name = $_FILES['doc_resignation']['name'];
    $resignation_size = $_FILES['doc_resignation']['size'];
    $resignation_tmp = $_FILES['doc_resignation']['tmp_name'];

        $name_only = pathinfo($resignation_name,PATHINFO_FILENAME);
		$extension = pathinfo($resignation_name, PATHINFO_EXTENSION);
		$i = 1;
		while(file_exists($upload_path."/document/".$resignation_name))
		{           
		    $resignation_name = (string)$name_only.$i;
		    $resignation_name = $resignation_name.".".$extension;
		    $i++;
		}
		move_uploaded_file($resignation_tmp,$upload_path."/document/".$resignation_name);
	}else{
		$resignation_name = NULL;
	}

	//check Other document
	if(!empty($_FILES['doc_other']["name"])){
    $other_name = $_FILES['doc_other']['name'];
    $other_size = $_FILES['doc_other']['size'];
    $other_tmp = $_FILES['doc_other']['tmp_name'];

        $name_only = pathinfo($other_name,PATHINFO_FILENAME);
		$extension = pathinfo($other_name, PATHINFO_EXTENSION);
		$i = 1;
		while(file_exists($upload_path."/document/".$other_name))
		{           
		    $other_name = (string)$name_only.$i;
		    $other_name = $other_name.".".$extension;
		    $i++;
		}
		move_uploaded_file($other_tmp,$upload_path."/document/".$other_name);
		
	}else{
		$other_name = null;
	}


//check photo
	if(!empty($_FILES['photo']["name"])){
    $photo_name = $_FILES['photo']['name'];
    $photo_size = $_FILES['photo']['size'];
    $photo_tmp = $_FILES['photo']['tmp_name'];

        $name_only = pathinfo($photo_name,PATHINFO_FILENAME);
		$extension = pathinfo($photo_name, PATHINFO_EXTENSION);
		$i = 1;
		while(file_exists($upload_path."/photo/".$photo_name))
		{           
		    $photo_name = (string)$name_only.$i;
		    $photo_name = $photo_name.".".$extension;
		    $i++;
		}
		move_uploaded_file($photo_tmp,$upload_path."/photo/".$photo_name);
		
	}else{
		$phone_name = NULL;
	}



//insert hrms_employee information
      $sql = sprintf("INSERT INTO `hrms_employee`
                (`employment_id`,`first_name`,`last_name`,`date_of_birth`,`gender`,
                `marital_status`,`father_name`,`nationality`,`identity_no`,`photo`,
                  `present_address`,`city`,`country_id`,`mobile`,`phone`,`email`,
                  `emergency_contact`,`designation_id`,`joining_date`,`probation`,`last_date`,
                  `confirmation_date`,`created`,`createdby`,`updated`,`updatedby`,`status`,
                  `work_pass_category_id`,`organization_id`) 
                VALUES 
                ('%s','%s','%s','%s','%d',
                '%d','%s','%d','%s','%s',
                '%s','%s','%d','%s','%s',
                '%s','%s','%d','%s','%d',
                '%s','%s',
                '%s','%d','%s','%d','%d',
                '%d','%d');"
                ,
               $this->employment_id,$this->first_name,$this->last_name,$this->date_of_birth,$this->gender,
               $this->marital_status,$this->father_name,$this->nationality,$this->identity_no,$photo_name,
               $this->present_address,$this->city,$this->country_id,$this->mobile,$this->phone,
               $this->email,$this->emergency_contact,$this->designation_id,$this->joining_date,$this->probation,
               $this->last_date,$this->confirmation_date,
               $timestamp,$user_id,$timestamp,$user_id,$this->isactive,
               $this->work_pass_category_id,1);

//insert hrms_employee information
        if(mysqli_query($db,$sql)) {
        	//get max employee id
        	 $employee_id = $this->getMaxID();

        	//insert employee bank information
        	 $sql_bank = sprintf("INSERT INTO `hrms_employee_bank`
        		 (`employee_id`,`bank_name`,`branch_name`,`account_name`,`account_number`,
                  `created`,`createdby`,`updated`,`updatedby`)
				 VALUES 
                ('%d','%s','%s','%s','%s',
                '%s','%d','%s','%d');"
        		,$employee_id,$this->bank_name,$this->branch_name,$this->account_name,$this->account_number,
               $timestamp,$user_id,$timestamp,$user_id);
				mysqli_query($db,$sql_bank);
			//END employee bank information


			//insert employee document
			 $sql_document = sprintf("INSERT INTO `hrms_employee_document`
        		 (`employee_id`,`doc_identity`,`doc_appointment`,`doc_confirmation`,`doc_resignation`,`doc_other`,
                  `created`,`createdby`,`updated`,`updatedby`)
				 VALUES 
                ('%d','%s','%s','%s','%s','%s',
                '%s','%d','%s','%d');"
        		,$employee_id,$identity_name,$appointment_name,$confirmation_name,$resignation_name,$other_name,
               $timestamp,$user_id,$timestamp,$user_id);
				mysqli_query($db,$sql_document);
			//END employee document


            //if not empty insert employee login
            if(!empty($this->employee_user)){
            		$escapedName = mysql_real_escape_string($this->employee_user);
            		$escapedPW = mysql_real_escape_string($this->employee_pass);
            		# generate a random salt to use for this account
            		$salt = bin2hex(mcrypt_create_iv(32, MCRYPT_DEV_URANDOM));
            		$saltedPW =  $escapedPW . $salt;
            		$hashedPW = hash('sha256', $saltedPW);
            			//insert employee login
            				
                      $sql_login = sprintf("INSERT INTO `hrms_employee_login`
                    		 (`employee_id`,`user_name`,`password`,`salt`,
                              `created`,`createdby`,`updated`,`updatedby`)
            				 VALUES 
                            ('%d','%s','%s','%s',
                            '%s','%d','%s','%d');"
                    		,$employee_id,$escapedName,$hashedPW,$salt,
                           $timestamp,$user_id,$timestamp,$user_id);
            				mysqli_query($db,$sql_login);
            }
            //END employee login

            //START employee salary
           $sql_salary =sprintf("INSERT INTO `hrms_employee_payroll`
                 (`employee_id`,
                  `created`,`createdby`,`updated`,`updatedby`)
                 VALUES 
                ('%d',
                '%s','%d','%s','%d');"
                ,$employee_id,
               $timestamp,$user_id,$timestamp,$user_id);
                mysqli_query($db,$sql_salary);
            //END employee salary

		$_SESSION['msg']="<div class='alert alert-success'>
          Employee Information Save Successfully!
         </div>";
          return true;
        }else {
           $_SESSION['msg']="<div class='alert alert-info'>
           <span class='text-danger'>Failed to Add New Employee, please contact webmaster.</span></div>";
       return false;
        }
	}

//choose department then get designation (ajax submit)
	public function getDesignation($department_id){
		global $db;

				$selectctl = "";
                 $sql="SELECT * FROM hrms_designations where designations_id>0 AND department_id = $department_id order by designations_id";
            
                $query=mysqli_query($db,$sql);
                while($row=mysqli_fetch_assoc($query)){
                $designations_id=$row['designations_id'];
                $designations=$row['designations'];
            
                $SELECTED='';
                $selectctl=$selectctl."<OPTION value='$designations_id' $SELECTED>$designations</OPTION>";
                }
                return $selectctl;
	}

//choose department then get department code and maximun id +1 (ajax submit)
		public function getMaxID(){
		global $db;

			//  $sql="SELECT department_code From hrms_department WHERE department_id = $department_id";
			// $query = mysqli_query($db,$sql);
		 //    $row = mysqli_fetch_assoc($query);
		 //    $id = $row['department_code'];

		       $sql="SELECT MAX(employee_id) From hrms_employee";
		      $query = mysqli_query($db,$sql);
		      $row = mysqli_fetch_assoc($query);

		      return $max= $row['MAX(employee_id)'];
		      // return "<employee_id>".$max."</employee_id>";
		      // $this->next_number = $max;
	}


	public function fetch(){
		global $db,$employee_logo;

		   $sql="SELECT * , DEP.department_id,DES.designations, DEP.department_name from hrms_employee EMP
		    INNER JOIN  hrms_designations DES ON DES.designations_id = EMP.designation_id
		    INNER JOIN  hrms_department DEP ON DEP.department_id = DES.department_id
		    LEFT JOIN  hrms_employee_bank BANK ON BANK.employee_id = EMP.employee_id
		    LEFT JOIN  hrms_employee_document DOC ON DOC.employee_id = EMP.employee_id
		    LEFT JOIN  hrms_employee_login LOG ON LOG.employee_id = EMP.employee_id
            LEFT JOIN  hrms_employee_payroll PAY ON PAY.employee_id = EMP.employee_id
		    WHERE EMP.employee_id = $this->employee_id";

		    $query=mysqli_query($db,$sql);

		    if (mysqli_num_rows($query) > 0){
 
            $row=mysqli_fetch_assoc($query);
			$this->employment_id = $row['employment_id'];
			$this->first_name = $row['first_name'];
			$this->last_name = $row['last_name'];
			$this->date_of_birth = $row['date_of_birth'];
			$this->gender = $row['gender'];
    		$this->marital_status = $row['marital_status'];
    		$this->father_name = $row['father_name'];
    		$this->nationality = $row['nationality'];
    		$this->identity_no = $row['identity_no'];

    		$this->photo = $row['photo'];
            if ($this->photo ==""){
                     $this->photo = $employee_logo;
                }

    		$this->present_address = $row['present_address'];
    		$this->city = $row['city'];
    		$this->country_id = $row['country_id'];
    		$this->mobile = $row['mobile'];
    		$this->phone = $row['phone'];
    		$this->email = $row['email'];
    		$this->emergency_contact = $row['emergency_contact'];
    		$this->designation_id = $row['designation_id'];
    		$this->joining_date = $row['joining_date'];
    		$this->probation = $row['probation'];
    		$this->last_date = $row['last_date'];
              if ($this->last_date == "0000-00-00"){
                $this->last_date = "";
            }

            $this->designations = $row['designations'];
            $this->department_name = $row['department_name'];

    		$this->confirmation_date = $row['confirmation_date'];
            if ($this->confirmation_date == "0000-00-00"){
                $this->confirmation_date = "";
            }
    		$this->department = $row['department_id'];
    		$this->isactive = $row['status'];
            $this->work_pass_category_id = $row['work_pass_category_id'];

    		//Bank information
    		$this->bank_name = $row['bank_name'];
    		$this->branch_name = $row['branch_name'];
    		$this->account_name = $row['account_name'];
    		$this->account_number = $row['account_number'];


    		//Employee Document
    		$this->doc_identity = $row['doc_identity'];
    		$this->doc_appointment = $row['doc_appointment'];
    		$this->doc_confirmation = $row['doc_confirmation'];
    		$this->doc_resignation = $row['doc_resignation'];
    		$this->doc_other = $row['doc_other'];

    		//Employee Login
    		$this->employee_user = $row['user_name'];

            $this->basic_salary = $row['basic_salary'];
        
            $this->employee_cpf_percent = $row['employee_cpf_percent'];
            $this->employer_cpf_percent = $row['employer_cpf_percent'];
            $this->sdl_payable = $row['sdl_payable'];

            //EMPLOYEE CPF
            $this->employee_cpf = $this->basic_salary * $this->employee_cpf_percent /100;
            //EMPLOYER CPF
            $this->employer_cpf = $this->basic_salary * $this->employer_cpf_percent /100;
            //TOTAL CPF CONTRIBUTION
            $this->total_cpf_contribution = $this->employee_cpf + $this->employer_cpf;

            //DEDUCTION
            $this->total_deduction = $this->employee_cpf;

            //NET SALARY (GROSS SALARY - TOTAL DEDUCTION)
            $this->net_salary = $this->basic_salary - $this->total_deduction;

		$warning_msg = "Are want to delete this document?";
		if(!empty($this->doc_identity)){
			$value = "doc_identity";
			$this->del_identity = "<a href='add_employee.php?action=del&employee_id=$this->employee_id&value=$value' class='btn btn-default btn-xs' 
			onClick=\"return confirm('$warning_msg')\"><i class='fa fa-trash-o'></i></a>";
		}else{
			$this->del_identity="";
		}

		if(!empty($this->doc_appointment)){
			$value = "doc_appointment";
			$this->del_appointment = "<a href='add_employee.php?action=del&employee_id=$this->employee_id&value=$value' class='btn btn-default btn-xs' 
			onClick=\"return confirm('$warning_msg')\"><i class='fa fa-trash-o'></i></a>";
		}else{
			$this->doc_appointment="";
		}

		if(!empty($this->doc_confirmation)){
			$value = "doc_confirmation";
			$this->del_confirmation = "<a href='add_employee.php?action=del&employee_id=$this->employee_id&value=$value' class='btn btn-default btn-xs' 
			onClick=\"return confirm('$warning_msg')\"><i class='fa fa-trash-o'></i></a>";
		}else{
			$this->doc_confirmation="";
		}

		if(!empty($this->doc_resignation)){
			$value = "doc_resignation";
			$this->del_resignation = "<a href='add_employee.php?action=del&employee_id=$this->employee_id&value=$value' class='btn btn-default btn-xs' 
			onClick=\"return confirm('$warning_msg')\"><i class='fa fa-trash-o'></i></a>";
		}else{
			$this->doc_resignation="";
		}

		if(!empty($this->doc_other)){
			$value = "doc_other";
			$this->del_other = "<a href='add_employee.php?action=del&employee_id=$this->employee_id&value=$value' class='btn btn-default btn-xs' 
			onClick=\"return confirm('$warning_msg')\"><i class='fa fa-trash-o'></i></a>";
		}else{
			$this->doc_other="";
		}
		return true;
	}else{


  		$_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
           No Record Found!</span>
          </div>";
		}
		return false;
}

	public function update(){
		global $user_id,$db,$upload_path;
      $timestamp= date("y/m/d H:i:s", time());

//check NRIC / Work Pass document
	if(!empty($_FILES['doc_identity']["name"])){
    $identity_name = $_FILES['doc_identity']['name'];
    $identity_size =$_FILES['doc_identity']['size'];
    $identity_tmp =$_FILES['doc_identity']['tmp_name'];

     	$name_only = pathinfo($identity_name,PATHINFO_FILENAME);
		$extension = pathinfo($identity_name, PATHINFO_EXTENSION);
		$i = 1;
		while(file_exists($upload_path."/document/".$identity_name))
		{           
		    $identity_name = (string)$name_only.$i;
		     $identity_name = $identity_name.".".$extension;
		    $i++;
		}
move_uploaded_file($identity_tmp,$upload_path."/document/".$identity_name);
	}
					
//check Appointment Letter document
	if(!empty($_FILES['doc_appointment']["name"])){
    $appointment_name = $_FILES['doc_appointment']['name'];
    $appointment_size = $_FILES['doc_appointment']['size'];
    $appointment_tmp = $_FILES['doc_appointment']['tmp_name'];

        $name_only = pathinfo($appointment_name,PATHINFO_FILENAME);
		$extension = pathinfo($appointment_name, PATHINFO_EXTENSION);
		$i = 1;
		while(file_exists($upload_path."/document/".$appointment_name))
		{           
		    $appointment_name = (string)$name_only.$i;
		     $appointment_name = $appointment_name.".".$extension;
		    $i++;
		}
		move_uploaded_file($appointment_tmp,$upload_path."/document/".$appointment_name);
	}

//check Confirmation Letter document
	if(!empty($_FILES['doc_confirmation']["name"])){
    $confirmation_name = $_FILES['doc_confirmation']['name'];
    $confirmation_size = $_FILES['doc_confirmation']['size'];
    $confirmation_tmp = $_FILES['doc_confirmation']['tmp_name'];

        $name_only = pathinfo($confirmation_name,PATHINFO_FILENAME);
		$extension = pathinfo($confirmation_name, PATHINFO_EXTENSION);
		$i = 1;
		while(file_exists($upload_path."/document/".$confirmation_name))
		{           
		    $confirmation_name = (string)$name_only.$i;
		    $confirmation_name = $confirmation_name.".".$extension;
		    $i++;
		}
		move_uploaded_file($confirmation_tmp,$upload_path."/document/".$confirmation_name);
	}

//check Confirmation Letter document
	if(!empty($_FILES['doc_resignation']["name"])){
    $resignation_name = $_FILES['doc_resignation']['name'];
    $resignation_size = $_FILES['doc_resignation']['size'];
    $resignation_tmp = $_FILES['doc_resignation']['tmp_name'];

        $name_only = pathinfo($resignation_name,PATHINFO_FILENAME);
		$extension = pathinfo($resignation_name, PATHINFO_EXTENSION);
		$i = 1;
		while(file_exists($upload_path."/document/".$resignation_name))
		{           
		    $resignation_name = (string)$name_only.$i;
		    $resignation_name = $resignation_name.".".$extension;
		    $i++;
		}
		move_uploaded_file($resignation_tmp,$upload_path."/document/".$resignation_name);
	}

//check Other document
	if(!empty($_FILES['doc_other']["name"])){
    $other_name = $_FILES['doc_other']['name'];
    $other_size = $_FILES['doc_other']['size'];
    $other_tmp = $_FILES['doc_other']['tmp_name'];

        $name_only = pathinfo($other_name,PATHINFO_FILENAME);
		$extension = pathinfo($other_name, PATHINFO_EXTENSION);
		$i = 1;
		while(file_exists($upload_path."/document/".$other_name))
		{           
		    $other_name = (string)$name_only.$i;
		    $other_name = $other_name.".".$extension;
		    $i++;
		}
		move_uploaded_file($other_tmp,$upload_path."/document/".$other_name);
		
	}

//check photo
	if(!empty($_FILES['photo']["name"])){
    $photo_name = $_FILES['photo']['name'];
    $photo_size = $_FILES['photo']['size'];
    $photo_tmp = $_FILES['photo']['tmp_name'];

        $name_only = pathinfo($photo_name,PATHINFO_FILENAME);
		$extension = pathinfo($photo_name, PATHINFO_EXTENSION);
		$i = 1;
		while(file_exists($upload_path."/photo/".$photo_name))
		{           
		    $photo_name = (string)$name_only.$i;
		    $photo_name = $photo_name.".".$extension;
		    $i++;
		}
		move_uploaded_file($photo_tmp,$upload_path."/photo/".$photo_name);
		
	}

    if ($photo_name==""){
        $photo_name = "";
    }else{
        $photo_name = "photo='$photo_name',";
    }

    if ($identity_name==""){
        $filter = "";
    }else{
        $filter = ",doc_identity='$identity_name'";
    }

    if ($appointment_name==""){
        $filter = $filter."";
    }else{
        $filter = $filter.",doc_appointment='$appointment_name'";
    }

    if ($confirmation_name==""){
        $filter = $filter."";
    }else{
        $filter = $filter.",doc_confirmation='$confirmation_name'";
    }

    if ($resignation_name==""){
        $filter = $filter."";
    }else{
        $filter = $filter.",doc_resignation='$resignation_name'";
    }

    if ($other_name==""){
        $filter = $filter.",DOC.updated = '$timestamp',DOC.updatedby = '$user_id' ";
    }else{
        $filter = $filter.",doc_other = '$other_name',DOC.updated = '$timestamp', DOC.updatedby = '$user_id'";
    }

      $sql="UPDATE hrms_employee EMP
      LEFT JOIN hrms_employee_bank BANK ON EMP.employee_id = BANK.employee_id
      INNER JOIN hrms_employee_login ON EMP.employee_id = hrms_employee_login.employee_id
      LEFT JOIN hrms_employee_document DOC ON EMP.employee_id = DOC.employee_id
      SET employment_id='$this->employment_id',
      first_name='$this->first_name',
      last_name='$this->last_name',
      date_of_birth='$this->date_of_birth',
      gender='$this->gender',
      marital_status='$this->marital_status',
      father_name='$this->father_name',
      nationality='$this->nationality',
      identity_no='$this->identity_no',
      work_pass_category_id='$this->work_pass_category_id',


      $photo_name
      present_address='$this->present_address',
      city='$this->city',
      country_id='$this->country_id',
      mobile='$this->mobile',
      phone='$this->phone',
      email='$this->email',
      emergency_contact='$this->emergency_contact',
      designation_id='$this->designation_id',
      joining_date='$this->joining_date',
      probation='$this->probation',
      last_date='$this->last_date',
      confirmation_date='$this->confirmation_date',
      EMP.updated='$timestamp',
      EMP.updatedby='$user_id',
      status='$this->isactive',

      bank_name='$this->bank_name',
      branch_name='$this->branch_name',
      account_name='$this->account_name',
      account_number='$this->account_number',

      hrms_employee_login.user_name='$this->employee_user',

      BANK.updated='$timestamp',
      BANK.updatedby='$user_id'

      $filter



       WHERE EMP.employee_id = $this->employee_id";

        if(mysqli_query($db,$sql)) {
            
            $_SESSION['msg']="<div class='alert alert-success'>
           Company Information Successfully Updated!
          </div>";
          return true;

        }else {
             $_SESSION['msg']="<div class='alert alert-info'>
             <span class='text-danger'>Failed to Update Employee Information, please contact webmaster.</span></div>";
       
       return false;
        }

	}

	 public function updatePass(){
	 	 global $db,$user_id;
	 	$timestamp= date("y/m/d H:i:s", time());

		$escapedPW = mysql_real_escape_string($this->change_pass);
		# generate a random salt to use for this account
		$salt = bin2hex(mcrypt_create_iv(32, MCRYPT_DEV_URANDOM));
		$saltedPW =  $escapedPW . $salt;
		$hashedPW = hash('sha256', $saltedPW);
			//insert employee login
				
          $sql = "UPDATE hrms_employee_login
          SET password = '$hashedPW',
          salt = '$salt',
          updated = '$timestamp',
          updatedby = $user_id

          WHERE employee_id = $this->employee_id";

		 if (mysqli_query($db,$sql)){
		 	$_SESSION['msg']="<div class='alert alert-success'>
           Password Updated Successfully!
          </div>";
          return true;

        }else {
             $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>Failed to Update Password,please contact webmaster.</span></div>";
             return false;
		 }
			//END employee login
	 }

     // UPDATE DOCUMENT
	public function updateDoc($value){
		    global $db,$user_id;
	$timestamp= date("y/m/d H:i:s", time());
    $this->unlink($value);
     $sql = "UPDATE hrms_employee_document 
     SET $value = NULL,
     updated = '$timestamp',
     updatedby = $user_id
     WHERE employee_id = $this->employee_id";

        if(mysqli_query($db,$sql)) {
        	$_SESSION['msg']="<div class='alert alert-success'>
           Employee Document Deleted Successfully!
          </div>";
        	  return true;
        }else {
            $_SESSION['msg']="<div class='alert alert-success'><span class='text-danger'>
           Failed to Remoce Employee Document, please contact webmaster.</span>
          </div>";
              return false;
        }
	}
//delete file from folder
    public function unlink($value){
        global $db,$upload_path;

  $sql = "SELECT $value FROM hrms_employee_document WHERE employee_id = $this->employee_id ";
        $query=mysqli_query($db,$sql);
        if ($row=mysqli_fetch_assoc($query)){
			$file_name = $row[$value];
               if (unlink($upload_path."/document/".$file_name)){         
        	  return true;
        	}else{
           return true;
        	}
        }
}
//check user NAME duplicate
    public function checkuser($type){
        global $db;

        if($type == "update"){
            $filter = " AND employee_id != $this->employee_id";
        }else{
            $filter = "";
        }
        $username = filter_var($this->employee_user, FILTER_SANITIZE_STRING, FILTER_FLAG_STRIP_LOW|FILTER_FLAG_STRIP_HIGH);
        $sql = "SELECT user_name FROM hrms_admin WHERE user_name = '$username' ";
        $query = mysqli_query($db,$sql);
        if(mysqli_num_rows($query) > 0){
        
        $_SESSION['msg']="<div class='alert alert-success'><span class='text-danger'>
           Failed to Update User Name due to User Name is duplicated.</span>
          </div>";
            return false;
        }else{

             $sql = "SELECT user_name FROM hrms_employee_login WHERE user_name = '$username' $filter";
             $query = mysqli_query($db,$sql);
              if(mysqli_num_rows($query) > 0){
            $_SESSION['msg']="<div class='alert alert-success'><span class='text-danger'>
           Failed to Update User Name due to User Name is duplicated.</span>
          </div>";
            return false;
              }

            return true;
        }
    }


//EMPLOYEE SALART
    public function manage_salary_detail(){
global $up_path;

echo<<<EOF
    <form id="salaryform" class="form-horizontal form-label-left" action="add_employee.php" method="post">
    <div class="col-md-12 col-sm-12 col-xs-12">
   
            <div class="x_title">
                <div class='pull-left'>
                <h2>Employee Information</h2>
                </div>

                <div class='pull-right'>
                   <a href="make_payment.php?employee_id=$this->employee_id" class='btn btn-success btn-xs' data-toggle='tooltip' data-placement='top' data-original-title='Make Payment'><i class='fa fa-list'></i> Make Payment</a>
                </div>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">

                                <div class="table-responsive">
                                    <table >
                                        <tbody>

                                        <tr>
                                            <th class="col-md-12 col-sm-12 col-xs-12" rowspan="5" style="width:10%;"><img src="$up_path/photo/$this->photo" alt="" style="width:160px;height:160px;border-radius: 5px;margin-right:10px;"/></th>
                                            <td colspan='5'><h3>$this->first_name $this->last_name</h3><hr></td>
                                        </tr>


                                        <tr>
                                         
                                            <td style="width:10%;"><strong>Employee ID</strong></td>
                                            <td> $this->employment_id</td>
                                        </tr>
                                        <tr>
                                            <td><strong>Department</strong></td>
                                            <td>$this->department_name</td>
                                        </tr>
                                        <tr>
                                            <td><strong>Designation</strong></td>
                                            <td>$this->designations</td>
                                        </tr>                                                                         
                                        <tr>
                                            <td><strong>Joining Date</strong></td>
                                            <td>$this->joining_date</td>
                                        </tr>                                            
                                    </tbody></table>
                                </div>
                    </div>
    </div>


<!-- ***************** Salary Details  Start *********************-->
<div class="col-md-12 col-sm-12 col-xs-12">
            <div class="x_title">
                <h2>A. Salary Details</h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                    <div class="">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" >Basic Salary<span class="required"> *</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                              <input type="number" class="salary form-control col-md-7 col-xs-12" id="basic_salary" name="basic_salary" value="$this->basic_salary" min="0"
                                              required="required"> 
                                            </div>
                                    </div>

                                   
        </div>
</div>
<!-- ***************** Salary Details  Ends *********************-->
   <!-- ******************-- Monthly CPF Contribution Percentage Panel Start **************************-->

        <div class="col-md-6 col-sm-6 col-xs-12">

            <div class="x_title">
                <h2>B. CPF Contribution<small>PLEASE LET IT BLANK, IF NOT APPLICABLE.</small></h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                 
                            <div class="">
                            <label class="control-label" >I. Employee's Monthly CPF Contribution Percentage ( % )</label> 
                                <input type="number" id="employee_cpf_percent" name="employee_cpf_percent" class="percentage form-control" value="$this->employee_cpf_percent">
                                </label>
                            </div>

                            <div class="">
                                <label class="control-label" >II. Employer's Monthly CPF Contribution Percentage ( % )</label>
                                <input type="number" id="employer_cpf_percent" name="employer_cpf_percent" class="percentage form-control" value="$this->employer_cpf_percent">
                                </label>
                            </div>                        
        </div>
    </div>
   <!-- ********************Monthly CPF Contribution Percentage End ******************-->

      <!-- ******************-- Total CPF Contribution Panel Start **************************-->

        <div class="col-md-6 col-sm-6 col-xs-12">

            <div class="x_title">
                <h2>C. Total CPF Contribution</h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                 
                            <div class="">
                            <label class="control-label" >I. Employee's Monthly CPF Contribution</label> 
                                <input type="number" id="employee_cpf" name="employee_cpf" class="deduction form-control" disabled value="$this->employee_cpf">
                                </label>
                            </div>

                            <div class="">
                                <label class="control-label" >II. Employer's Monthly CPF Contribution</label>
                                <input type="number" id="employer_cpf" name="employer_cpf" class="form-control" disabled value="$this->employer_cpf">
                                </label>
                            </div>

                            <div class="">
                                <label class="control-label" >III. Total Monthly CPF Contribution</label>
                                <input type="number" id="total_cpf_contribution" name="total_cpf_contribution"  class="form-control" disabled value="$this->total_cpf_contribution">
                                </label>
                            </div>           
        </div>
    </div>
   <!-- ********************Total CPF Contribution End ******************-->


   <!-- ******************-- Other Panel Start **************************-->

        <div class="col-md-6 col-sm-6 col-xs-12">

            <div class="x_title">
                <h2>Other<small>PLEASE LET IT BLANK, IF NOT APPLICABLE.</small></h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                 
                            <div class="">
                                <label class="control-label" >SDL Payable</label>
                                <input type="number" name="sdl_payable"  class="form-control" value="$this->sdl_payable">
                                </label>
                            </div>
        </div>
    </div>
   <!-- ********************Other End ******************-->

    <!-- ************** Total Salary Details Start  **************-->
<div class="col-md-6 col-sm-6 col-xs-12">
                    <div class="x_title">
                        <h2>Total Salary Details</h2>
                         <div class="clearfix"></div>
                    </div>

               <div class="x_content">
                            <div class="">
                                <label class="control-label" >Deduction ( C.I ) </label>
                                <input type="number" id="total_deduction" name="total_deduction" disabled class="form-control"  value="$this->total_deduction">
                            </div>                                                        
                            <div class="">
                                <label class="control-label" >Net Salary ( A - C.I)</label>
                                <input type="number" id="net_salary" name="net_salary" disabled class="form-control"  value="$this->net_salary" required="required">
                            </div>         
        </div></div>
 <!-- ************** Total Salary Details End  **************-->
              <div class="col-sm-6 margin pull-right" style="margin-top:25px;">
                <button id="btn_emp" type="submit" class="btn btn-primary btn-block">Save</button>
                        <input type='hidden' value='update_salary' name='action'>
                        <input type='hidden' value='$this->employee_id' name='employee_id'>
            </div>  
 </form>
EOF;
}
//SALARY UPDATE
    public function updateSalary(){
            global $db,$user_id;
    $timestamp= date("y/m/d H:i:s", time());

    if($_SESSION['account_type']!=1){
       echo "<script>alert('You are unable to do this action.') </script>";
       exit;
    }

     $sql = "UPDATE hrms_employee_payroll 
     SET basic_salary = '$this->basic_salary',
     employee_cpf_percent = '$this->employee_cpf_percent',
     employer_cpf_percent = '$this->employer_cpf_percent',
     sdl_payable = '$this->sdl_payable',
     updated = '$timestamp',
     updatedby = $user_id
     WHERE employee_id = $this->employee_id";

        if(mysqli_query($db,$sql)) {
            $_SESSION['msg']="<div class='alert alert-success'>
           Employee Salary Updated Successfully!
          </div>";
              return true;
        }else {
            $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
           Failed to Update Employee Salary, please contact webmaster.</span>
          </div>";
              return false;
        }
    }
    //MANAGE EMPLOYEE LEAVE
    public function manage_leave_detail(){
     global $selectcrtl,$up_path;
        $leave_category = $selectcrtl->getSelectLeaveCat($this->leave_category,'Y');
echo<<<EOF


<!-- ***************** Add Leave Start *********************-->
<div class="col-md-12 col-sm-12 col-xs-12">
    <form id="salaryform" class="form-horizontal form-label-left" action="add_employee.php" method="post">
            <div class="x_title">
                <h2>Add Leave</h2>
                 <div class="clearfix"></div>
            </div>

            <div class="x_content">
                <div class="col-md-6 col-sm-6 col-xs-12 col-md-offset-3">
                    <div class="item form-group">
                        <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Leave Type<span class="required"> *</span>
                        </label>
                        <div class="col-md-6 col-sm-6 col-xs-12">
                                <select name='leave_category' class="form-control" required="required">
                                    $leave_category
                                </select>
                        </div>
                   </div>

                   <div class="item form-group">
                        <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Days of Leave<span class="required"> *</span>
                        </label>
                        <div class="col-md-6 col-sm-6 col-xs-12">
                            <input type="number" min="0" class="salary form-control col-md-7 col-xs-12" id="leave_days" name="leave_days" value="$this->leave_days"
                             required="required"> 
                        </div>
                   </div>


                    <div class="col-md-6 col-md-offset-3">
                        <button id="btn_emp" type="submit" class="btn btn-primary btn-block">Save</button>
                                <input type='hidden' value='save_leave' name='action'>
                                <input type='hidden' value='$this->employee_id' name='employee_id'>
                    </div>  
                </div>
           </div>
    </form>
</div>

<!-- ***************** Add Leave Ends *********************-->

<!-- ***************** Leave Usage Start *********************-->
<div class="col-md-12 col-sm-12 col-xs-12">
            <div class="x_title">
                <h2>Leave Usage</h2>
                 <div class="clearfix"></div>
            </div>

    <div class="x_content">
        
          <table id="leave_usage" class="table table-bordered table-hover dt-responsive" cellspacing="0" width="100%">
                                        <thead>
                                            <tr>
                                                <th>#</th>
                                                <th>Leave Type</th>
                                                <th>Days of Leave</th>
                                                <th>Taken Days </th>
                                                <th>Remaining Days </th>
                                                <th>Action</th>
                                            </tr>
                                        </thead>
                                         <tbody>


EOF;
$this->fetch_leave();
echo<<<EOF
            </tbody></table>
        </div>
      </div>

<!-- *****************Leave Usage Ends *********************-->

<!-- *****************Leave Record Start *********************-->
    <div class="col-md-12 col-sm-12 col-xs-12">
            <div class="x_title">
                <h2>List of All Applications</h2>
                 <div class="clearfix"></div>
            </div>

    <div class="x_content">

            <table id="all_application"  class="table table-bordered table-hover dt-responsive" cellspacing="0" width="100%">
                                        <thead>
                                            <tr>
                                                <th>#</th>
                                                <th>Leave Category</th>
                                                <th>Start Date</th>
                                                <th>End Date</th>
                                                <th>Leave Requested Day(s)</th>
                                                <th>Reason</th>
                                                <th>Applied On</th>
                                                <th>Status</th>
                                                <th>Action</th>
                                            </tr>
                                        </thead>
                    <tbody>
EOF;
$this->get_all_leave_application();
echo<<<EOF
                    </tbody>
            </table>
        </div>

                                <div id="change_days" class='modal fade bs-example-modal-sm' tabindex='-1' role='dialog' aria-hidden='true'>
                                    <div class='modal-dialog modal-sm'>
                                        <div class='modal-content'>

                                            <div class='modal-header'>
                                                <button type='button' class='close' data-dismiss='modal' aria-label='Close'><span aria-hidden='true'>×</span>
                                                </button>
                                                <h4 class='modal-title' id='myModalLabel2'>Change Days of Leave</h4>
                                            </div>
                                            <div class='modal-body'>
                                                <div class=''>
                                                <label class='control-label'>Days of Leave</label>
                                                <input type='number' min="0" name='change_days_of_leave' id='change_days_of_leave' class='form-control'>
                                                </div>
                                            </div>
                                            <div class='modal-footer'>
                                                <button type='button' class='btn btn-default' data-dismiss='modal'>Close</button>
                                                <button type='button' class='btn btn-primary' id="anchor">Save</button>
                                            </div>

                                        </div>
                                    </div>
                                </div>
                                <!-- /Change Days -->
</div>
<!-- *****************Leave Record Ends *********************-->

EOF;
}
//save function
    public function save_leave(){
         global $user_id,$db;
    if($_SESSION['account_type']!=1){
        exit;
    }
      $timestamp= date("y/m/d H:i:s", time());
      $sql = sprintf("INSERT INTO `hrms_employee_leave`
                (`employee_id`,`leave_category_id`,`days_of_leave`,
                  `created`,`createdby`,`updated`,`updatedby`) 
                VALUES 
                ('%d','%d','%s',
                '%s','%d','%s','%d');"
                ,
               $this->employee_id,$this->leave_category,$this->leave_days,
               $timestamp,$user_id,$timestamp,$user_id);


        if(mysqli_query($db,$sql)) {

            $_SESSION['msg']="<div class='alert alert-success'>
           Employee Leave Information Updated Successfully!
          </div>";

          return true;
        }else {
           $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
          Failed to Add Employee Leave due to Employee Leave is already existed.</span></div>";
       return false;
        }
    }

    //FETCH LEAVE
    public function fetch_leave(){
 global $db;

$warning_msg = "Are you want to delete this Leave for this employee?";
    $sql="SELECT employee_leave_id, days_of_leave , LCAT.category,EMP.leave_category_id
    FROM hrms_employee_leave EMP
    INNER JOIN hrms_leave_category LCAT ON LCAT.leave_category_id = EMP.leave_category_id
    WHERE EMP.employee_id = $this->employee_id";
            $query=mysqli_query($db,$sql);

           $i=0;
            while ($row=mysqli_fetch_assoc($query)) {
                $total_days=0;
                $i++;
                $leave_category_id = $row['leave_category_id'];
                $employee_leave_id = $row['employee_leave_id'];
                $category = $row['category'];
                $days_of_leave = $row['days_of_leave'];

                $sql_count = "SELECT total_days FROM hrms_application_list WHERE employee_id = $this->employee_id AND leave_category_id = $leave_category_id AND application_status !=3";
                $query_count=mysqli_query($db,$sql_count);
                while ($row_count=mysqli_fetch_assoc($query_count)) {
                  $count_days = $row_count['total_days'];
                  $total_days = $count_days + $total_days;
                }
                $days_of_remaining = $days_of_leave - $total_days;
              
echo<<<EOF
<tr>
    <td >$i</td>
    <td>$category</td>
    <td>$days_of_leave</td>
    <td>$total_days</td>
    <td>$days_of_remaining</td>
    <td>
    <button type='button' class='btn btn-primary btn-xs' data-toggle='modal' onclick="change_days($employee_leave_id)"><i class='fa fa-pencil-square-o'></i>Edit</button>
    <a href="add_employee.php?action=delete_leave&employee_leave_id=$employee_leave_id&employee_id=$this->employee_id" data-original-title='Delete'  onclick="return confirm('$warning_msg')" class='btn btn-danger btn-xs'  data-toggle='tooltip' data-placement='top' data-original-title='Deactive'><i class='fa fa-trash-o'></i>Delete</a>
    </td>   
</tr>
EOF;
 }
}
    public function update_leave_days($employee_leave_id,$change_days){
        global $db,$user_id;

         $timestamp= date("y/m/d H:i:s", time());

      $sql = "UPDATE hrms_employee_leave 
     SET days_of_leave = '$change_days',
     updated = '$timestamp',
     updatedby = $user_id
     WHERE employee_leave_id = $employee_leave_id";

        if(mysqli_query($db,$sql)) {
            $_SESSION['msg']="<div class='alert alert-success'>
           Employee Leave Information Updated Successfully!
          </div>";
              return true;
        }else {
            $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
          Failed to Update Employee Leave Days, please contact webmaster.</span>
          </div>";
              return false;
        }
    }

    public function delete_leave($employee_leave_id){
        global $db,$user_id;

         $timestamp= date("y/m/d H:i:s", time());

    if($_SESSION['account_type']!=1){
       echo "<script>alert('You are unable to do this action.') </script>";
       exit;
    }
    $sql = "SELECT leave_category_id FROM hrms_employee_leave WHERE employee_leave_id = $employee_leave_id";
    if($query = mysqli_query($db,$sql)) {
        $row=mysqli_fetch_assoc($query);
        $leave_category_id = $row['leave_category_id'];
    }

    $this->checkDelLeaveType($leave_category_id);

         $sql = "DELETE FROM hrms_employee_leave WHERE employee_leave_id = $employee_leave_id";
        if(mysqli_query($db,$sql)) {
              $_SESSION['msg'] ="<div class='alert alert-success'>
           Employee Leave Information Updated Successfully!
          </div>";
          return true;
        }else {
              $_SESSION['msg'] ="<div class='alert alert-info'><span class='text-danger'>
              Failed to Delete Employee Leave Type, please contact webmaster.</span></div>";
        return true;
        }

    }
        //check leave type in used
 public function checkDelLeaveType($leave_category_id){
    global $db,$user_id;

    $sql = "SELECT application_list_id FROM hrms_application_list
    WHERE employee_id = $this->employee_id AND leave_category_id = $leave_category_id";
    $query=mysqli_query($db,$sql);

        // if no data to show
        if (mysqli_num_rows($query) == 0) {
            return true;
        }else{

            $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
           Failed to Delete Leave Type due to Leave Type is already in used.</span>
          </div>";
            echo "<script>window.location = 'add_employee.php?action=edit&employee_id=$this->employee_id#manage_leave'</script>";
            exit;

        }
 }

 public function get_all_leave_application(){
        global $db,$user_id;

         $sql="SELECT application_list_id AS application_id,hrms_leave_category.category,leave_start_date, leave_end_date, reason, application_status, hrms_application_list.created AS applied_on,total_days
         FROM hrms_application_list
         INNER JOIN hrms_leave_category ON hrms_leave_category.leave_category_id = hrms_application_list.leave_category_id
         WHERE employee_id = $this->employee_id
         ORDER BY applied_on asc";
         $query=mysqli_query($db,$sql);
          $i=0;
            while ($row=mysqli_fetch_assoc($query)) {
                $i++;
                $application_id = $row['application_id'];
                $category = $row['category'];
                $leave_start_date = $row['leave_start_date'];
                $leave_end_date = $row['leave_end_date'];
                $total_days = $row['total_days'];
                $reason = $row['reason'];
                $application_status = $row['application_status'];
                $applied_on = $row['applied_on'];

            $str = strlen($reason);
            if ($str > 40) {
                $ss = '<strong>......</strong>';
            } else {
                $ss = '&nbsp';
             } $reason = substr($reason, 0, 40) . $ss;

            if ($application_status == 1) {
                $application_status = '<span class="label label-info">Pending</span>';
            } elseif ($application_status == 2) {
                 $application_status = '<span class="label label-success">Accepted</span>';
            } else {
                $application_status = '<span class="label label-danger">Rejected</span>';
            }

echo<<<EOF
<tr>
    <td>$i</td>
    <td>$category</td>
    <td>$leave_start_date</td>
    <td>$leave_end_date</td>
    <td>$total_days</td>

    <td>$reason</td>
    <td>$applied_on</td>
    <td>$application_status</td>
    

    <td><a href="view_application.php?application_id=$application_id" data-original-title='View' class='btn btn-info btn-xs' data-toggle='tooltip' data-placement='top' ><i class='fa fa-list-alt'></i> View</a></td>                                                                                                     
</tr>
EOF;
}
    }
}//END OF THE CLASS
