<?php 
class employee_list{

    public $department_id;

    public $action;
    public $msg;

//input form
	public function listform(){
global $selectcrtl;

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
                                    <h2>Employee List</h2>
                                    <div class="clearfix"></div>
                            </div>

                <div class='x_content'>
                        <table id="example" class="table table-bordered table-hover dt-responsive" cellspacing="0" width="100%">
                                        <thead>
                                            <tr>
                                                <th>#</th>
                                                <th>Employee ID </th>
                                                <th>Employee </th>
                                                <th>Dept.>Designation</th>
                                                <th>Mobile</th>
                                                <th>Status </th>
                                                <th>Action</th>
                                            </tr>
                                        </thead>
                                        <tbody>

           

EOF;
$this->fetch();
echo<<<EOF
     </div>
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

$warning_msg = "Are you want to deactive this employee?";
    $sql="SELECT employee_id,employment_id,first_name,last_name,mobile,status,DES.designations,DEP.department_name
    FROM hrms_employee EMP
    INNER JOIN hrms_designations DES ON DES.designations_id = EMP.designation_id
    INNER JOIN hrms_department DEP ON DEP.department_id = DES.department_id";
            $query=mysqli_query($db,$sql);

           $i=0;
            while ($row=mysqli_fetch_assoc($query)) {
                $i++;
                $employee_id = $row['employee_id'];
                $employment_id = $row['employment_id'];
                $first_name = $row['first_name'];
                $last_name = $row['last_name'];
                $mobile = $row['mobile'];
                $status = $row['status'];
                $designations = $row['designations'];
                $department_name = $row['department_name'];
                if ($status == 1) {
                $status =  '<span class="label label-success">Active</span>';
                 } else {
                 $status =  '<span class="label label-danger">Deactive</span>';
                }
              
echo<<<EOF
<form action='employee_list.php' method='post'>
    <tr>
    <td >$i</td>
    <td>$employment_id</td>
    <td>$last_name $first_name</td>
    <td>$department_name > $designations</td>
    <td>$mobile</td>
    <td>$status</td>
    <td>
    <a href="view_employee.php?employee_id=$employee_id" class="btn btn-info btn-xs" data-toggle="tooltip" data-placement="top" title="" data-original-title="View"><span class="fa fa-list-alt"></span> View</a>
    <a href="add_employee.php?action=edit&employee_id=$employee_id" data-original-title='Edit' class='btn btn-primary btn-xs'  data-toggle='tooltip' data-placement='top' ><i class='fa fa-pencil-square-o'></i> Edit</a>
    <a href="employee_list.php?action=deactive&employee_id=$employee_id" data-original-title='Deactive'  onclick="return confirm('$warning_msg')" class='btn btn-danger btn-xs' data-toggle='tooltip' data-placement='top' ><i class='fa fa-trash-o'></i>Deactive</a>
    </td>   
     </tr>
</form>
EOF;
 }
echo "</tbody></table>";
}

 public function deactive($employee_id){
  global $db,$user_id;
  $timestamp= date("y/m/d H:i:s", time());



  //else update
  $sql="UPDATE hrms_employee
      SET status=0,
      updated='$timestamp',updatedby='$user_id'
      WHERE employee_id = $employee_id ";

    if(mysqli_query($db,$sql)) {
           $_SESSION['msg']="<div class='alert alert-success'>
           Employee Successfully Deactive!
          </div>";
          return true;

        }else {
             $_SESSION['msg']="<div class='alert alert-info'>
           This employee cannot be deactive.
          </div>";
        header("Location: employee_list.php");
       return false;
    }

 }

}