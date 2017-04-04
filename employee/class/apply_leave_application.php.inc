<?php 

class apply_leave_application{

  public $application_id;
	public $leave_category_id;
	public $start_date;
	public $end_date;
	public $reason;
	public $msg;
  public $days;
  public $application_status;

	public function inputform($type){
		global $selectcrtl,$user_id;
        $leave_category = $selectcrtl->getSelectEmployeeLeave($this->leave_category_id,'Y');
    if (!empty($_SESSION['msg'])) {
   $this->msg = $_SESSION['msg'];
    }

    if($type=="new"){
      $btnsave = "<button type='submit' id='sbtn' name='sbtn' class='btn btn-primary'>Submit</button>
               <input type='hidden' value='save' name='action'>";
      $lblstatus = "";
      $application_status = "";
      $hidden = "";
      $btndelete = "";
    }else{

      //if application status is pending, user still can edit the detail of the leave application
      if ($this->application_status == 1){
       $btnsave = "<button type='submit' class='btn btn-primary'>Submit</button>
               <input type='hidden' value='update' name='action'>";
        $btndelete = "<button type='submit'' class='btn btn-danger' onclick='return confirm(\"Are you sure want to delete this Leave Application?\")'>Delete</button>
               <input type='hidden' value='delete' name='action'>";
      }else{
         $btnsave = "";
      }

      $lblstatus = "<label for='field-1' class='col-sm-3 control-label'>Status</label>";

      if ($this->application_status == 1) {
        $application_status = '<span class="label label-info">Pending</span>';
      } elseif ($this->application_status == 2) {
         $application_status = '<span class="label label-success">Accepted</span>';
       } else {
        $application_status = '<span class="label label-danger">Rejected</span>';
      }
      $hidden = "<input type='hidden' value='$this->application_id' name='application_id'>";
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
    <br/>
    <div class="row">
        <div class="col-sm-12" data-offset="0">                            
            <div class="panel panel-info">
                <!-- Default panel contents -->

                <div class="panel-heading">
                    <div class="panel-title">                 
                        <strong>Leave Usage</strong><span class="pull-right"><a onclick="history.go(-1);" class="view-all-front">Go Back</a></span>
                    </div>
                </div>
                <!-- Table -->
                <table class="table table-bordered table-hover" id="example">

                    <thead>
                        <tr>                                                   
                            <th class="col-sm-1">#</th>
                            <th>Leave Category</th>
                            <th>Days of Leave</th>
                            <th>Taken Days</th>
                            <th>Remaining Days</th>
                        </tr>
                    </thead>
                    <tbody>
EOF;
$this->fetch_leave();
echo<<<EOF
                  

                    </tbody>
                </table>          
            </div>
        </div>
    </div>        
</div>

<div class="col-md-12">
    <div class="row">
        <div class="col-sm-12">
            <div class="wrap-fpanel">
                <div class="panel panel-info" data-collapsed="0">
                    <div class="panel-heading">
                        <div class="panel-title">
                            <strong>Add New Leave Application</strong>
                        </div>
                    </div>
                    <div class="panel-body">
                        <div class="col-md-offset-1">
                            <form id="form" action="apply_leave_application.php" method="post"  enctype="multipart/form-data" class="form-horizontal">
                                <div class="panel_controls">
                                    <div class="form-group">
                                        <label for="field-1" class="col-sm-3 control-label">Leave Category<span class="required"> *</span></label>

                                        <div class="col-sm-5">
                                            <select name="leave_category_id" class="form-control" required >
                                             $leave_category
                                            </select>
                                        </div>
                                    </div>

                                    <div class="form-group">
                                        <label class="col-sm-3 control-label">Start Date <span class="required"> *</span></label>

                                   
                                        <div class="col-md-5 col-sm-5 col-xs-12">
                                         <input type="text" class="form-control datepicker" id="start_date" name="start_date" placeholder="yyyy-mm-dd" value="$this->start_date"> 
                                        </div>
                                    </div> 
                                    <div class="form-group">
                                        <label class="col-sm-3 control-label">End Date <span class="required"> *</span></label>

              							<div class="col-md-5 col-sm-5 col-xs-12">
                                         <input type="text" class="form-control datepicker" id="end_date" name="end_date" onchange="getWorkingDays()" placeholder="yyyy-mm-dd" value="$this->end_date"> 
                                         </div>
                                    </div> 

                                    <div class="form-group">
                                        <label for="field-1" class="col-sm-3 control-label">Leave Requested Day(s) </label>
                                        <div class="col-md-5 col-sm-5 col-xs-12">
                                        <label for="field-1" class="control-label" id="days">$this->days</label>
                                        </div>
                                    </div>

                                    <div class="form-group">
                                        <label for="field-1" class="col-sm-3 control-label">Reason<span class="required"> *</span></label>

                                        <div class="col-sm-5">
                                            <textarea id="present" name="reason" class="form-control" rows="6" required>$this->reason</textarea>
                                        </div>
                                    </div>

                                    <div class="form-group">
                                        $lblstatus
                                        <div class="col-md-5 col-sm-5 col-xs-12">
                                        <label for="field-1" class="control-label">$application_status</label>
                                        </div>
                                    </div>


                                    <div class="form-group">
                                        <div class="col-sm-offset-3 col-sm-5">

                                        <table style="width:150px;"><tbody><tr><td>
                                        $btnsave
                                        $hidden
                                          </form><td>

                                      <form action="apply_leave_application.php" method="post"  enctype="multipart/form-data" class="form-horizontal">
                                            $btndelete
                                            $hidden
                                      </form>
                                      </td></tr></tbody></table>
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
        		</div>
	        </div>
        </div>
    </div>        
</div>

<script>
$(function() {
   $('#end_date').datepicker({
      format: 'yyyy-mm-dd',
      autoclose: true,
      orientation: "top auto"
    });
   $('#start_date').datepicker({
      format: 'yyyy-mm-dd',
      autoclose: true,
      orientation: "top auto"
    });
});


function getWorkingDays(){

		var start_date = $('#start_date').val();
		var end_date = $('#end_date').val();

     var data="action=countLeaveDays&start_date="+start_date+"&end_date="+end_date;
     $.ajax({url: "apply_leave_application.php", type: "POST", data: data, success: function (xml) {

      }
   });

}

setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 3000); // <-- time in milliseconds
</script>
EOF;
$this->msg = null;
$_SESSION['msg'] = null;
	}
	    //FETCH EMPLOYEE LEAVE
    public function fetch_leave(){
 global $db,$user_id;

    $sql="SELECT employee_leave_id, days_of_leave, LCAT.category,EMP.leave_category_id
    FROM hrms_employee_leave EMP
    INNER JOIN hrms_leave_category LCAT ON LCAT.leave_category_id = EMP.leave_category_id
    WHERE EMP.employee_id = $user_id";
            $query=mysqli_query($db,$sql);

           
           $i=0;
            while ($row=mysqli_fetch_assoc($query)) {
                $total_days=0;
                $i++;
                $leave_category_id = $row['leave_category_id'];
                $employee_leave_id = $row['employee_leave_id'];
                $category = $row['category'];
                $days_of_leave = $row['days_of_leave'];
              

                $sql_count = "SELECT total_days FROM hrms_application_list WHERE employee_id = $user_id AND leave_category_id = $leave_category_id AND application_status !=3";
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
     </tr>
EOF;
	 }
	}

public function countLeaveDays($start_date,$end_date){
 $begin=strtotime($start_date);
 $end=strtotime($end_date);
 if($begin > $end){
 $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
 Failed to Apply Leave due to Start Date is bigger than End Date.</span></div>";
 header("Location: apply_leave_application.php",500);
exit;
 }

 $off_days = $this->getWorkingDays();

   $no_days=0;
   $weekends=0;
  while($begin<=$end){

    $no_days++; // no of days in the given interval
    $what_day=date("N",$begin);

     foreach ($off_days as $key=>$value ) {
     	$offdays = implode($off_days[$key]);
     if($what_day==$offdays) { // 6 and 7 are weekend days
          $weekends++;
     };
	 }

    $begin+=86400; // +1 day

  };
  $working_days=$no_days-$weekends;
  return $working_days;
 }

public function getWorkingDays(){
	global $db;

	$sql = "SELECT day_id FROM hrms_working_days WHERE flag = 0";
	 $query=mysqli_query($db,$sql);
		while ($row=mysqli_fetch_assoc($query)) {
			$off_days[] = $row;
         }
    return $off_days;
}
	//Apply Leave
public function save(){
		global $db,$user_id;
	$timestamp= date("y/m/d H:i:s", time());
    $total_days = $this->countLeaveDays($this->start_date,$this->end_date);
      //else save
       $sql = sprintf("INSERT INTO `hrms_application_list`
                (`employee_id`,`leave_category_id`,`reason`,`leave_start_date`,`leave_end_date`,`total_days`,
                	`application_status`,
                `created`,`createdby`,`updated`,`updatedby`) 
                VALUES 
                ('%d','%d','%s','%s','%s','%d',
                '%d',
                '%s','%d','%s','%d');"
                ,$user_id,$this->leave_category_id,$this->reason,$this->start_date,$this->end_date,$total_days,
                1,
                $timestamp,$user_id,$timestamp,$user_id);
      	if(mysqli_query($db,$sql)) {
              $_SESSION['msg']="<div class='alert alert-success'>
                 					Leave Applied Successfully!
                					</div>";
             return true;
          }else{
              $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>Invalid action was made.</span></div>";
          
           return false;
       	}
}

//when action = view
public function fetch(){
  global $db,$user_id;

  $sql= "SELECT *
  FROM hrms_application_list
  WHERE application_list_id = $this->application_id AND employee_id = $user_id";
   if($query=mysqli_query($db,$sql)){
    $row=mysqli_fetch_assoc($query);
    $this->leave_category_id = $row['leave_category_id'];
    $this->reason = $row['reason'];
    $this->start_date = $row['leave_start_date'];
    $this->end_date = $row['leave_end_date'];
    $this->days = $row['total_days'];
    $this->application_status = $row['application_status'];
   }
}

