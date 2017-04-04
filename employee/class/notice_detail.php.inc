<?php 
class notice_detail{

	public $title;
	public $short_description;
	public $long_description;
	public $last_updated;

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
                <strong>Notice Details</strong><span class="pull-right"><a onclick="history.go(-1);" class="view-all-front">Go Back</a></span>
            </div>                    
        </div>    
        <div class="panel-body form-horizontal">
            <div class="col-md-12 notice-details-margin">

                    <label class="control-label col-sm-4"><strong>Title:</strong></label>
            
                <div class="col-sm-8">
                    <p class="form-control-static">$this->title</p>
                </div>
            </div>
            <div class="col-md-12 notice-details-margin">

                    <label class="control-label col-sm-4"><strong>Short Description:</strong></label>

                <div class="col-sm-8">
                    <p class="form-control-static text-justify">$this->short_description</p>
                </div>
            </div>
            <div class="col-md-12 notice-details-margin">

                    <label class="control-label col-sm-4"><strong>Long Description:</strong></label>

                <div class="col-md-8">
                    <p class="form-control-static text-justify">$this->long_description</p>
                </div>                  
            </div>
            <div class="col-md-12 notice-details-margin">

                    <label class="control-label col-sm-4"><strong>Last Updated:</strong></label>

                <div class="col-sm-8">
                    <p class="form-control-static"><span class="text-danger">$this->last_updated</span></p>
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

	public function get_notice_detail(){
		global $db;

		$sql="SELECT notice_id, title, short_description, long_description,
    		concat(hrms_notice.updated,' by ',UPDATEDBY.first_name,' ',UPDATEDBY.last_name) as updatedby
         FROM hrms_notice
         INNER JOIN hrms_admin CREATEDBY ON CREATEDBY.user_id = hrms_notice.createdby
         INNER JOIN hrms_admin UPDATEDBY ON UPDATEDBY.user_id = hrms_notice.updatedby
         WHERE notice_id = $this->notice_id";
        if($query=mysqli_query($db,$sql)){
         $row=mysqli_fetch_assoc($query);
                $this->title = $row['title'];
                $this->short_description = $row['short_description'];
                $this->long_description = $row['long_description'];
                $this->last_updated = $row['updatedby'];
        }else{
             header("Location: all_notice.php",500);
          exit;
        }
	}
}