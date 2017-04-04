<?php

class dashboard{
		public $employment_id;
		public $name;
		public $photo;
		public $father_name;
		public $date_of_birth;
		public $gender;
		public $email;
		public $phone;
		public $mobile;
		public $address;
		public $position;

	public function form(){
		global $up_path,$user_id;
echo<<<EOF
    <div class="container">
        <div class="row">
            <div class="margin">    
                <div class="col-md-12">
                    <div class="main_content">
                        <div class="row">
							 <div class="col-md-12">
							    <div class="main_content">
							        <div class="row">
							            <div class="col-md-12">
                        <!-- START General Information -->
                            <div class="col-md-3">
				                    <div class="panel panel-info" style="border: 1px solid #004884 ">
				                        <div class="panel-body">
				                                <img src="$up_path/photo/$this->photo" style="height: 200px; width: 210px;"  class="img-responsive center-block" />
				                  
				                        </div>
				                        <div style="border-top: 1px solid #004884 ">
				                            <h3 class="text-center">$this->name</h3>
				                            <h6 class="text-center">Employee ID: $this->employment_id</h6>
				                            <h6 class="text-center">$this->position</h6>
				                            <p></p>
				                        </div>
				                    </div>
				            </div>
				            <!-- END General Information -->

				   <!-- START Personal Details -->
				  <div class="col-md-5">
                    <div class="panel panel-info">
                        <div class="panel-heading">
                            <h2 class="panel-title "><i class="fa fa-user"></i> <strong>Personal Details </strong><span class="pull-right">
                            <a href="profile.php?user_id=$user_id" class="view-all-front">View Profile</a></span></h2>
                        </div>
                        <div class="panel-body">
                        <div class="table-responsive">
                            <table class="table table-hover">
                                <tbody>
                                    <tr>
                                        <td>
                                            <span class="primary-link">Name</span>
                                        </td>
                                        <td>
                                          $this->name
                                        </td>
                                    </tr>
                                    <tr>
                                        <td>
                                            <span class="primary-link">DOB</span>
                                        </td>
                                        <td >
                                            $this->date_of_birth
                                        </td>
                                    </tr>
                                    <tr>
                                        <td>
                                            <span class="primary-link">Gender</span>
                                        </td>
                                        <td>
                                            $this->gender
                                        </td>
                                    </tr>
                                    <tr>
                                        <td>
                                            <span class="primary-link">Email</span>
                                        </td>
                                        <td>
                                            $this->email
                                        </td>
                                    </tr>
                                    <tr>
                                        <td>
                                            <span class="primary-link">Phone</span>
                                        </td>
                                        <td>
                                            $this->phone
                                        </td>
                                    </tr>
                                    <tr>
                                        <td>
                                            <span class="primary-link">Mobile</span>
                                        </td>
                                        <td>
                                            $this->mobile
                                        </td>
                                    </tr>
                                  <tr>
                                        <td>
                                            <span class="primary-link">Address</span>
                                        </td>
                                        <td>
                                            $this->address
                                        </td>
                                    </tr>
                                </tbody>
                            </table>
                            </div>
                        </div>
                    </div>
                </div>
                <!-- END  Personal Details -->

                 <!-- Start LEAVE ADWARD -->
<!--/.col-md-4 -->
                <div class="col-md-4">                          
                    <div class="well-custom">
                        <!-- STATISTICS -->
                        <div class="row">
                            <div class="col-md-6 col-sm-6 col-xs-6" style="border-right: 1px solid #46b8da">
                                <a href="leave_application.php" style="color: white;">
                                    <div class="uppercase text-center">
                                        <strong>
                                          
                                        </strong>
                                    </div>
                                    <div class="uppercase text-center">
                                        Leave
                                    </div>
                                </a>
                            </div>
                            <div class="col-md-6 col-sm-6 col-xs-6">
                                <a href="<?php echo base_url() ?>employee/dashboard/all_award" style="color: white;">
                                    <div class="uppercase text-center">
                                        <strong>
                                       
                                        </strong>
                                    </div>
                                    <div class="uppercase text-center">
                                        Awards
                                    </div>
                                </a>
                            </div>
                        </div>
                    </div>

				<!-- END LEAVE ADWARD -->

				<!-- Start NOTICE BOARD -->
				<div class="panel panel-info">
                        <div class="panel-heading">
                            <h2 class="panel-title"><i class="fa fa-bell-o"></i> <strong>Notice Board</strong><span class="pull-right">
                            <a href="all_notice.php" class=" view-all-front">View All</a></span></h2>
                        </div>               
                        <div class="panel-body tab-pane-notice">
                       		 
EOF;
$this->notice();
echo<<<EOF
                           
                        </div>
                    </div>                     
                    <!-- END NOTICE BOARD -->
</div> 
<!--/.col-md-4 -->
</div>
 <hr/>

 <!-- START EMAIL BOARD -->
 <!--/.col-md-12 -->
            <div class="col-md-12">
                <div class="col-md-8">
                    <div class="panel panel-info">
                        <div class="panel-heading ">
                            <h2 class="panel-title "><i class="fa fa-mail-reply-all"></i> <strong>Recent Mails</strong><span class="pull-right"><a href="<?php echo base_url() ?>employee/dashboard/all_notice" class="view-all-front">Go To Mailbox</a></span></h2>
                        </div>
                        <div class="panel-body tab-pane">
                            <div class="table-responsive mailbox-messages">
                                <table class="table table-hover table-striped">
                                    <tbody>
                                            <tr>
                                                <td><strong>There is no email to display</strong></td>
                                            </tr> 

                                    </tbody>
                                </table><!-- /.table -->
                            </div><!-- /.mail-box-messages -->
                        </div>
                    </div> 
                </div>

 <!-- END EMAIL BOARD -->
<!--/.col-md-4 -->
                 <div class="col-md-4">

                  <!-- START Upcoming Holiday -->
                    <div class="panel panel-info">
                        <div class="panel-heading">
                            <h2 class="panel-title"><i class="fa fa-binoculars"></i><strong> Holidays</strong><span class="pull-right">
                            <a href="all_holidays.php" class=" view-all-front">View All</a></span></h2>
                        </div>               
                        <div class="panel-body event">
EOF;
$this->holiday();
echo<<<EOF
                        </div>
                    </div> 
                    <!-- END Upcoming Holiday -->              
                </div>
<!--/.col-md-4 -->
	</div>
<!--/.col-md-12 -->
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
EOF;
	}

