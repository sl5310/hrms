<?php 

class make_payment{

  public $employee_id;
  public $msg;
  public $employment_id;
  public $first_name;
  public $last_name;
  public $photo;
  public $joining_date;
  public $designations;
  public $department_name;
  public $basic_salary;
 
  public $employee_cpf_percent;
  public $employer_cpf_percent;
  public $sdl_payable;

  public $employee_cpf;
  public $employer_cpf;
  public $total_cpf_contribution;
  public $total_deduction;
  public $net_salary;

  public $ot_hours_worked;
  public $total_ot_pay;

  public $allowances_field;
  public $total_allowances;
  public $payment_amount;
  public $payment_month;

  public $payment_type;
  public $payment_date;

  public $overtime_rate;
  public $hours_worken_week;


  public $item_remark;
  public $item_amount;
  public $isCPF;
  public $isAdd;
  public $isDeduc;
  public $deduc_remark;
  public $deduc_amount;

  public $payment_id;

  public $gross_salary;
  public $hidden_deduction;

	public function inputform($type){

		    if (!empty($_SESSION['msg'])) {
       $this->msg = $_SESSION['msg'];
    }

		echo<<<EOF

<div class="right_col" role="main">
  <div class="">
      <div class="row">
        <div class="col-md-12 col-sm-12 col-xs-12">
        <h4><a href="make_payment.php?employee_id=$this->employee_id"><i class="fa fa-plus"></i> New Payment</a></h4>
          <div id="msg">
          $this->msg                         
          </div>
              <div class="x_content">

                                  
                                        <ul id="myTab1" class="nav nav-tabs bar_tabs right" role="tablist">
                                            <li><a href="#payment_history"  data-toggle="tab"><i class="fa fa-history"></i> Payment History</a>
                                            </li>
                                            <li class="active"><a href="#make_payment" data-toggle="tab"><i class="fa fa-tasks"></i> Make Payment</a>
                                            </li>
                                        </ul>

                                        <div class="tab-content">

                                        <div class="tab-pane active" id="make_payment">
EOF;
$this->manage_make_payment($type);
echo<<<EOF
                                            </div>

                                      <div class="tab-pane" id="payment_history">
EOF;
$this->manage_payment_history();
echo<<<EOF
                            </div>                   
              </div>
          </div>

     <!-- daterangepicker -->
    <script type="text/javascript" src="../asset/js/datepicker/daterangepicker.js"></script>


<script type="text/javascript">
    $(document).ready(function() {

        var hash = window.location.hash;
              hash && $('ul.nav a[href="' + hash + '"]').tab('show');

              $('.nav-tabs a').click(function (e) {
                $(this).tab('show');
                window.location.hash = this.hash;
                if(window.location.hash == "#payment_history"){
                 location.reload();
                }
              });

  $('#example').DataTable( {
    responsive: true
  });
        $('#payment_date').datepicker({
          format: 'yyyy-mm-dd',
          autoclose: true,
          orientation: "top auto"
        });

        $('#payment_month').datepicker({
         format: "MM-yyyy",
          viewMode: "months", 
          minViewMode: "months",
          autoclose: true,
          orientation: "top auto"
        });

        $("#add_line_cpf").click(function() {
                var add_new ='<div class="form-group">'
                +'<div class="col-md-5 col-sm-5 col-xs-6"><input type="text" name="item_cpf_remark[]" class="form-control" placeholder="Enter Detail" required="required"/></div>'
                +'<div class="col-md-5 col-sm-5 col-xs-6"><input type="number" min="0" name="item_cpf_amount[]" class="form-control item_cpf" placeholder="Enter Amount" required="required"/></div>'
                +'<div class="col-sm-2">'
                +'<strong><a href="javascript:void(0);" class="remItmCPF"> Remove</a></strong></div>';

                $("#add_item_cpf").append(add_new);
        });

        $("#add_item_cpf").on('click', '.remItmCPF', function() {
            $(this).parent().parent().parent().remove();
        });

        $("#add_line_non_cpf").click(function() {
                var add_new ='<div class="form-group">'
                +'<div class="col-md-5 col-sm-5 col-xs-6"><input type="text" name="item_NON_cpf_remark[]" class="form-control" placeholder="Enter Detail" required="required"/></div>'
                +'<div class="col-md-5 col-sm-5 col-xs-6"><input type="number" min="0" name="item_NON_cpf_amount[]" class="form-control item_non_cpf" placeholder="Enter Amount" required="required"/></div>'
                +'<div class="col-sm-2">'
                +'<strong><a href="javascript:void(0);" class="remItmNCPF">Remove</a></strong></div>';

                $("#add_item_non_cpf").append(add_new);
        });

        $("#add_item_non_cpf").on('click', '.remItmNCPF', function() {
            $(this).parent().parent().parent().remove();
        });

        $("#add_line_deduction").click(function() {
                var add_new ='<div class="form-group">'
                +'<div class="col-md-5 col-sm-5 col-xs-6"><input type="text" name="deduc_remark[]" class="form-control" placeholder="Enter Detail" required="required"/></div>'
                +'<div class="col-md-5 col-sm-5 col-xs-6"><input type="number" min="0" name="deduc_amount[]" class="form-control deduction" placeholder="Enter Amount" required="required"/></div>'
                +'<div class="col-sm-2">'
                +'<strong><a href="javascript:void(0);" class="remDeduc"> Remove</a></strong></div>';

                $("#add_deduction").append(add_new);
        });

        $("#add_deduction").on('click', '.remDeduc', function() {
            $(this).parent().parent().parent().remove();
        });
        
        var item_cpf = 0;
        var item_non_cpf =0;
        var deduc =0;

        $(".item_cpf").each(function() {
            item_cpf += +$(this).val();
        });

         $(".item_non_cpf").each(function() {
            item_non_cpf += +$(this).val();
        });

        $(".deduction").each(function() {
            deduc += +$(this).val();
        });

        $("#total_item_cpf").val(item_cpf.toFixed(2));
        $("#total_item_NON_cpf").val(item_non_cpf.toFixed(2));
        $("#total_deduction").val(deduc.toFixed(2));
        $("#hidden_deduction").val(deduc.toFixed(2));
    });

$(document).on("click", function() {

        var emp_cpf_per = "$this->employee_cpf_percent";
        var com_cpf_per = "$this->employer_cpf_percent";
        var basic_salary = +$('#basic_salary').val();
        var hours_worken_week = "$this->hours_worken_week";
        var overtime_rate = "$this->overtime_rate";
        var ot_hours_worked = $('#ot_hours_worked').val();

        var overtime_pay = 0;
        var hourly_basic_pay = 0;
        var employee_cpf = 0;
        var employer_cpf = 0;
        var sum_allowance = 0;
        var item_cpf = 0;
        var item_non_cpf =0;
        var deduc = 0;

        hourly_basic_pay = (12*basic_salary) / (52*hours_worken_week);
        if (hourly_basic_pay == "Infinity"){
          hourly_basic_pay = 0;
        }


        overtime_pay = (hourly_basic_pay * overtime_rate * ot_hours_worked).toFixed(2);
        $("#total_ot_pay").val(overtime_pay);

        $(".item_cpf").each(function() {
            item_cpf += +$(this).val();
        });

        $(".item_non_cpf").each(function() {
            item_non_cpf += +$(this).val();
        });

        employee_cpf = ((item_cpf +basic_salary) * (emp_cpf_per /100)).toFixed(2);
        $("#employee_cpf").val(employee_cpf);

        employer_cpf = ((item_cpf + basic_salary) * (com_cpf_per /100)).toFixed(2);
        $("#employer_cpf").val(employee_cpf);

        $(".deduction").each(function() {
            deduc += +$(this).val();
        });

        
        $("#total_item_cpf").val(item_cpf.toFixed(2));
        $("#total_item_NON_cpf").val(item_non_cpf.toFixed(2));
        $("#total_deduction").val(deduc.toFixed(2));
                    $("#hidden_deduction").val(deduc.toFixed(2));

        $("#gross_salary").val((basic_salary + item_cpf + item_non_cpf).toFixed(2));


        net_salary = ((basic_salary + item_cpf + item_non_cpf - deduc).toFixed(2));
        $("#net_salary").val(net_salary);
        $("#payment_amount").val(net_salary);
    });

$('#inputform').parsley(); //validate form


setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 2000); // <-- time in milliseconds


