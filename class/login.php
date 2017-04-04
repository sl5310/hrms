<?php

class Login{
    public $msg;
    
    public function loginform(){

   // $msg="<b style='color:red'>Wrong username/password combination!</b>";

echo<<<EOF

<head>
<title>Human Resource Management System</title>
</head>

<body>
    <div class="">
        <div id="wrapper">
            <div class="animated fadeInUp" data-animation="fadeInUp">
                <section class="login_content" id="section-main">    

                    <form id='loginForm' data-toggle="validator" action="login.php" method="post">

                            <div class="login-panel panel panel-default">

                                <div class="panel-heading">
                                    <h3 class="panel-title">Login Panel</h3>
                                </div>
                                <div class="panel-body">
                                        $this->msg

                                        <fieldset>

                                            <div class="form-group" id="errors">

                                            </div>

                                            
                                            <div class="form-group has-feedback">
                                                <input class="form-control" placeholder="User Name" id="username" name="username" type="text" value="" autofocus >
                                                <span class="fa fa-user form-control-feedback right" aria-hidden="true"></span>
                                            </div>
                                          

                                            <div class=" form-group has-feedback">
                                                <input class="form-control" placeholder="Password" id="password" name="password" type="password" value="" >
                                                <span class="fa fa-lock form-control-feedback right" aria-hidden="true"></span>
                                            </div>

                                           <input type='submit' class="btn btn-lg btn-success btn-block" data-loading-text="Signing In...." value='Login'>
                                           <input type='hidden' value='login' name='action'>

                                        </fieldset>
                                   
                                </div>
                        </div>
                    </form>
                </section>    
            </div>
        </div>
    </div>
</body>
<script>
$(document).ready(function () {
    $('#loginForm').validate({
        errorElement: "div",
        errorPlacement: function(error, element) {
                        error.appendTo("div#errors");
        }, 
        rules: {
            username: {
                required: true

            },
            password: {
                required: true,
            },
        },
         messages: {
             "username": {
                required: "The User Name field is required..",
            },  
             "password": {
                required: "The Password field is required.",
            },
        }
       });
 });
</script>
EOF;
    }

    public function verifylogin($username_1,$password_1){
        include "admin/components/setting.php.inc";
         session_start();
           $_SESSION['is_logged_in'] = 0;
           $_SESSION['account_type'] = 0;
           $login_data = array();


    //check request method is POST
    if($_SERVER['REQUEST_METHOD'] == 'POST') {
            
            $db = mysqli_connect($dbhost,$dbuser,$dbpassword,$dbname) or die ('ERROR: Could not connect to database!');
            mysqli_select_db($db, $dbname);

            $username = mysqli_real_escape_string($db,$username_1);
            $password = mysqli_real_escape_string($db,$password_1);

        //check if admin login
            $sql = "SELECT * FROM hrms_admin WHERE user_name = '$username' AND isactive=1";
            $result = mysqli_query($db,$sql);

        //check whether query can run or not.
        if ($result === false) {
            echo "Could not successfully run query ($sql) from DB: " . mysqli_error() .". Please contact webmaster.";
            exit;
        }

if (mysqli_num_rows($result) > 0) {

            $row=mysqli_fetch_assoc($result);
            $salt = $row['salt'];
            $saltedPW =  $password . $salt;
            $hashedPW = hash('sha256', $saltedPW);
           $sql_hash = "SELECT * FROM hrms_admin where password = '$hashedPW'";
            $result_hash = mysqli_query($db,$sql_hash);

           if (mysqli_num_rows($result_hash) > 0) {

                     //store login detail in array.
                    $_SESSION['user_id'] = $row['user_id'];
                    $_SESSION['first_name'] = $row['first_name'];
                    $_SESSION['last_name'] = $row['last_name'];
                    $_SESSION['user_name'] = $row['user_name'];
                    $_SESSION['is_logged_in'] = 1;
                    $_SESSION['account_type'] = 1;
                }else{
           
                     $_SESSION['user_id'] = '';
                     $_SESSION['first_name'] = '';
                     $_SESSION['last_name'] = '';
                     $_SESSION['user_name'] = '';
                     $_SESSION['is_logged_in'] = 0;
                     $_SESSION['account_type'] = 0;
                 }
        
}else{
        //check if employee login
            $sql = "SELECT * FROM hrms_employee_login WHERE user_name = '$username'";
            $result = mysqli_query($db,$sql);

        //check whether query can run or not.
        if ($result === false) {
            echo "Could not successfully run query ($sql) from DB: " . mysqli_error() .". Please contact webmaster.";
            exit;
        }

    if (mysqli_num_rows($result) > 0) {
            $row=mysqli_fetch_assoc($result);
            $salt = $row['salt'];
            $saltedPW =  $password . $salt;
            $hashedPW = hash('sha256', $saltedPW);
           $sql_hash = "SELECT * FROM hrms_employee_login where password = '$hashedPW'";
            $result_hash = mysqli_query($db,$sql_hash);
        if (mysqli_num_rows($result_hash) > 0) {
                         //store login detail in session.
                         $_SESSION['employee_login_id'] = $row['employee_login_id'];
                         $_SESSION['employee_id'] = $row['employee_id'];
                         $_SESSION['user_name'] = $row['user_name'];
                         $_SESSION['is_logged_in'] = 1;
                         $_SESSION['account_type'] = 2;
                

        }else{
                         $_SESSION['employee_login_id'] = '';
                         $_SESSION['employee_id'] = '';
                         $_SESSION['user_name'] = '';
                         $_SESSION['is_logged_in'] = 0;
                         $_SESSION['account_type'] = 0;
                
        }
    }


}

    if($_SESSION['is_logged_in']==0) {
        $this->msg = "<div class='alert alert-info'>
            Username and Password does not match. Please try again.
          </div>";

    }elseif($_SESSION['is_logged_in']==1){
          
                  if($_SESSION['account_type']==1){
                      header('Location: admin/dashboard.php');
                      exit;
                  }elseif($_SESSION['account_type']==2){
                     header('Location: employee/dashboard.php');
                  }

    }
    }}}


// <!-- 
// <style type="text/css">
// div.error { color: black;} -->