<?php 
class application_list{
    public $msg;

	public function form(){
        if (!empty($_SESSION['msg'])) {
   $this->msg = $_SESSION['msg'];
}
echo<<<EOF
<div class="right_col" role="main">
    <div class="">
                <div class="row">
                    <div class="col-md-12 col-sm-12 col-xs-12">
                            <div id="msg">
                               $this->msg                         
                            </div>

                            <div class="x_title">
                                    <h2>List of All Applications</h2>
                                    <div class="clearfix"></div>
                            </div>

                <div class='x_content'>
                <form action='application_list.php' method='post'>
                        <table id="example" class="table table-bordered table-hover dt-responsive bulk_action" cellspacing="0" width="100%">
                                        <thead>
                                            <tr>
                                                <th>
                                                   <input type="checkbox" id="check-all" class="flat">
                                                </th>
                                                <th>#</th>
                                                <th>Employee ID </th>
                                                <th>Employee </th>
                                                <th>Dept.>Designation</th>
                                                <th>Leave Type</th>
                                                <th>Start Date</th>
                                                <th>End Date </th>
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
            </tbody></table>
            </form>
</div>


<script>
$('#check-all').click( function() {
  $('input:checkbox').prop('checked', this.checked);
} );
$(document).ready(function() {

    $('#example').DataTable( {
         responsive: true,
    } );
$('<button style="padding-left:10px;" type="submit" id="refresh">Mark as Past Year</button>').appendTo('div.dataTables_length');px;
} );


setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 3000); // <-- time in milliseconds
</script>
EOF;
$this->msg = null;
$_SESSION['msg'] = null;
	}

	public function get_all_leave_application(){
		global $db,$user_id;

		 $sql="SELECT application_list_id AS application_id,hrms_leave_category.category,leave_start_date, leave_end_date, reason, application_status, hrms_application_list.created AS applied_on, total_days,
         employment_id,concat(first_name,' ',last_name) AS name, concat(DEP.department_name,'.>',DES.designations) AS designation
         FROM hrms_application_list
         INNER JOIN hrms_leave_category ON hrms_leave_category.leave_category_id = hrms_application_list.leave_category_id
         INNER JOIN hrms_employee EMP ON EMP.employee_id = hrms_application_list.employee_id
         INNER JOIN hrms_designations DES ON DES.designations_id = EMP.designation_id
         INNER JOIN hrms_department DEP ON DEP.department_id = DES.department_id
         ORDER BY applied_on asc";

         $query=mysqli_query($db,$sql);
          $i=0;
            while ($row=mysqli_fetch_assoc($query)) {
                $i++;
                $application_id = $row['application_id'];

                $employment_id = $row['employment_id'];
                $employee_name = $row['name'];
                $designation = $row['designation'];
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
    <td class="a-center "><input type="checkbox" class="flat" name="mark_application_id[]" value="$application_id"></td>
    <td>$i</td>
    <td>$employment_id</td>
    <td>$employee_name</td>
    <td>$designation</td>

    <td>$category</td>
    <td>$leave_start_date</td>
    <td>$leave_end_date</td>
    <td>$total_days</td>

    <td>$reason</td>
    <td>$applied_on</td>
    <td>$application_status</td>
    <td> <a href="view_application.php?application_id=$application_id" data-original-title='Action' class='btn btn-info btn-xs' data-toggle='tooltip' data-placement='top' ><i class='fa fa-list-alt'></i> View</a></td>                                                                    
</tr>
EOF;
}
	}
}//END CLASS