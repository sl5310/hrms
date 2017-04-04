<?php 
class leave_application{
    public $msg;
	public function form(){

         if (!empty($_SESSION['msg'])) {
   $this->msg = $_SESSION['msg'];
    }
echo<<<EOF
    <div class="container">
        <div class="row">
            <div class="margin">    
                <div class="col-md-12">
                    <div class="main_content">
                        <div class="row">
    <div id="msg">
    $this->msg                         
   </div>
<div class="col-md-12">
<h4><a href="apply_leave_application.php"><i class="fa fa-plus"></i> Apply New Leave Application</a></h4>
    <br/>
    <div class="row">
        <div class="col-sm-12" data-offset="0">                            
            <div class="panel panel-info">
                <!-- Default panel contents -->

                <div class="panel-heading">
                    <div class="panel-title">                 
                        <strong>Leave Applications You Applied</strong>
                    </div>
                </div>
                <div class="panel-body ">
                <!-- Table -->
                <table id="example" class="table table-bordered table-hover dt-responsive" cellspacing="0" width="100%">
                    <thead>
                        <tr>                                                   
                            <th class="col-sm-1">#</th>
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
            </div>
        </div>
    </div>        
</div>
					</div>
        		</div>
	        </div>
        </div>
    </div>        
</div>
<script>
    $(document).ready(function() {
          $('#example').dataTable();
    });
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

		 $sql="SELECT application_list_id AS application_id,hrms_leave_category.category,leave_start_date, leave_end_date, reason, application_status, hrms_application_list.created AS applied_on,total_days
         FROM hrms_application_list
         INNER JOIN hrms_leave_category ON hrms_leave_category.leave_category_id = hrms_application_list.leave_category_id
         WHERE employee_id = $user_id
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
    

    <td><a href="apply_leave_application.php?action=view&application_id=$application_id" data-original-title='View' class='btn btn-info btn-xs' data-toggle='tooltip' data-placement='top' ><i class='fa fa-list-alt'></i> View</a></td>                                                                                                     
</tr>
EOF;
}
	}
}//END CLASS