	public function information(){
		global $db,$user_id;

		$sql = "SELECT employee_id,employment_id,concat(first_name,' ',last_name) AS name,photo,father_name,date_of_birth,gender,email,phone,mobile,
		concat(present_address,',',city, ',',countryName) AS address, concat(DEP.department_name,' - ',DES.designations) as position
		FROM hrms_employee
		INNER JOIN countries ON countries.country_id = hrms_employee.country_id
		INNER JOIN hrms_designations DES ON DES.designations_id = hrms_employee.designation_id
    	INNER JOIN hrms_department DEP ON DEP.department_id = DES.department_id
		WHERE employee_id = $user_id";
		$query=mysqli_query($db,$sql);
		$row=mysqli_fetch_assoc($query);

		$this->employment_id = $row['employment_id'];
		$this->name = $row['name'];
		$this->photo = $row['photo'];
		$this->father_name = $row['father_name'];
		$this->date_of_birth = $row['date_of_birth'];
		$this->email = $row['email'];
		$this->phone = $row['phone'];
		$this->mobile = $row['mobile'];
		$this->address = $row['address'];
		$this->position = $row['position'];
		$gender = $row['gender'];
		if($gender == 1){
			$this->gender = "Male";
		}else{
			$this->gender = "Female";
		}
	}

	public function notice(){
		global $db;

		$sql = "SELECT notice_id,title,short_description,updated
		FROM hrms_notice
		WHERE flag = 1";
		$query=mysqli_query($db,$sql);
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
                                            <a href="notice_detail.php?notice_id=$notice_id">$title</a>                        
                                        </h5>
                                        <div class="notice-calendar-date">
                                           
                                            $short_description
                                        </div>
                                    </div>
                                    <div style="margin-top: 5px; padding-top: 5px; padding-bottom: 10px;">
                                        <span style="font-size: 10px;" class="pull-right">
                                            <strong><a href="notice_detail.php?notice_id=$notice_id" style="color: #004884;">View Details</a></strong>
                                        </span>
                                    </div>
                                </div>
EOF;
		}
	}
	public function holiday(){
		global $db;

		$sql = "SELECT holiday_id,event_name,event_date
		FROM hrms_holiday
		ORDER BY event_date";
		$query=mysqli_query($db,$sql);
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
                                            <a href="notice_detail.php?holiday_id=$holiday_id">$event_name</a>                        
                                        </h5>
                                    </div>
                                    <div style="margin-top: 5px; padding-top: 5px; padding-bottom: 10px;">
                                        <span style="font-size: 10px;" class="pull-right">
                                            <strong><a href="notice_detail.php?holiday_id=$holiday_id" style="color: #004884;">View Details</a></strong>
                                        </span>
                                    </div>
                                </div>
EOF;
		}
	}
}// END CLASS