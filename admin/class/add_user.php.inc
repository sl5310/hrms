<?php 

class add_user{

	public $msg;
	public $username;
	public $password;
	public $confirm_password;
    public $first_name;
    public $last_name;
    public $permission;
    public $isactive;
    public $prm_add;
    public $prm_update;
    public $prm_delete;


	public function inputform($type){

if (!empty($_SESSION['msg'])) {
   $this->msg = $_SESSION['msg'];
}

echo<<<EOF
    <!-- icheck -->
        <script src="/aspirez_hrms/application/asset/js/icheck/icheck.min.js"></script>

        <script type="text/javascript">
 $(document).ready(function () {
$('#inputform').parsley();
             $('input').iCheck({
                checkboxClass: 'icheckbox_flat-blue'
              });

        });


setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 1500); // <-- time in milliseconds



        </script>


            <div class="right_col" role="main">
                <div class="">

                    <div class="clearfix"></div>

                   <div class="row">
                        <div class="col-md-12 col-sm-12 col-xs-12">
                        <div id="msg">
                           $this->msg                         
                        </div>

                                <div class="x_title">
                                    <h2>Add User</h2>
                                    <div class="clearfix"></div>
                                </div>

                                 <div class="x_content">

                                    <form id="inputform" class="form-horizontal form-label-left" action="add_user.php" method="post" data-parsley-validate>

                                            <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">First Name <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input id="name" class="form-control col-md-7 col-xs-12" name="first_name" placeholder="Enter Your First Name" required="required" type="text" value="$this->first_name">
                                            </div>
                                            </div>

                                            <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Last Name <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input id="name" class="form-control col-md-7 col-xs-12" name="last_name" placeholder="Enter Your Last Name" required="required" type="text" value="$this->last_name">
                                            </div>
                                            </div>

											<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">User Name <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input id="name" class="form-control col-md-7 col-xs-12" name="username" id="username" placeholder="Enter Your User Name" required="required" type="text" value="$this->username"  pattern="^[A-Za-z0-9()\/-]+$" >
                                            </div>
                                        	</div>

                                        	<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Password <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input class="form-control col-md-7 col-xs-12" id="password" name="password" placeholder="Enter Your Password" required="required" type="password" value="$this->password">
                                            </div>
                                        	</div>

                                        	<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Confirm Password <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input class="form-control col-md-7 col-xs-12" id="confirm_password" name="confirm_password" placeholder="Confirm Your Password" 
                                                data-parsley-equalto="#password" required="required" type="password" value="$this->confirm_password">
                                            </div>
                                        	</div>

                                            <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Permission
                                            </label>
                                            
         
                                            <input type="checkbox" name="prm_add" class="flat" /> Add
                                        
                                            <input type="checkbox" name="prm_update" class="flat" /> Update

                                            <input type="checkbox" name="prm_delete" class="flat" /> Delete
                                 

                             
                                            </div>

                                             <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Is Active
                                            </label>
                                       
                                             <p style="padding:10px;">
                                            <input type="checkbox" name="isactive" class="flat" />
                                            <p>
                                             
                                            </div>

                                      <div class="ln_solid"></div>
                                        <div class="form-group">
                                            <div class="col-md-6 col-md-offset-3">

                                                <input id="send" type='submit' value='Save' class="btn btn-primary">
                                                <input type='hidden' value='save' name='action'>
                                            </div>
                                        </div>

                                    </form>
                                
                                </div>
                            </div>
                        </div>

EOF;

$this->msg = null;
$_SESSION['msg'] = null;

	}

	public function save(){
		global $db,$user_id;
       
        $timestamp= date("y/m/d H:i:s", time());
		$escapedName = mysql_real_escape_string($this->username);
		$escapedPW = mysql_real_escape_string($this->password);

		# generate a random salt to use for this account
		$salt = bin2hex(mcrypt_create_iv(32, MCRYPT_DEV_URANDOM));

		$saltedPW =  $escapedPW . $salt;

		$hashedPW = hash('sha256', $saltedPW);

		 $sql = sprintf("INSERT INTO hrms_admin (first_name,last_name,user_name,password,salt,isactive,created,createdby,updated,updatedby) 
        values ('%s','%s','%s','%s','%s',
                '%d','%s','%d','%s','%d')",
        $this->first_name,$this->last_name,$escapedName, $hashedPW, $salt,$this->isactive,$timestamp,$user_id,$timestamp,$user_id);
		  if(mysqli_query($db,$sql)) {

             $user_id = $this->getMaxID();
             $sql_permission = sprintf("INSERT INTO permission (user_id,prm_add,prm_update,prm_delete,
                created,createdby,updated,updatedby) 
                values ('%d','%d','%d','%d',
                        '%s','%d','%s','%d');",
                $user_id,$this->prm_add,$this->prm_update,$this->prm_delete,$timestamp,$user_id,$timestamp,$user_id);
                mysqli_query($db,$sql_permission);

         $_SESSION['msg']="<div class='alert alert-success'>
          Administrator Account Save Successfully!
         </div>";
          return true;
          }else{
            $_SESSION['msg']="<div class='alert alert-info'>Username Already Existed. Please try another Username.</div>";
            return false;
          }
	}

    public function getMaxID(){
        global $db;

            $sql="SELECT MAX(user_id) From hrms_admin";
              $query = mysqli_query($db,$sql);
              $row = mysqli_fetch_assoc($query);

              return $max= $row['MAX(user_id)'];

    }

//check user duplicate
    public function checkuser(){
        global $db;

        $username = filter_var($this->username, FILTER_SANITIZE_STRING, FILTER_FLAG_STRIP_LOW|FILTER_FLAG_STRIP_HIGH);
        $sql = "SELECT user_name FROM hrms_admin WHERE user_name = '$username'";
        $query = mysqli_query($db,$sql);
        if(mysqli_num_rows($query) > 0){
echo<<<EOF
<script>
alert('Username is already existed. Please enter username instead of this.');
$( "#username" ).focus();
</script>
EOF;
            return false;
        }else{

            $sql = "SELECT user_name FROM hrms_employee_login WHERE user_name = '$username'";
             $query = mysqli_query($db,$sql);
              if(mysqli_num_rows($query) > 0){
                echo<<<EOF
<script>
alert('Username is already existed. Please enter username instead of this.');
$( "#username" ).focus();
</script>
EOF;
            return false;
              }

            return true;
        }
    }
}