  function delete_payment(payment_id){
    if(confirm('Confirm to detele this PAYMENT permanently?')){
      
              var data="action=delete&payment_id="+payment_id;
              $.ajax({url: "make_payment.php", type: "POST", data: data, cache: false, success: function (xml) {
               window.location.reload();
              }
              });
            
        }
  }


</script>
EOF;

$this->msg = null;
$_SESSION['msg'] = null;

	}  

  public function manage_make_payment($type){
    global $up_path,$selectcrtl;
    
$payment_type = $selectcrtl->getSelectPaymentType($this->payment_type,'Y');
    if ($type == "new"){
    $action = "save";
    $payment_id = "";
    }else{
    $action = "update";
    $payment_id = "<input type='hidden' value='$this->payment_id' name='payment_id'>";
    }

    echo<<<EOF
    <!-- ************** Employee Information Start **************-->
    <div class="col-md-12 col-sm-12 col-xs-12">
            <div class="x_title">
                <div class='pull-left'>
                <h2>Employee Information</h2>
                </div>
                <div class='pull-right'>
                   <a href="add_employee.php?action=edit&employee_id=$this->employee_id#manage_salary" class='btn btn-success btn-xs' data-toggle='tooltip' data-placement='top' data-original-title='Manage Employee Salary Details'><i class='fa fa-list'></i> Manage Employee Salary Details</a>
                </div>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                  <div class="table-responsive">
                                    <table>
                                        <tbody>

                                        <tr>
                                            <th rowspan="5" style="width:10%;"><img src="$up_path/photo/$this->photo" alt="" style="width:160px;height:160px;border-radius: 5px;margin-right:10px;"/></th>
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
           <!-- ************** Employee information End **************-->

           <!-- ************** Leave Summary Start **************-->
           <div class="col-md-7 col-sm-7 col-xs-12" style="margin-top:10px;">
           </div>
           <!-- ************** Leave Summary End **************-->

        <!-- ************** Make Payment Start **************-->
        <div class="col-md-5 col-sm-5 col-xs-12" style="margin-top:10px;">
          <div class="panel panel-primary">

              <div class="panel-heading" >
                          <h4 class="panel-title">Payment Information</h4>
                           <div class="clearfix"></div>
              </div>

               <div class="panel-body">
                  <form id="inputform" class="form-horizontal form-label-left" action="make_payment.php" method="post" data-parsley-validate>

                           <div class="item form-group">
                                <label class="control-label col-md-4 col-sm-4 col-xs-12"><h5><strong>Payment For <span class="required">*</span></strong></h5></label>
                                <div class="col-md-6 col-sm-6 col-xs-12">
                                <input type="text" class="form-control date-picker" name="payment_month" value="$this->payment_month" id="payment_month"
                                    placeholder="Month-Year" required="required">
                                </div>
                            </div>

                          <!-- ************** Basic Pay Start **************-->


                           <div class="item form-group">
                                <label class="control-label col-md-4 col-sm-4 col-xs-12">A. Basic Salary</label>
                                <div class="col-md-6 col-sm-6 col-xs-12">
                                <input type="number" step="any" class="form-control" id="basic_salary" name="basic_salary" required="required" value="$this->basic_salary" required="required" readonly="readonly">
                                </div>
                            </div>
                            <!-- ************** Basic Pay End  **************-->

                             <!-- ************** Pay Item (CPF) Start  **************-->
                            <div class="ln_solid"></div>

                            <div class="item form-group">
                                <label class="control-label col-md-4 col-sm-4 col-xs-12"><h5><strong>B. Pay Item (CPF)</strong></h5></label>
                                <abbr title="Under this section is CPF payable."><i class="fa fa-question-circle"></i></abbr>
                                <a href="javascript:void(0);" id="add_line_cpf" class="pull-right addCF"><i class="fa fa-plus"></i>&nbsp;Add Line</a>
                                <div class="col-md-6 col-sm-6 col-xs-12">
                                <input type="number" step="any" class="form-control" style="background-color:#FCF5D8;" id="total_item_cpf" name="total_item_cpf" required="required" value="" required="required" readonly="readonly">
                                </div>
                            </div>

                            <div class="form-group">
                              <label class="control-label col-md-4 col-sm-4 col-xs-12">Total Overtime Pay</label>
                              <abbr title="Please set 'Overtime rate' and 'No. of hours worken in a week' at Payroll Management > Set Overtime Rate"><i class="fa fa-question-circle"></i></abbr>
                              <div class="col-md-6 col-sm-6 col-xs-12">
                              <input type="number" step="any" class="form-control item_cpf" id="total_ot_pay" name="total_ot_pay" readonly="readonly" value="$this->total_ot_pay">
                              </div>
                            </div>

                            <div class="item form-group">
                              <label class="control-label col-md-4 col-sm-4 col-xs-12">Overtime Hours Worked</label>
                              <div class="col-md-6 col-sm-6 col-xs-12">
                              <input type="number" step="any" class="form-control overtime" id="ot_hours_worked" name="ot_hours_worked" value="$this->ot_hours_worked">
                              </div>
                            </div>

                            <div id="add_item_cpf">
EOF;
if ($type == "edit"){
  $this->additional_cpf_fetch();
}
echo<<<EOF
                            </div>
                            <!-- ************** Pay Item (CPF) End  **************-->

                          <!-- ************** Basic Pay End  **************-->


                           
                           <!-- ************** Allowances Start **************-->
                            <div class="ln_solid"></div>
                             <div class="item form-group">
                                     <label class="control-label col-md-4 col-sm-4 col-xs-12"><h5><strong>C. Pay Item (Non-CPF)</strong></h5></label> 
                                     <abbr title="Under this section is CPF Non-payable."><i class="fa fa-question-circle"></i></abbr>
                                     <a href="javascript:void(0);" id="add_line_non_cpf" class="pull-right addCF"><i class="fa fa-plus"></i>&nbsp;Add Line</a>
                                     <div class="col-md-6 col-sm-6 col-xs-12">
                                      <input type="number" step="any" class="form-control" style="background-color:#FCF5D8;" id="total_item_NON_cpf" name="total_item_NON_cpf" value="$this->total_allowances" readonly="readonly">
                                    </div>
                            </div>

                              $this->allowances_field
                              <div id="add_item_non_cpf">
EOF;
if ($type == "edit"){
  $this->additional_non_cpf_fetch();
}
echo<<<EOF
                              </div>

                          <!-- ************** Allowances End **************-->

                            <!-- ************** Deduction Start **************-->
                             <div class="ln_solid"></div>
                             <div class="item form-group">
                                   <label class="control-label col-md-4 col-sm-4 col-xs-12"><h5><strong>D. Total Deduction</strong></h5></label><a href="javascript:void(0);" id="add_line_deduction" class="pull-right addCF "><i class="fa fa-plus"></i>&nbsp;Add Line</a>
                                   <div class="col-md-6 col-sm-6 col-xs-12">
                                   <input type="number" step="any" class="form-control" style="background-color:#FCF5D8;" id="total_deduction" name="total_deduction" readonly="readonly">
                                   </div>
                            </div>

                            <div class='item form-group'>
                                          <label class='control-label col-md4 col-sm-4 col-xs-12'>Employee's CPF Contribution</label>
                                          <div class='col-md-6 col-sm-6 col-xs-12'>
                                           <input type="number" step="any" class='form-control deduction' id='employee_cpf' name='employee_cpf' value='$this->employee_cpf' readonly="readonly">
                                            </div>
                            </div>

                            <div id="add_deduction">
EOF;
if ($type == "edit"){
  $this->deduction_fetch();
}
echo<<<EOF
                            </div>

                          <!-- ************** Deduction End **************-->


                           <!-- ************** Overtime Details Start **************-->
                           <div class="ln_solid"></div>

                           <div class='item form-group'>
                                           <label class='control-label col-md-4 col-sm-4 col-xs-12'>Employer’s CPF Contribution</label>
                                           <div class='col-md-6 col-sm-6 col-xs-12'>
                                           <input type="number" step="any" class='form-control' id='employer_cpf' name='employer_cpf' value='$this->employer_cpf' readonly="readonly">
                                            </div>
                          </div>

                            <div class="item form-group">
                                  <label class="control-label col-md-4 col-sm-4 col-xs-12">SDL Payble</label>
                                  <div class="col-md-6 col-sm-6 col-xs-12">
                                  <input type="number" step="any" class="form-control" id="sdl_payable" name="sdl_payable" value="$this->sdl_payable" readonly="readonly">
                                  </div>
                            </div>


                            <div class="item form-group">
                                  <label class="control-label col-md-4 col-sm-4 col-xs-12"><h5><strong>Net Salary(A+B+C-D)</strong></h5></label>
                                  <div class="col-md-6 col-sm-6 col-xs-12">
                                  <input type="number" step="any" class="form-control" style="background-color:#FCF5D8;" id="net_salary" name="net_salary" value="$this->net_salary" readonly="readonly">
                                  </div>
                            </div>


                          <!-- ************** Overtime Details End **************-->

                          <!-- ************** Payment Amount Start **************-->
                            <div class="item form-group">
                                 <label class="control-label col-md-4 col-sm-4 col-xs-12"><h5><strong>Payment Amount <span class="required">*</span></strong></h5></label>
                                 <div class="col-md-6 col-sm-6 col-xs-12">
                                 <input type="number" step="any" style="background-color:#FCF5D8;" class="form-control" id="payment_amount" name="payment_amount" value="$this->payment_amount">
                                 </div>
                            </div>

                             <div class="item form-group">
                                <label class="control-label col-md-4 col-sm-4 col-xs-12" for="name"><h5><strong>Payment Type <span class="required">*</span></strong></h5></label>
                                <div class="col-md-6 col-sm-6 col-xs-12">
                                  <select name='payment_type' class="form-control" required="required">
                                          $payment_type
                                          </select>
                                </div>
                            </div>

                            <div class="item form-group">
                              <label class="control-label col-md-4 col-sm-4 col-xs-12"><h5><strong>Payment Date <span class="required">*</span></strong></h5></label>
                              <div class="col-md-6 col-sm-6 col-xs-12">
                              <input type="text" class="form-control datepicker" id="payment_date" name="payment_date" placeholder="yyyy-mm-dd" value="$this->payment_date" required="required"> 
                              </div>
                            </div>

                           <div class="item form-group">
                                  <label class="control-label col-md-4 col-sm-4 col-xs-12">Comments</label>
                                  <div class="col-md-6 col-sm-6 col-xs-12">
                                  <textarea class="form-control" id="comments" name="comments"></textarea>
                                  </div>
                            </div>
                          <!-- ************** Payment Amount End **************-->
                          <div class="ln_solid"></div>
                          <div class="col-md-6 col-sm-6 col-xs-12 col-md-offset-3">
                        <button type="submit" class="btn btn-primary btn-block">Save</button>
                        <input type='hidden' value='$this->employee_id' name='employee_id'>
                        <input type='hidden' value='$action' name='action'>
                        <input type='hidden' name='gross_salary' id='gross_salary'>
                        <input type='hidden' name='hidden_deduction' id='hidden_deduction'>
                        $payment_id
                         </div>
                  </form> 
              </div>
          </div>
      </div>
      <!-- ************** Make Payment End **************-->
EOF;
  }

	  public function save(){
    global $db,$user_id;
     if($_SESSION['account_type']!=1){
        exit;
    }

    //Call Select Overtime Rate
    $this->getOTrate();
    $this->getEPFrate();

    $this->payslip_no =  $this->getMaxPayslipNo();

      $timestamp= date("y/m/d H:i:s", time());
      $sql = sprintf("INSERT INTO `hrms_salary_payment`
                (`payslip_no`,`employee_id`,`payment_month`,`basic_salary`,`ot_rate`,`hours_worken_week`,`ot_hours_worked`,`total_ot_pay`,
                 `employee_cpf_percent`, `employee_cpf`,`employer_cpf_percent`,`employer_cpf`,`sdl_payable`,`net_salary`,
                  `payment_amount`,`payment_type`,`payment_date`,`comments`,`gross_salary`,`total_deduction`,
                  `created`,`createdby`,`updated`,`updatedby`) 
                VALUES 
                ('%d','%d','%s','%s','%s','%s','%s','%s',
                '%s','%s','%s','%s','%s','%s',
                '%s','%d','%s','%s','%s','%s',
                '%s','%d','%s','%d');"
                ,
               $this->payslip_no,$this->employee_id,$this->payment_month,$this->basic_salary,$this->overtime_rate,$this->hours_worken_week,$this->ot_hours_worked,$this->total_ot_pay,
               $this->employee_cpf_percent,$this->employee_cpf,$this->employer_cpf_percent,$this->employer_cpf,$this->sdl_payable,$this->net_salary,
               $this->payment_amount,$this->payment_type,$this->payment_date,$this->comments,$this->gross_salary,$this->hidden_deduction,
               $timestamp,$user_id,$timestamp,$user_id);

        if(mysqli_query($db,$sql)) {

            $_SESSION['msg']="<div class='alert alert-success'>
           The payment is make successfully!
          </div>";

          return true;
        }else {
           $_SESSION['msg']="<div class='alert alert-info'>The Payment Is Unsuccessfully!</div>";
       return false;
        }
  }

