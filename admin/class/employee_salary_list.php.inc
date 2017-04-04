<?php 
class employee_salary_list{

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
                                                <th>Employee ID </th>
                                                <th>Full Name </th>
                                                <th>Dept.>Designation</th>
                                                <th>Gross Salary</th>
                                                <th>Deduction </th>
                                                <th>Net Salary </th>
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

    $sql="SELECT EMP.employee_id, employment_id, first_name, last_name, DES.designations, department_name ,basic_salary, employee_cpf_percent, employer_cpf_percent
            FROM hrms_employee EMP
            INNER JOIN  hrms_designations DES ON DES.designations_id = EMP.designation_id
            INNER JOIN  hrms_department DEP ON DEP.department_id = DES.department_id
            LEFT JOIN  hrms_employee_payroll PAY ON PAY.employee_id = EMP.employee_id WHERE status = 1 ";

            $query=mysqli_query($db,$sql);

           $i=0;
            while ($row=mysqli_fetch_assoc($query)) {
                $i++;
                $employee_id = $row['employee_id'];
                $employment_id = $row['employment_id'];
                $first_name = $row['first_name'];
                $last_name = $row['last_name'];

                $designations = $row['designations'];
                $department_name = $row['department_name'];

                $basic_salary = $row['basic_salary'];
                $employee_cpf_percent = $row['employee_cpf_percent'];
                $employer_cpf_percent = $row['employer_cpf_percent'];

                     //GROSS SALARY (BASIC SALARY + ALLOWANCES)

            //EMPLOYEE CPF
            $employee_cpf = $basic_salary * $employee_cpf_percent /100;

            //NET SALARY (GROSS SALARY - TOTAL DEDUCTION)
            $net_salary = $basic_salary - $employee_cpf;
              
echo<<<EOF
<form action='employee_list.php' method='post'>
    <tr>
    <td >$i</td>
    <td>$employment_id</td>
    <td>$last_name $first_name</td>
    <td>$department_name > $designations</td>
    <td>$basic_salary</td>
    <td>$employee_cpf</td>
    <td>$net_salary</td>
    <td >
    <a href="add_employee.php?action=edit&employee_id=$employee_id#manage_salary" data-original-title='Edit' class='btn btn-primary btn-xs'  data-toggle='tooltip' data-placement='top' '><i class='fa fa-pencil-square-o'></i> Edit</a>

    <a href="make_payment.php?employee_id=$employee_id" data-original-title='Make Payment' class='btn btn-success btn-xs'  data-toggle='tooltip' data-placement='top'><i class='fa fa-tasks'></i> Make Payment</a>
     </tr>
</form>
EOF;
 }
echo "</tbody></table></div>";
}

}//END CLASS