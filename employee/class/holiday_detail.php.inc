<?php 
class holiday_detail{

        public $event_name;
        public $description;
        public $event_date;
	public function form(){

echo<<<EOF
    <div class="container">
        <div class="row">
            <div class="margin">    
                <div class="col-md-12">
                    <div class="main_content">
                        <div class="row">
<div class="col-md-12">

    <div class="panel panel-info">
        <!-- Default panel contents -->

        <div class="panel-heading">
            <div class="panel-title">                 
                <strong>Holidays Details</strong><span class="pull-right"><a onclick="history.go(-1);" class="view-all-front">Go Back</a></span>
            </div>                    
        </div>    
        <div class="panel-body form-horizontal">
            <div class="col-md-12 notice-details-margin">

                    <label class="control-label col-sm-4"><strong>Title:</strong></label>
              
                <div class="col-sm-8">
                    <p class="form-control-static">$this->event_name</p>
                </div>
            </div>

            <div class="col-md-12 notice-details-margin">

                    <label class="control-label col-sm-4"><strong>Event Date:</strong></label>

                <div class="col-sm-8">
                    <p class="form-control-static"><span class="text-danger">$this->event_date</span></p>
                </div>                                              
            </div>

            <div class="col-md-12 notice-details-margin">

                    <label class="control-label col-sm-4"><strong>Description:</strong></label>

                <div class="col-sm-8">
                    <p class="form-control-static text-justify">$this->description</p>
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

EOF;
	}

	public function get_holiday_detail(){
		global $db;

		$sql="SELECT event_name, description, event_date
         FROM hrms_holiday
         WHERE holiday_id = $this->holiday_id";
        if($query=mysqli_query($db,$sql)){
         $row=mysqli_fetch_assoc($query);
                $this->event_name = $row['event_name'];
                $this->description = $row['description'];
                $this->event_date = $row['event_date'];
        }else{
             header("Location: all_holidays.php",500);
          exit;
        }
	}
}