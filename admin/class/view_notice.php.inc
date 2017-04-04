<?php 
class view_notice{

	public $title;
	public $short_description;
	public $long_description;
	public $last_updated;

	public function form(){

echo<<<EOF
<div class="right_col" role="main">
    <div class="">
        <div class="row">

<div class="col-md-12 col-xs-12">

            <div class="x_title">               
                <h2>Notice Details</h2><span class="pull-right"><a style='color:white;'onclick="history.go(-1);" class="view-all-front">Go Back</a></span>
            <div class="clearfix"></div>
            </div>                    
  
        <div class='x_content'>

           <div class="item form-group col-sm-12 col-xs-12">
                <div class="col-sm-3" style='text-align:right;'> 
                    <label class="control-label col-md-offset-3"><strong>Title:</strong></label>
                </div>
                <div class="col-sm-6">
                    <class="form-control-static col-md-7 col-xs-12">$this->title
                </div>

            </div>

            <div class="item form-group col-sm-12 col-xs-12">
                <div class="col-sm-3" style='text-align:right;'> 
                    <label class="control-label col-md-offset-3"><strong>Short Description:</strong></label>
                </div>
               <div class="col-sm-6">
                    <class="form-control-static text-justify col-md-7 col-xs-12">$this->short_description
                </div>
            </div>

            <div class="item form-group col-sm-12 col-xs-12">
                <div class="col-sm-3" style='text-align:right;'> 
                    <label class="control-label col-md-offset-3"><strong>Long Description:</strong></label>
                </div>
                <div class="col-sm-6 col-xs-12">
                    <class="form-control-static text-justify col-md-7 col-xs-12">$this->long_description
                </div>
            </div>

            <div class="item form-group col-sm-12 col-xs-12">
                <div class="col-sm-3" style='text-align:right;'> 
                    <label class="control-label" ><strong>Last Updated:</strong></label>
                </div>
               <div class="col-sm-6">                    
                    <class="form-control-static col-md-7 col-xs-12"><span class="text-danger">$this->last_updated</span>   
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