//SAVE ITEM WITH CPF
   public function save_salary_item($type){
    global $db,$user_id;
     if($_SESSION['account_type']!=1){
        exit;
    }

    if ($type == "new"){
    $this->payment_id = $this->getMaxPayment_ID();  //Get Maximun Payment ID
    }
      $timestamp= date("y/m/d H:i:s", time());
      $sql = sprintf("INSERT INTO `hrms_salary_item`
                (`payment_id`,`item_remark`,`item_amount`,`isCPF`,`isAdd`,`isDeduc`,
                  `created`,`createdby`,`updated`,`updatedby`) 
                VALUES 
                ('%d','%s','%s','%d','%d','%d',
                '%s','%d','%s','%d');"
                ,
               $this->payment_id,$this->item_remark,$this->item_amount,$this->isCPF,$this->isAdd,$this->isDeduc,
               $timestamp,$user_id,$timestamp,$user_id);


        if(mysqli_query($db,$sql)) {

        }else{
          echo "Cannot insert pay item";
          die;
        }
  }

  //Get Maximun Payslip No
    public function getMaxPayslipNo(){
    global $db;

           $sql="SELECT MAX(payslip_no) From hrms_salary_payment";
          $query = mysqli_query($db,$sql);
          $row = mysqli_fetch_assoc($query);

          $payslip_no= $row['MAX(payslip_no)'];

          if ($payslip_no==""){
          return $payslip_no="246820"; 
          }else{
          return $payslip_no + 1;
          }
  }

    //Get Maximun Payment ID
    public function getMaxPayment_ID(){
    global $db;

          $sql="SELECT MAX(payment_id) From hrms_salary_payment";
          $query = mysqli_query($db,$sql);
          $row = mysqli_fetch_assoc($query);

          return $row['MAX(payment_id)'];
  }

   

