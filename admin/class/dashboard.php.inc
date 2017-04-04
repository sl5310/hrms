<?php 
class dashboard{
    public $msg;
    public $total_employee;
    public $total_department;
	public function form(){
        if (!empty($_SESSION['msg'])) {
   $this->msg = $_SESSION['msg'];
}
$month = date("F");
echo<<<EOF
<div class="right_col" role="main">
    <div class="">
        <div class="row">
            <div class="col-sm-12">
                <h3>Dashboard</h3>
                    <div class="ln_solid"></div>

                    <div class="row top_tiles">
                        <div class="animated flipInY col-lg-3 col-md-3 col-sm-6 col-xs-12">
                            <div class="tile-stats">
                                <div class="icon"><i class="fa fa-pie-chart"></i>
                                </div>
                                <div class="count">$this->total_department</div>
                                <h3>Total Department</h3>
                                <p></p>
                            </div>
                        </div>
                        <div class="animated flipInY col-lg-3 col-md-3 col-sm-6 col-xs-12">
                            <div class="tile-stats">
                                <div class="icon"><i class="fa fa-users"></i>
                                </div>
                                <div class="count">$this->total_employee</div>
                                <h3>Total Employee</h3>
                                <p></p>
                            </div>
                        </div>
                    </div> 
            </div>  

        <div class="col-sm-7 col-xs-12">    
                <div class="wrap-fpanel margin">                           

                        <div class="x_title">
                            <h2><i class="fa fa-bell-o"></i> Notice Board</h2>
                            <div class="pull-right"><a href="manage_notice.php" style='color:white;'>View All</a></div>
                            <div class="clearfix"></div>
                        </div> 
                                      
                        <div class='x_content appls-scroll'>
EOF;
$this->notice();
echo<<<EOF
                        </div>
                </div>
<div class="clearfix"></div>
                <div class="wrap-fpanel margin">                           

                        <div class="x_title">
                            <h2><i class="fa fa-rocket"></i> Applications Pending Approval</h2>
                            <div class="pull-right"><a href="application_list.php" style='color:white;'>View All</a></div>
                            <div class="clearfix"></div>
                        </div> 

                <div class='x_content appls-scroll'>
EOF;
$this->application();
echo<<<EOF
                        </div>
                </div>
            </div> 

         <div class="col-sm-5 col-xs-12">        
                <div class="wrap-fpanel margin">                           

                        <div class="x_title">
                            <h2><i class="fa fa-binoculars"></i> Holidays</h2>
                            <div class="pull-right"><a href="set_holidays.php" style='color:white;'>View All</a></div>
                            <div class="clearfix"></div>
                        </div> 
                                      
                        <div class='x_content bithday'>
EOF;
$this->holiday();
echo<<<EOF
                        </div>
                </div>
<div class="clearfix"></div>
                <div class="wrap-fpanel margin">                           

                        <div class="x_title">
                            <h2><i class="fa fa-birthday-cake"></i> Upcomming Birhday - $month</h2>
                            <div class="clearfix"></div>
                        </div> 

                        <div class='x_content bithday'>
EOF;
$this->birthday();
echo<<<EOF
                        </div>
                </div>
            </div>
EOF;
$this->msg = null;
$_SESSION['msg'] = null;
	}

