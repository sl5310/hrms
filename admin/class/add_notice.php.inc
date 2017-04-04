<?php
class add_notice{
	
	public $msg;
  public $notice_id;
	public $title;
	public $short_description;
	public $long_description;
	public $flag;
  public $published;
  public $unpublished;

	public function inputform($type){
    if (!empty($_SESSION['msg'])) {
       $this->msg = $_SESSION['msg'];
    }

    if ($type == "new"){
    	$action = "save";
    	$this->unpublished = "checked";
    	$hidden = "";
    }else{
    	$action = "update";
    	$hidden = "<input type='hidden' value='$this->notice_id' name='notice_id'>";
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
                <h2>Create Notice</h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                    <form id="inputform" class="form-horizontal form-label-left" action="add_notice.php" method="post">
						            <div class="form-group">
                            <label for="field-1" class="col-sm-3 control-label">Publication Status <span class="required">*</span></label>

                            <div class="col-md-4 col-sm-4 col-xs-4">Published
                            <input type="checkbox" name="flag" value="1" $this->published></div>

                        </div>

                        <div class="form-group">
                            <label for="field-1" class="col-sm-3 control-label">Title<span class="required">*</span></label>

                            <div class="col-md-9 col-sm-9 col-xs-12">
                                <input type="text" name="title" value="$this->title" class="form-control" required="required" placeholder="Enter Notice Title Here"/>
                            </div>
                        </div>

                         <div class="form-group">
                            <label for="field-1" class="col-sm-3 control-label">Short Description <span class="required">*</span></label>

                            <div class="col-md-9 col-sm-9 col-xs-12">
                                <textarea name="short_description" class=" col-md-9 col-sm-9 col-xs-12 form-control" required="required" placeholder="Enter Short Description">$this->short_description</textarea>
                            </div>
                        </div>

                  <!-- ************************ Long Description Start ******************************* -->

                  		<div class="form-group">
                            <label for="field-1" class="col-sm-3 control-label">Long Description</label>

                            <div class="col-md-9 col-sm-9 col-xs-12">
						           <textarea name="long_description" id="long_description" rows="10" cols="80" required="required">$this->long_description</textarea>
					        </div>
                    </div>
                                      <!-- ************************ Long Description End ******************************* -->
                     <!--hidden input values -->                       

                        <div class="form-group">
                            <div class="col-sm-offset-3 col-sm-5">
                                <button type="submit" id="sbtn" class="btn btn-primary">Save</button>
                                <input type="hidden" value="$action" name="action">
                                $hidden             
                            </div>
                        </div>   

                    </form>
                </div>
    </div>
    <script src="//cdn.ckeditor.com/4.5.4/standard/ckeditor.js"></script>
      <!-- icheck -->
        <script src="../asset/js/icheck/icheck.min.js"></script>
            <script>

                   $('input').iCheck({
          checkboxClass: 'icheckbox_flat-blue'
        });
                // Replace the <textarea id="editor1"> with a CKEditor
                // instance, using default configuration.
                CKEDITOR.replace( 'long_description' );
                setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 3000); // <-- time in milliseconds

            </script>
    
EOF;
$this->msg = null;
$_SESSION['msg'] = null;
	}
	//SAVE NOTICE
public function save(){
		global $db,$user_id;
	$timestamp= date("y/m/d H:i:s", time());

      //else save
      $sql = sprintf("INSERT INTO `hrms_notice`
                (`title`,`short_description`,`long_description`,`flag`,
                `created`,`createdby`,`updated`,`updatedby`) 
                VALUES 
                ('%s','%s','%s','%d',
                '%s','%d','%s','%d');"
                ,$this->title,$this->short_description,$this->long_description,$this->flag,
                $timestamp,$user_id,$timestamp,$user_id);
      	if(mysqli_query($db,$sql)) {
              $_SESSION['msg']="<div class='alert alert-success'>
                 					Notice Successfully Saved!
                					</div>";
             return true;
          }else{
              $_SESSION['msg']="<div class='alert alert-info'>Cannot create new notice.</div>";
          
           return false;
       	}
}
// fetch notice information from database
    public function fetch(){
         global $user_id,$db;
    // select department
    $sql="SELECT title,short_description,long_description,flag 
          FROM hrms_notice
          WHERE notice_id = $this->notice_id";

    $query=mysqli_query($db,$sql);
            if (!$query) {
        echo "Cannot fetch data, please contact webmater.";
        exit;
    }
          // fetch department_name to input text
           $row=mysqli_fetch_assoc($query);
           $this->title = $row['title'];
           $this->short_description = $row['short_description'];
           $this->long_description = $row['long_description'];
           $flag = $row['flag'];
           if ($flag == 1){
            $this->published = "checked";
           }else{
            $this->published = "";
           }
          }
    public function update(){
      global $db,$user_id;

      $sql = "UPDATE hrms_notice
      SET title = '$this->title',
      short_description = '$this->short_description',
      long_description = '$this->long_description',
      flag = '$this->flag'
      WHERE notice_id = $this->notice_id";
      if(mysqli_query($db,$sql)) {
           $_SESSION['msg']="<div class='alert alert-success'>
           Notice Successfully Updated!
          </div>";
          return true;

        }else {
             $_SESSION['msg']="<div class='alert alert-info'>
           Cannot updated notice, please contact webmaster.
          </div>";
        header("Location: manage_notice.php");
       return false;
    }
    }
}//END CLASS