  public function update(){
    global $db,$user_id;

      $timestamp= date("y/m/d H:i:s", time());
      $total_days = $this->countLeaveDays($this->start_date,$this->end_date);
      $sql = "UPDATE hrms_application_list
      SET leave_category_id = '$this->leave_category_id',
      reason = '$this->reason',
      leave_start_date = '$this->start_date',
      leave_end_date = '$this->end_date',
      total_days = '$total_days',
      updated = '$timestamp',
      updatedby = '$user_id'
      WHERE application_list_id = $this->application_id";
      if(mysqli_query($db,$sql)) {
           $_SESSION['msg']="<div class='alert alert-success'>
           Leave Application Successfully Updated!
          </div>";
          return true;

        }else {
             $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
           Cannot Update Leave Application, please contact webmaster.</span>
          </div>";
        header("Location: manage_notice.php");
       return false;
      }
  }

  //delete leave application
 public function delete(){
    global $db,$user_id;

     $sql = "DELETE FROM hrms_application_list WHERE application_list_id = $this->application_id";
        if(mysqli_query($db,$sql)) {
              $_SESSION['msg'] ="<div class='alert alert-success'>
           Leave Application Successfully Deleted!
          </div>";
          return true;
        }else {
              $_SESSION['msg'] ="<div class='alert alert-info'><span class='text-danger'>
              Cannot delete Leave Application, please contact webmaster.</span></div>";
        return true;
        }
 }
}//END CLASS