//SELECT EMPLOYEE INFORMATION
  public function getinformation(){
 global $db,$employee_logo;

   $sql="SELECT EMP.employee_id, joining_date, photo, sdl_payable, employment_id, first_name, last_name, DES.designations, department_name ,basic_salary,employee_cpf_percent, employer_cpf_percent
            FROM hrms_employee EMP
            INNER JOIN  hrms_designations DES ON DES.designations_id = EMP.designation_id
            INNER JOIN  hrms_department DEP ON DEP.department_id = DES.department_id
            LEFT JOIN  hrms_employee_payroll PAY ON PAY.employee_id = EMP.employee_id
            WHERE EMP.employee_id = $this->employee_id";

    if ($query=mysqli_query($db,$sql)){
      if (mysqli_num_rows($query) > 0){
            $row=mysqli_fetch_assoc($query);
            $this->employment_id = $row['employment_id'];
            $this->first_name = $row['first_name'];
            $this->last_name = $row['last_name'];

            $this->photo = $row['photo'];
                if ($this->photo ==""){
                         $this->photo = $employee_logo;
                    }
            $this->joining_date = $row['joining_date'];
          
            $this->designations = $row['designations'];
            $this->department_name = $row['department_name'];

            $this->basic_salary = $row['basic_salary'];
            $this->employee_cpf_percent = $row['employee_cpf_percent'];
            $this->employer_cpf_percent = $row['employer_cpf_percent'];
            $this->sdl_payable = $row['sdl_payable'];

            //EMPLOYEE CPF
            $this->employee_cpf = $this->basic_salary * $this->employee_cpf_percent /100;
            if($this->employee_cpf ==0){
              $this->employee_cpf = "";
            }


            //EMPLOYER CPF
            $this->employer_cpf = $this->basic_salary * $this->employer_cpf_percent /100;
            if($this->employer_cpf ==0){
              $this->employer_cpf = "";
            }

            //TOTAL CPF CONTRIBUTION
            $this->total_cpf_contribution = $this->employee_cpf + $this->employer_cpf;

            //DEDUCTION
            $this->total_deduction = $this->employee_cpf;
            if($this->total_deduction ==0){
              $this->total_deduction = "";
            }

            //NET SALARY (GROSS SALARY - TOTAL DEDUCTION)
            $this->net_salary = $this->basic_salary - $this->total_deduction;

            $this->payment_amount = $this->net_salary;

            //Call Select Overtime Rate
            $this->getOTrate();

      }else{

        //if no record
         header("Location: employee_salary_list.php",500);
          exit;
      }
    }else{
      //if query failed
          header("Location: employee_salary_list.php",500);
          exit;
    }
}
  
  public function getOTrate(){
    global $db;
    $sql = "SELECT * FROM hrms_overtime_rate WHERE flag = 1";
            if ($query=mysqli_query($db,$sql)){

            $row=mysqli_fetch_assoc($query);
            $this->overtime_rate = $row['overtime_rate'];
            $this->hours_worken_week = $row['hours_worken_week'];

          }else{
               $_SESSION['msg']="<div class='alert alert-success'>
                      Cannot fetch OT Rate, please contact web master.
                      </div>";
          header("Location: make_payment.php?employee_id=$this->employee_id#payment_history",500);
          exit; 
            }
  }
    public function getEPFrate(){
    global $db;
    $sql = "SELECT * FROM hrms_employee_payroll WHERE employee_id = $this->employee_id";
            if($query=mysqli_query($db,$sql)){
            $row=mysqli_fetch_assoc($query);
            $this->employee_cpf_percent = $row['employee_cpf_percent'];
            $this->employer_cpf_percent = $row['employer_cpf_percent'];
            }else{
               $_SESSION['msg']="<div class='alert alert-success'>
                      Cannot fetch CPF Rate, please contact web master.
                      </div>";
          header("Location: make_payment.php?employee_id=$this->employee_id#payment_history",500);
          exit; 
            }
  }
  public function manage_payment_history(){

    echo<<<EOF

    <div class="col-md-12 col-sm-12 col-xs-12">
            <div class="x_title">
                <h2>Payment History</h2>
                 <div class="clearfix"></div>
            </div>

       <div class="x_content">
         <table id="example" class="table table-bordered table-hover dt-responsive" cellspacing="0" width="100%">
                                        <thead>
                                            <tr>
                                                <th>#</th>
                                                <th>Payslip No</th>
                                                <th>Payment Month</th>
                                                <th>Payment Date</th>
                                                <th>Basic Salary</th>
                                                <th>Gross Salary</th>
                                                <th>Total Deduction</th>
                                                <th>Net Salary</th>
                                                <th>Payment Amount</th>
                                                <th>Mode of Payment</th>
                                                <th>Prepared By</th>
                                                <th>Payslip</th>
                                                <th>Action</th>
                                            </tr>
                                        </thead>
                                         <tbody>

EOF;
$this->fetch();
echo "</tbody></table></div></div>";
  }

	  public function fetch(){
 global $db;

   $sql = "SELECT * ,hrms_admin.first_name, hrms_admin.last_name 
    FROM hrms_salary_payment
    INNER JOIN hrms_payment_type ON hrms_payment_type.payment_type_id = hrms_salary_payment.payment_type
    INNER JOIN hrms_admin ON hrms_admin.user_id = hrms_salary_payment.updatedby
    WHERE employee_id = $this->employee_id";
         
    if ($query=mysqli_query($db,$sql)){
         $i=0;
         while ($row=mysqli_fetch_assoc($query)) {
         $i++;
         $payment_id = $row['payment_id'];
         $payslip_no = $row['payslip_no'];
         $payment_month = $row['payment_month'];
         $payment_date = $row['payment_date'];
         $basic_salary = $row['basic_salary'];
         $net_salary = $row['net_salary'];
         $payment_amount = $row['payment_amount'];
         $payment_type = $row['payment_type'];
         $employee_cpf = $row['employee_cpf'];
         $last_updated_by = $row['first_name']."".$row['last_name'];
         $gross_salary = $row['gross_salary'];
         $total_deduction = $row['total_deduction'];
echo<<<EOF
<tr>
    <td >$i</td>
    <td>$payslip_no</td>
    <td>$payment_month</td>
    <td>$payment_date</td>
    <td>$basic_salary</td>
    <td>$gross_salary</td>
    <td>$total_deduction</td>
    <td>$net_salary</td>
    <td>$payment_amount</td>
    <td>$payment_type</td>
    <td>$last_updated_by</td>
    <td> <a href="payslip.php?payment_id=$payment_id" data-original-title='View' class='btn btn-info btn-xs'  data-toggle='tooltip' data-placement='top' ><i class='fa fa-list-alt'></i> View</a></td>
    <td>
    <a href="make_payment.php?action=edit&employee_id=$this->employee_id&payment_id=$payment_id" data-original-title='Edit' class='btn btn-primary btn-xs' data-toggle='tooltip' data-placement='top' ><i class='fa fa-pencil-square-o'></i> Edit</a>
    <a data-original-title='Delete' class='btn btn-danger btn-xs' data-toggle='tooltip' data-placement='top' onclick="delete_payment($payment_id)"><i class='fa fa-trash-o'></i> Delete</a>
    </td>
</tr>
EOF;
        }
  }else{
    $_SESSION['msg']="<div class='alert alert-success'>
                      Cannot fetch data, please contact web master.
                      </div>";
 header("Location: make_payment.php?employee_id=$o->employee_id#payment_history",500);
          exit; 
  }
  }


  //Edit mode fetch data
  public function edit_fetch(){
    global $db;

     $sql = "SELECT payslip_no,payment_month,basic_salary,employee_cpf,employer_cpf,sdl_payable,net_salary,payment_amount,
    payment_type,payment_date,comments,
    employee_cpf_percent,employer_cpf_percent,
    ot_rate,hours_worken_week,ot_hours_worked,total_ot_pay
    FROM hrms_salary_payment
    WHERE payment_id = $this->payment_id";

  if ($query=mysqli_query($db,$sql)){
     if($row=mysqli_fetch_assoc($query)){

      $this->payment_month = $row['payment_month'];
      $this->basic_salary = $row['basic_salary'];
      $this->ot_rate = $row['ot_rate'];
      $this->hours_worken_week = $row['hours_worken_week'];
      $this->ot_hours_worked = $row['ot_hours_worked'];
      $this->employee_cpf = $row['employee_cpf'];
      $this->employer_cpf = $row['employer_cpf'];
      $this->sdl_payable = $row['sdl_payable'];
      $this->net_salary = $row['net_salary'];
      $this->payment_amount = $row['payment_amount'];
      $this->payment_type = $row['payment_type'];
      $this->payment_date = $row['payment_date'];
      $this->comments = $row['comments'];
      $this->employee_cpf_percent = $row['employee_cpf_percent'];
      $this->employer_cpf_percent = $row['employer_cpf_percent'];

      $this->overtime_rate = $row['ot_rate'];
      $this->hours_worken_week = $row['hours_worken_week'];
      $this->ot_hours_worked = $row['ot_hours_worked'];
      $this->total_ot_pay = $row['total_ot_pay'];

      }else{
          $_SESSION['msg']="<div class='alert alert-success'>
                      Cannot fetch 'edit_fetch' data, please contact web master.
                      </div>";
          header("Location: make_payment.php?employee_id=$this->employee_id#payment_history",500);
          exit; 
      }

  }else{
    $_SESSION['msg']="<div class='alert alert-success'>
                      Cannot fetch 'edit_fetch' data, please contact web master.
                      </div>";
          header("Location: make_payment.php?employee_id=$this->employee_id#payment_history",500);
          exit; 
    }
  }

  //Edit mode fetch dynamic Pay Item (CPF)
  public function additional_cpf_fetch(){
    global $db;
   $sql ="SELECT addition_item_id,item_remark,item_amount
   FROM hrms_salary_item
    WHERE payment_id = $this->payment_id AND isCPF = 1 AND isAdd = 1";
      if ($query=mysqli_query($db,$sql)){
          while ($row=mysqli_fetch_assoc($query)) {

            $addition_item_id = $row['addition_item_id'];
            $item_remark = $row['item_remark'];
            $item_amount = $row['item_amount'];
echo<<<EOF
        <div class="form-group">
        <div class="col-md-5 col-sm-5 col-xs-6">
        <input type="text" name="item_cpf_remark[]" class="form-control" placeholder="Enter Detail" required="required" value="$item_remark"></div>
        <div class="col-md-5 col-sm-5 col-xs-6">
        <input type="number" min="0" name="item_cpf_amount[]" class="form-control item_cpf" placeholder="Enter Amount" required="required" value="$item_amount"></div>
        <div class="col-sm-2">
        <strong><a href="javascript:void(0);" class="remItmCPF"> Remove</a></strong></div></div>
EOF;

  }}else{
    $_SESSION['msg']="<div class='alert alert-success'>
                      Cannot fetch 'additional_cpf_fetch' data, please contact web master.
                      </div>";
          header("Location: make_payment.php?employee_id=$this->employee_id#payment_history",500);
          exit; 
        }
  }

  //Edit mode fetch dynamic Pay Item (NON-CPF)
    public function additional_non_cpf_fetch(){
    global $db;
   $sql ="SELECT addition_item_id,item_remark,item_amount
   FROM hrms_salary_item
    WHERE payment_id = $this->payment_id AND isCPF = 0 AND isAdd = 1";
      if ($query=mysqli_query($db,$sql)){
          while ($row=mysqli_fetch_assoc($query)) {

            $addition_item_id = $row['addition_item_id'];
            $item_remark = $row['item_remark'];
            $item_amount = $row['item_amount'];
echo<<<EOF
        <div class="form-group">
        <div class="col-md-5 col-sm-5 col-xs-6">
        <input type="text" name="item_NON_cpf_remark[]" class="form-control" placeholder="Enter Detail" required="required" value="$item_remark"></div>
        <div class="col-md-5 col-sm-5 col-xs-6">
        <input type="number" min="0" name="item_NON_cpf_amount[]" class="form-control item_non_cpf" placeholder="Enter Amount" required="required" value="$item_amount"></div>
        <div class="col-sm-2">
         <strong><a href="javascript:void(0);" class="remItmNCPF">Remove</a></strong></div></div>
EOF;

  }}else{
    $_SESSION['msg']="<div class='alert alert-success'>
                      Cannot fetch 'additional_non_cpf_fetch' data, please contact web master.
                      </div>";
          header("Location: make_payment.php?employee_id=$this->employee_id#payment_history",500);
          exit; 
        }
  }

    //Edit mode fetch dynamic Deduction
    public function deduction_fetch(){
    global $db;
   $sql ="SELECT addition_item_id,item_remark,item_amount
   FROM hrms_salary_item
    WHERE payment_id = $this->payment_id AND isDeduc = 1";
      if ($query=mysqli_query($db,$sql)){
          while ($row=mysqli_fetch_assoc($query)) {

            $deduction_id = $row['addition_item_id'];
            $deduction_remark = $row['item_remark'];
            $deduction_amount = $row['item_amount'];
echo<<<EOF
    <div class="form-group">
    <div class="col-md-5 col-sm-5 col-xs-6">
    <input type="text" name="deduc_remark[]" class="form-control" placeholder="Enter Detail" required="required" value="$deduction_remark"></div>
    <div class="col-md-5 col-sm-5 col-xs-6">
    <input type="number" min="0" name="deduc_amount[]" class="form-control deduction" placeholder="Enter Amount" required="required" value="$deduction_amount"></div>
    <div class="col-sm-2">
    <strong><a href="javascript:void(0);" class="remDeduc"> Remove</a></strong></div></div>
EOF;

  }}else{
    $_SESSION['msg']="<div class='alert alert-success'>
                      Cannot fetch 'deduction_fetch' data, please contact web master.
                      </div>";
          header("Location: make_payment.php?employee_id=$this->employee_id#payment_history",500);
          exit; 
        }
  }
  public function update_payment(){
    global $db,$user_id;
      $timestamp= date("y/m/d H:i:s", time());
    $sql = "UPDATE hrms_salary_payment
    SET payment_month = '$this->payment_month',
        ot_hours_worked = '$this->ot_hours_worked',
        total_ot_pay = '$this->total_ot_pay',
        employee_cpf = '$this->employee_cpf',
        employer_cpf = '$this->employer_cpf',
        net_salary = '$this->net_salary',
        payment_amount = '$this->payment_amount',
        payment_type = '$this->payment_type',
        payment_date = '$this->payment_date',
        comments = '$this->comments',
        gross_salary = '$this->gross_salary',
        total_deduction = '$this->hidden_deduction',
        updated = '$timestamp',
        updatedby = '$user_id'
        WHERE payment_id = $this->payment_id";
    if(mysqli_query($db,$sql)) {
              $_SESSION['msg'] ="<div class='alert alert-success'>
           Payment Updated Successfully.
          </div>";
          return true;
        }else {
              $_SESSION['msg'] ="<div class='alert alert-info'>Cannot delete record.</div>";
               header("Location: make_payment.php?employee_id=$this->employee_id#payment_history");
        return false;
        }
  }

   public function delete_additional(){
    global $db,$user_id;

    $sql = "DELETE FROM hrms_salary_item WHERE payment_id = $this->payment_id";
        if(mysqli_query($db,$sql)) {
          return true;
        }else {
        return false;
        }
 }
     //delete designation 
   public function delete_payment(){
    global $db,$user_id;

    $sql = "DELETE FROM hrms_salary_payment WHERE payment_id = $this->payment_id";
        if(mysqli_query($db,$sql)) {
            $_SESSION['msg'] ="<div class='alert alert-success'>
           Payment Deleted Successfully.
          </div>";
          return true;
        }else {
           $_SESSION['msg'] ="<div class='alert alert-info'>Cannot delete Payment.</div>";
        return false;
        }
 }
}//END CLASS
