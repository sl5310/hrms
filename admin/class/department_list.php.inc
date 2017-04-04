<?php 
class department_list{

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

       <script type="text/javascript">

setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 1500); // <-- time in milliseconds

        </script>

<div class="right_col" role="main">
<div class="">
        <div class="row">
            <div class="col-md-12 col-sm-12 col-xs-12">
              <h4><a href="add_department.php"><i class="fa fa-plus"></i> Add Department</a></h4>
                            <div id="msg">
                               $this->msg                         
                            </div>

                                <div class="x_title">
                                    <h2>Department List</h2>
                                    <div class="clearfix"></div>
                                </div>

                <div class='x_content'>
EOF;
$this->fetch();
echo<<<EOF
              
            </div>
EOF;

$this->msg = null;
$_SESSION['msg'] = null;

	}

    public function fetch(){
        global $db;

    $sql="SELECT * from hrms_department";
            $query=mysqli_query($db,$sql);

        // if no data to show
         if (mysqli_num_rows($query) == 0) {
             echo "<h2>No data to show.</h2>";
           }

        
$warning_msg="You are about to delete This Department. All Designation Under This Department Will Be Deleted. Are you sure?";
           // select from department
        while ($row=mysqli_fetch_assoc($query)) {

            $no = 0;
            $department_id=$row['department_id'];
            $department_name=$row['department_name'];
            $department_code=$row['department_code'];
echo<<<EOF
    <table class='table table-hover'><thead><tr class='headings'>
        <th class='col-md-2'>$department_name - $department_code </th>
            <th>
<div class='pull-right'><a href="department_list.php?action=delete&department_id=$department_id" data-original-title='Delete' class='btn btn-danger btn-xs' data-toggle='tooltip' data-placement='top' onclick="return confirm('$warning_msg')" ><i class='fa fa-trash-o'></i>Delete</a></div>

            <div class='pull-right'><a href="add_department.php?action=edit&department_id=$department_id" data-original-title='Edit' class='btn btn-primary btn-xs'  data-toggle='tooltip' data-placement='top'><i class='fa fa-pencil-square-o'></i>Edit</a></div>


            </th>
        </tr></thead><tbody>

EOF;
                $sql_desination = "SELECT * from hrms_designations WHERE department_id = $department_id";
                                $query_desination=mysqli_query($db,$sql_desination);

                            // select from designations 
                            while ($row_desination=mysqli_fetch_assoc($query_desination)) {
                                $no++;
                                $designations = $row_desination['designations'];
echo "<tr class='even pointer'><tr class='even pointer'><td>$no</td>";
echo "<td>$designations</td></tr>";
                            }
                        echo "</tbody></table>";


        }
                       
    }
//check department in used
 public function checkDel(){
    global $db,$user_id;

    $sql = "SELECT designations_id FROM hrms_employee EMP
    INNER JOIN hrms_designations DES ON DES.designations_id = EMP.designation_id 
    WHERE department_id = $this->department_id";
    $query=mysqli_query($db,$sql);

        // if no data to show
        if (mysqli_num_rows($query) == 0) {
            return true;
        }else{

             $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
          Failed to Delete Department due to Department already in used.</span>
          </div>";
          return false;
        }

 }

//delete department
 public function delete(){
    global $db,$user_id;

     $sql = "DELETE FROM hrms_department WHERE department_id = $this->department_id";
        if(mysqli_query($db,$sql)) {
              $_SESSION['msg'] ="<div class='alert alert-success'>
          Department deleted successfully.
          </div>";
          return true;
        }else {
              $_SESSION['msg'] ="<div class='alert alert-info'><span class='text-danger'>
              Failed to Delete Department, please contact webmaster.</span></div>";
        return true;
        }
 }


}
 ?>          