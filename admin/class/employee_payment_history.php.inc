<?php 
class employee_payment_history{

    public $action;
    public $msg;

//input form
	public function listform(){

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

                            <div class="x_title">
                                    <h2>List of Employees and Their Salaries</h2>
                                    <div class='pull-right'>
                                     <a href="add_employee.php" data-original-title='Add Employee' class='btn btn-success btn-xs'  data-toggle='tooltip' data-placement='top' data-original-title='Add Employee'><i class='fa fa-plus'></i> New Employee</a>
                                    </div>
                                    <div class="clearfix"></div>
                            </div>
            
                <div class='x_content'>

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
echo<<<EOF

    </div>

 <script>
$('#example').DataTable( {
    responsive: true
} );     
setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 3000); // <-- time in milliseconds

        </script>
EOF;

$this->msg = null;
$_SESSION['msg'] = null;

	}
      public function fetch(){
 global $db;

   $sql = "SELECT * ,hrms_admin.first_name, hrms_admin.last_name 
    FROM hrms_salary_payment
    INNER JOIN hrms_payment_type ON hrms_payment_type.payment_type_id = hrms_salary_payment.payment_type
    INNER JOIN hrms_admin ON hrms_admin.user_id = hrms_salary_payment.updatedby
    ORDER BY payment_id ASC";
         
    if ($query=mysqli_query($db,$sql)){
         $i=0;
         while ($row=mysqli_fetch_assoc($query)) {
         $i++;
         $employee_id = $row['employee_id'];
         $payment_id = $row['payment_id'];
         $payslip_no = $row['payslip_no'];
         $payment_month = $row['payment_month'];
         $payment_date = $row['payment_date'];
         $basic_salary = $row['basic_salary'];
         $net_salary = $row['net_salary'];
         $payment_amount = $row['payment_amount'];
         $payment_type = $row['payment_type'];
         $employee_cpf = $row['employee_cpf'];
         $last_updated_by = $row['first_name']." ".$row['last_name'];
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
    <td><a href="payslip.php?payment_id=$payment_id" data-original-title='View' class='btn btn-info btn-xs'  data-toggle='tooltip' data-placement='top' ><i class='fa fa-list-alt'></i> View</a></td>
    <td>
    <a href="make_payment.php?action=edit&employee_id=$employee_id&payment_id=$payment_id" data-original-title='Edit' class='btn btn-primary btn-xs' data-toggle='tooltip' data-placement='top' ><i class='fa fa-pencil-square-o'></i> Edit</a>
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
echo "</tbody></table></div></div>";
  }
}//END CLASS