    public function countEmployee(){
        global $db;
        $sql = "SELECT COUNT(*) as total_employee FROM hrms_employee WHERE status = 1";
        $query = mysqli_query($db,$sql);
        $row = mysqli_fetch_assoc($query);
        $this->total_employee = $row['total_employee'];
    }
    public function countDepartment(){
        global $db;
        $sql = "SELECT COUNT(*) as total_department FROM hrms_department";
        $query = mysqli_query($db,$sql);
        $row = mysqli_fetch_assoc($query);
        $this->total_department = $row['total_department'];
    }
    public function notice(){
        global $db;

        $sql = "SELECT notice_id,title,short_description,updated
        FROM hrms_notice
        WHERE flag = 1";
        $query=mysqli_query($db,$sql);
    if (mysqli_num_rows($query)>0){
        while ($row=mysqli_fetch_assoc($query)){

            $notice_id = $row['notice_id'];
            $title = $row['title'];
            $short_description = $row['short_description'];
            $updated = $row['updated'];
            $str = strlen($short_description);
            if ($str > 90) {
                $ss = '<strong> ......</strong>';
            } else {
                $ss = '&nbsp';
             } $short_description = substr($short_description, 0, 90) . $ss;
             $month = date('M', strtotime($updated));
             $day = date('d', strtotime($updated));
echo <<< EOF
            <div class="notice-calendar-list clearfix">
                    <div class="notice-calendar">
                        <span class="month">$month</span>
                        <span class="date">$day</span>
                    </div>
                    <div class="notice-calendar-heading">
                         <h5 class="notice-calendar-heading-title">
                            <a href="view_notice.php?notice_id=$notice_id">$title</a>                        
                        </h5>
                        <div class="notice-calendar-date">
                            $short_description
                        </div>
                    </div>
                    <div style="margin-top: 5px; padding-top: 5px; padding-bottom: 10px;">
                        <span style="font-size: 10px;" class="pull-right">
                           <strong><a href="view_notice.php?notice_id=$notice_id" style="color: #004884;">View Details</a></strong>
                        </span>
                     </div>
            </div>
EOF;
        }
    }else{
        echo "<h5 class='notice-calendar-heading-title'>No Notice To Show.</h5>";
    }
}
    public function holiday(){
        global $db;

        $sql = "SELECT holiday_id,event_name,event_date
        FROM hrms_holiday
        ORDER BY event_date";
        $query=mysqli_query($db,$sql);
        if (mysqli_num_rows($query)>0){
        while ($row=mysqli_fetch_assoc($query)){
            $holiday_id = $row['holiday_id'];
            $event_name = $row['event_name'];
            $event_date = $row['event_date'];
             $month = date('M', strtotime($event_date));
             $day = date('d', strtotime($event_date));
echo <<< EOF
<div class="notice-calendar-list clearfix">
                                    <div class="notice-calendar">
                                        <span class="month">$month</span>
                                        <span class="date">$day</span>
                                    </div>

                                    <div class="notice-calendar-heading">
                                        <h5 class="notice-calendar-heading-title">
                                            <a href="set_holidays.php">$event_name</a>                        
                                        </h5>
                                    </div>
                                    <div style="margin-top: 5px; padding-top: 5px; padding-bottom: 10px;">
                                        <span style="font-size: 10px;" class="pull-right">
                                            <strong><a href="set_holidays.php" style="color: #004884;">View Details</a></strong>
                                        </span>
                                    </div>
                                </div>
EOF;
        }
    }else{
         echo "<h5 class='notice-calendar-heading-title'>You have not setting the Holiday yet.</h5>";
    }
}

