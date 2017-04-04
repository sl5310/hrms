<?php 
class view_application{

		public $employment_id;
		public $employee_name;
		public $designation;
		public $category;
		public $leave_date;
		public $total_days;
		public $reason;
		public $application_status;
		public $applied_on;
		public $application_id;
		public $msg;

	public function inputform(){
		global $selectcrtl;
		$application_status=$selectcrtl->getSelectApplicationStatus($this->application_status,'N');

echo<<<EOF
<div class="right_col" role="main">
  <div class="">
    <div class="clearfix"></div>
      <div class="row">
        <div class="col-md-12 col-sm-12 col-xs-12">
            <div id="msg">
            $this->msg                         
            </div>
            <div class="x_title">
                <h2>Leave Application  Details</h2>
                <span class="pull-right"><a style="cursor: pointer;color:white"onclick="history.go(-1)" class="view-all-front">Go Back</a></span>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">


			            <form method="post" action="view_application.php">
			                  <div class="panel-body form-horizontal">

			                  <div class="item form-group">
			                    <div class="col-md-12">
			                        <div class="col-sm-4 text-right">
			                            <label class="control-label"><strong>Employee ID : </strong></label>
			                        </div>                    
			                        <div class="col-sm-8">
			                            <class="form-control-static">$this->employment_id
			                        </div>
			                    </div>
							 </div>			

							 <div class="item form-group">
			                    <div class="col-md-12">
			                        <div class="col-sm-4 text-right">
			                            <label class="control-label"><strong>Name : </strong></label>
			                        </div>                    
			                        <div class="col-sm-8">
			                            <class="form-control-static">$this->employee_name
			                        </div>
			                    </div>
			                  </div>

			                  <div class="item form-group">
			                    <div class="col-md-12">
			                        <div class="col-sm-4 text-right">
			                            <label class="control-label"><strong>Dept.>Designation : </strong></label>
			                        </div>                    
			                        <div class="col-sm-8">
			                            <class="form-control-static">$this->designation
			                        </div>
			                    </div>
			                  </div>

			                  <div class="item form-group">
			                    <div class="col-md-12">
			                        <div class="col-sm-4 text-right">
			                            <label class="control-label"><strong>Leave Date : </strong></label>
			                        </div>
			                        <div class="col-sm-8">
			                            <class="form-control-static text-justify">$this->leave_date
			                        </div>
			                    </div>
			                  </div>

			                  <div class="item form-group">
			                    <div class="col-md-12">
			                        <div class="col-sm-4 text-right">
			                            <label class="control-label"><strong>Leave Requested Day(s) : </strong></label>
			                        </div>
			                        <div class="col-sm-8">
			                            <class="form-control-static text-justify" name="total_days">$this->total_days
			                        </div>
			                    </div>
			                  </div>

			                  <div class="item form-group">
			                    <div class="col-md-12">
			                        <div class="col-sm-4 text-right">
			                            <label class="control-label"><strong>Leave Type :</strong></label>
			                        </div>
			                        <div class="col-sm-8">
			                            <class="form-control-static text-justify">$this->category
			                        </div>                  
			                    </div>
			                   </div>
			                   <div class="item form-group">
			                    <div class="col-md-12">
			                        <div class="col-sm-4 text-right">
			                            <label class="control-label"><strong>Apply On : </strong></label>
			                        </div>
			                        <div class="col-sm-8">
			                            <class="form-control-static"><span class="text-danger">$this->applied_on</span>
			                        </div>                                              
			                    </div>
			                    </div>
			                    <div class="item form-group">
			                    <div class="col-md-12">
			                        <div class="col-sm-4 text-right">
			                            <label class="control-label"><strong>Reason : </strong></label>
			                        </div>
			                        <div class="col-sm-8">
			                            <class="form-control-static">$this->reason
			                        </div>                                              
			                    </div>
			                    </div>
			                    <div class="item form-group">
			                    <div class="col-md-12 margin">
			                        <div class="col-sm-4 text-right">
			                            <label class="control-label"><strong>Action : </strong></label>
			                        </div>
			                        <div class="col-sm-2">                        
			                            <select class="form-control" name="application_status">
			                                $application_status
			                            </select>                        
			                        </div>                                              
			                    </div>
			                    </div>
			                    <div class="item form-group">
			                    <div class="col-md-12">
			                        <div class="col-sm-4 col-md-offset-4">
			                            <button type="submit" class="btn btn-primary">Update</button>
			                            <input type="hidden" value="update" name="action">
			                            <input type="hidden" value="$this->application_id" name="application_id">
			                        </div>                                                                
			                    </div>
			                   	</div>
			                 </form>

                </div>                
        </div>
    </div>
EOF;
	}

	public function fetch(){
		global $db;
		$sql="SELECT application_list_id AS application_id,hrms_leave_category.category,leave_start_date, leave_end_date, reason, application_status, hrms_application_list.created AS applied_on, total_days,
         employment_id,concat(first_name,' ',last_name) AS name, concat(DEP.department_name,'.>',DES.designations) AS designation
         FROM hrms_application_list
         INNER JOIN hrms_leave_category ON hrms_leave_category.leave_category_id = hrms_application_list.leave_category_id
         INNER JOIN hrms_employee EMP ON EMP.employee_id = hrms_application_list.employee_id
         INNER JOIN hrms_designations DES ON DES.designations_id = EMP.designation_id
         INNER JOIN hrms_department DEP ON DEP.department_id = DES.department_id
         WHERE application_list_id = $this->application_id";

    $query=mysqli_query($db,$sql);
            if (!$query) {
         $_SESSION['msg']="<div class='alert alert-success'>
          No data found.
          </div>";
            header("Location: application_list.php");
    		exit;
    }
          // fetch department_name to input text
           $row=mysqli_fetch_assoc($query);
           $application_id = $row['application_id'];
                $this->employment_id = $row['employment_id'];
                $this->employee_name = $row['name'];
                $this->designation = $row['designation'];
                $this->category = $row['category'];

                $this->total_days = $row['total_days'];
                $this->reason = $row['reason'];
                $this->application_status = $row['application_status'];
                $this->applied_on = $row['applied_on'];
                $this->leave_date = $row['leave_start_date']."<span class='text-danger'> To </span>".$row['leave_end_date'];
	}

	    public function update(){
      global $db,$user_id;

      $sql = "UPDATE hrms_application_list
      SET application_status = '$this->application_status'
      WHERE application_list_id = $this->application_id";

      if(mysqli_query($db,$sql)) {
           $_SESSION['msg']="<div class='alert alert-success'>
           Leave Application Updated Successfully!
          </div>";
          return true;

        }else {
             $_SESSION['msg']="<div class='alert alert-success'>
           Cannot updated leave application, please contact webmaster.
          </div>";
       return false;
    }

   }
}//END CLASS