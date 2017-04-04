<?php 
class change_password{

	public $new_password;
	public $old_password;
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
    <br/>  
<div class="row">
    <div class="col-sm-12" >

        <div class="panel panel-info" data-collapsed="0">
            <div class="panel-heading">
                <div class="panel-title">
                    <strong>Change Password</strong>
                </div>                
            </div>
            <div class="panel-body">
                <form role="form" id="change_password" action="change_password.php" method="post" class="form-horizontal form-groups-bordered">                        

                    <div class="form-group">
                        <label for="field-1" class="col-sm-3 control-label">Old Password <span class="required"> *</span></label>
                        <div class="col-sm-5">
                            <input type="password" name="old_password" value="" class="form-control"  placeholder="Enter Your Old Password">
                        </div>
                    </div>                                        
                    <div class="form-group">
                        <label for="field-1" class="col-sm-3 control-label">New Password <span class="required"> *</span></label>
                        <div class="col-sm-5">
                            <input type="password" name="new_password" id="new_password" value="" class="form-control"  placeholder="Enter Your New Password"/>
                        </div>
                    </div>                                        
                    <div class="form-group">
                        <label for="field-1" class="col-sm-3 control-label">Confirm Password <span class="required"> *</span></label>
                        <div class="col-sm-5">
                            <input type="password" name="confirm_password" value="" class="form-control"  placeholder="Enter Your Retype Password"/>
                        </div>
                    </div>                                        

                    <div class="form-group">
                        <div class="col-sm-offset-3 col-sm-5">
                            <button type="submit" id="sbtn" class="btn btn-primary">Update</button>
                            <input type='hidden' value='update' name='action'>                          
                        </div>
                    </div>   
                </form>
            </div>            
        </div>
        <br/>   
    </div>   
</div>  
</div> 					</div>
        		</div>
	        </div>
        </div>
    </div>        
</div>

<script>
setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 3000); // <-- time in milliseconds
</script>
EOF;
$this->msg = null;
$_SESSION['msg'] = null;
	}
public function checkpass(){
    global $user_id,$db;
            //check if employee login
            $old_password = mysqli_real_escape_string($db,$this->old_password);

            $sql = "SELECT * FROM hrms_employee_login WHERE employee_id = $user_id";
            $result = mysqli_query($db,$sql);

        //check whether query can run or not.
        if ($result === false) {
            echo "Could not successfully run query ($sql) from DB: " . mysqli_error() .". Please contact webmaster.";
            exit;
        }

    if (mysqli_num_rows($result) > 0) {
            $row=mysqli_fetch_assoc($result);
            $salt = $row['salt'];
            $saltedPW =  $old_password . $salt;
            $hashedPW = hash('sha256', $saltedPW);
            $sql_hash = "SELECT * FROM hrms_employee_login where password = '$hashedPW'";
            $result_hash = mysqli_query($db,$sql_hash);
        if (mysqli_num_rows($result_hash) > 0) {
            return true;
        }else{
           $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>Old Password is incorrect.</span></div>";
            return false;
        }
    }
}
    //update function
    public function update(){
      global $user_id,$db;

        $escapedPW = mysql_real_escape_string($this->new_password);
        # generate a random salt to use for this account
        $salt = bin2hex(mcrypt_create_iv(32, MCRYPT_DEV_URANDOM));
        $saltedPW =  $escapedPW . $salt;
        $hashedPW = hash('sha256', $saltedPW);

      $timestamp= date("y/m/d H:i:s", time());
      $sql="UPDATE hrms_employee_login
      SET password='$hashedPW',
      salt = '$salt',
      updated = '$timestamp',
      updatedby = '$user_id'
      WHERE employee_id = $user_id";


        if(mysqli_query($db,$sql)) {

            $_SESSION['msg']="<div class='alert alert-success'>
           Password Updated Successfully!
          </div>";

          return true;
        }else {
             $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>Cannot update password, please contact webmaster.</span></div>";
       return false;
        }
}
}//END CLASS