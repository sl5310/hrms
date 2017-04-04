<?php 
class update_profile{

  public $first_name;
  public $last_name;
  public $user_name;
  public $msg;
  public $old_password;
  public $new_password;

	public function inputform(){

    if (!empty($_SESSION['msg'])) {
   $this->msg = $_SESSION['msg'];
    }

echo<<<EOF

<div class="right_col" role="main">
  <div class="">
      <div class="row">

      <div class="col-md-12 col-sm-12 col-xs-12">
         <div id="msg">
        $this->msg                         
         </div>
      </div>

        <div class="col-md-6 col-sm-6 col-xs-12">
            <div class="x_title">
                <h2>Update Profile</h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                    <form id="inputform" class="form-horizontal form-label-left" action="update_profile.php" method="post">

                                  <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">First Name <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input type="text" class="form-control col-md-7 col-xs-12" name="first_name" required="required" value="$this->first_name" placeholder="Enter Your First Name">
                                            </div>
                                    </div>

                                  <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Last Name <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input type="text" class="form-control col-md-7 col-xs-12" name="last_name" required="required" value="$this->last_name"
                                                placeholder="Enter Your Last Name">
                                            </div>
                                    </div>

                                  <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">User Name <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input type="text" class="form-control col-md-7 col-xs-12" name="user_name" required="required" value="$this->user_name"
                                                placeholder="Enter Your User Name">
                                            </div>
                                    </div>


                                      <div class="ln_solid"></div>
                                        <div class="form-group">
                                            <div class="col-md-6 col-md-offset-3">

                                                <input type='submit' value='Update' class="btn btn-primary">
                                                <input type='hidden' value='update_profile' name='action'>
                                            </div>
                                        </div>
                                    </form>
      </div>
  </div>

          <div class="col-md-6 col-sm-6 col-xs-12">
            <div class="x_title">
                <h2>Change Password</h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                    <form id="inputform" class="form-horizontal form-label-left" action="update_profile.php" method="post" onSubmit="return changePass()">

                                  <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Old Password <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                               <input type="password" name="old_password" value="" class="form-control" required="required" placeholder="Enter Your Old Password">
                                            </div>
                                    </div>

                                  <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">New Password<span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                 <input type="password" name="new_password" id="new_password" value="" class="form-control" required="required" placeholder="Enter Your New Password"/>
                                            </div>
                                    </div>

                                  <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Confirm Password<span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input type="password" id="confirm_password" name="confirm_password" value="" class="form-control" required="required" placeholder="Enter Your Retype Password"/>
                                            </div>
                                    </div>


                                      <div class="ln_solid"></div>
                                        <div class="form-group">
                                            <div class="col-md-6 col-md-offset-3">

                                                <input type='submit' value='Update' class="btn btn-primary">
                                                <input type='hidden' value='update_password' name='action'>
                                            </div>
                                        </div>
                                    </form>
      </div>
  </div>

<script>
setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 3000); // <-- time in milliseconds
         function changePass(){
        
            var passwordval = document.getElementById('new_password').value;
            var passwordField = $('#new_password').parsley();


            var confirmpasswordval = document.getElementById('confirm_password').value;
            var ConfirmPasswordField = $('#confirm_password').parsley();


            if (passwordval.length < 1 ){
              window.ParsleyUI.removeError(passwordField, "EnterPassword");
      window.ParsleyUI.addError(passwordField, "EnterPassword", 'Please Enter Your New Password.');
              return false;
            }else{
      window.ParsleyUI.removeError(passwordField, "EnterPassword");
            }

            if(passwordval.length > 1 && confirmpasswordval.length < 1){
                window.ParsleyUI.removeError(ConfirmPasswordField, "ConfirmPasswordField");
                window.ParsleyUI.addError(ConfirmPasswordField, "ConfirmPasswordField", 'Please Confirm Your New Password.');
                return false;
            }else{
          window.ParsleyUI.removeError(ConfirmPasswordField, "ConfirmPasswordField");
            }

            if (passwordval != confirmpasswordval){
              window.ParsleyUI.removeError(ConfirmPasswordField, "ComparePassword");
              window.ParsleyUI.addError(ConfirmPasswordField, "ComparePassword", 'Password does not match the confirm password.');
                return false;
            }else{
              window.ParsleyUI.removeError(ConfirmPasswordField, "ComparePassword");
            }
            return true;
        }
</script>



EOF;
$this->msg = null;
$_SESSION['msg'] = null;
	}

  public function fetch_info(){
    global $db,$user_id;

    $sql = "SELECT first_name,last_name, user_name FROM hrms_admin WHERE user_id = $user_id";
    $query=mysqli_query($db,$sql);
    $row = mysqli_fetch_assoc($query);
    $this->first_name = $row['first_name'];
    $this->last_name = $row['last_name'];
    $this->user_name = $row['user_name'];
  }

  public function check_user_name(){
        global $db,$user_id;

        $username = filter_var($this->user_name, FILTER_SANITIZE_STRING, FILTER_FLAG_STRIP_LOW|FILTER_FLAG_STRIP_HIGH);
        $sql = "SELECT user_name FROM hrms_admin WHERE user_name = '$username' AND user_id != $user_id";
        $query = mysqli_query($db,$sql);
        if(mysqli_num_rows($query) > 0){

           $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
          User Name is duplicate, please choose another User Name.</span>
          </div>";
          return false;
        }else{

            $sql = "SELECT user_name FROM hrms_employee_login WHERE user_name = '$username' AND employee_id != $user_id";
             $query = mysqli_query($db,$sql);
              if(mysqli_num_rows($query) > 0){
            $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
          User Name is duplicate, please choose another User Name.</span>
          </div>";
            return false;
              }

            return true;
        }
    }
  public function update_info(){
    global $db,$user_id;
    $timestamp= date("y/m/d H:i:s", time());

   $sql="UPDATE hrms_admin
    SET first_name = '$this->first_name',
    last_name = '$this->last_name',
    user_name = '$this->user_name',
    updated = '$timestamp',
    updatedby = $user_id
    WHERE user_id = $user_id";
   if($query=mysqli_query($db,$sql)){

    $_SESSION['msg']="<div class='alert alert-success'>
    Profile updated successfully!
    </div>";
     return true;
  }else{

    $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
           Cannot update profile, please contact Administrator.</span>
          </div>";
          return false;
  }

 }
public function checkpass(){
    global $user_id,$db;
            //check if employee login
            $old_password = mysqli_real_escape_string($db,$this->old_password);

            $sql = "SELECT * FROM hrms_admin WHERE user_id = $user_id";
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
            $sql_hash = "SELECT * FROM hrms_admin where password = '$hashedPW'";
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
    public function update_pass(){
      global $user_id,$db;

        $escapedPW = mysql_real_escape_string($this->new_password);
        # generate a random salt to use for this account
        $salt = bin2hex(mcrypt_create_iv(32, MCRYPT_DEV_URANDOM));
        $saltedPW =  $escapedPW . $salt;
        $hashedPW = hash('sha256', $saltedPW);

      $timestamp= date("y/m/d H:i:s", time());
      $sql="UPDATE hrms_admin
      SET password='$hashedPW',
      salt = '$salt',
      updated = '$timestamp',
      updatedby = '$user_id'
      WHERE user_id = $user_id";


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