    public function application(){
        global $db,$up_path,$employee_logo;
        $query = mysqli_query($db,"SELECT application_list_id as application_id, CONCAT(EMP.first_name,' ',EMP.last_name) as name, reason, APP.created,photo,
                total_days,category
        FROM hrms_application_list APP
        INNER JOIN hrms_employee EMP ON APP.employee_id = EMP.employee_id
        INNER JOIN hrms_leave_category CAT ON APP.leave_category_id = CAT.leave_category_id
        WHERE application_status = 1");
    if (mysqli_num_rows($query)>0){
   while($row=mysqli_fetch_assoc($query)){
    $name = $row['name'];
    $reason = $row['reason'];
    $created = $row['created'];
    $application_id = $row['application_id'];
    $photo = $row['photo'];
    $total_days = $row['total_days'];
    $category = $row['category'];

     $str = strlen($reason);
            if ($str > 40) {
                $ss = '<strong>......</strong>';
            } else {
                $ss = '&nbsp';
             } $reason = substr($reason, 0, 40) . $ss;

 //$oldTime = date('h:i:s', strtotime($v_inbox_msg->send_time));
 // Past time as MySQL DATETIME value
 $oldtime = date('Y-m-d H:i:s', strtotime($created));

// Current time as MySQL DATETIME value
$csqltime = date('Y-m-d H:i:s');
// Current time as Unix timestamp
$ptime = strtotime($oldtime);
$ctime = strtotime($csqltime);

//Now calc the difference between the two
$timeDiff = floor(abs($ctime - $ptime) / 60);

//Now we need find out whether or not the time difference needs to be in
 //minutes, hours, or days
if ($timeDiff < 2) {
    $timeDiff = "Just now";
} elseif ($timeDiff > 2 && $timeDiff < 60) {
    $timeDiff = floor(abs($timeDiff)) . " minutes ago";
} elseif ($timeDiff > 60 && $timeDiff < 120) {
    $timeDiff = floor(abs($timeDiff / 60)) . " hour ago";
} elseif ($timeDiff < 1440) {
    $timeDiff = floor(abs($timeDiff / 60)) . " hours ago";
} elseif ($timeDiff > 1440 && $timeDiff < 2880) {
     $timeDiff = floor(abs($timeDiff / 1440)) . " day ago";
} elseif ($timeDiff > 2880) {
    $timeDiff = floor(abs($timeDiff / 1440)) . " days ago";
}
 if ($photo ==""){
    $photo = $employee_logo;
 }
echo<<<EOF
<div class="notice-calendar-list clearfix">

        <div class="pull-left">
        <img class="img-profile" src="$up_path/photo/$photo">
        </div>
        <div class="notice-calendar-heading">
                <h5 class="notice-calendar-heading-title">
                <a href="view_application.php?application_id=$application_id"><span>$name</span>
                <small style="font-style: italic;">$timeDiff</small></a>
            </h5>
            <div class="notice-calendar-date">
                $reason <br>Leave requested $total_days days ($category)
            </div>
        </div>
        <div style="margin-top: 5px; padding-top: 5px; padding-bottom: 10px;">
            <span style="font-size: 10px;" class="pull-right">
                <strong><a href="view_application.php?application_id=$application_id" style="color: #004884;">View Details</a></strong>
            </span>
            </div>
</div>
EOF;
    }
}else{
    echo "<h5 class='notice-calendar-heading-title'> No application is pending approval.</h5>";
}
    }
    public function birthday(){
        global $db;
        $m = date("m");
        $sql = "SELECT date_of_birth, CONCAT(first_name,' ',last_name) as name, employee_id
                FROM hrms_employee
                WHERE MONTH(date_of_birth) = $m";

        $query=mysqli_query($db,$sql);
        if (mysqli_num_rows($query)>0){
        while ($row=mysqli_fetch_assoc($query)){
            $employee_id = $row['employee_id'];
            $name = $row['name'];
            $date_of_birth = $row['date_of_birth'];
             $month = date('M', strtotime($date_of_birth));
             $day = date('d', strtotime($date_of_birth));
echo <<< EOF
<div class="notice-calendar-list clearfix">
                                    <div class="notice-calendar">
                                        <span class="month">$month</span>
                                        <span class="date">$day</span>
                                    </div>

                                    <div class="notice-calendar-heading">
                                        <h5 class="notice-calendar-heading-title">
                                            <a href="set_holidays.php">$name</a>                        
                                        </h5>
                                    </div>
                                    <div style="margin-top: 5px; padding-top: 5px; padding-bottom: 10px;">
                                        <span style="font-size: 10px;" class="pull-right">
                                            <strong><a href="set_holidays.php" style="color: #004884;">View Details</a></strong>
                                        </span>
                                    </div>
                                </div>
EOF;
        }
    }else{
         echo "<h5 class='notice-calendar-heading-title'>Nobody Birthday On This Month.</h5>";
    }
}
}//END CLASS