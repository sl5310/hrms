<?php

class set_working_days {
public $msg;
public $day;
	//input form
	public function inputform(){

if (!empty($_SESSION['msg'])) {
   $this->msg = $_SESSION['msg'];
}

echo<<<EOF

 	<!-- icheck -->
        <script src="../asset/js/icheck/icheck.min.js"></script>

        <script type="text/javascript">
        $(document).ready(function () {

			 $('input').iCheck({
			    checkboxClass: 'icheckbox_flat-blue'
			  });

        });

setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 3000); // <-- time in milliseconds

        </script>

<div class="right_col" role="main">
  <div class="">
      <div class="row">
        <div class="col-md-12 col-sm-12 col-xs-12">
	                        <div id="msg">
	                           $this->msg                         
	                        </div>
	         
                                <div class="x_title">
                                    <h2>Set Working Days</h2>
                                    <div class="clearfix"></div>
                                </div>

                            
                
                <form action="set_working_days.php" method="post">
                	<div class="x_content">
                    <div class="table-responsive">
                        <table class="table table-bordered table-hover" style='font-size:13px;'>
                          <tr>
EOF;
$this->getworkingday();
echo<<<EOF
                        </tr>
                        </table>

						
                     <div class="ln_solid"></div>
                        <div class="form-group">
                            <div class="col-md-6 col-md-offset-5">
                              <input id="send" type='submit' value='Save' class="btn btn-primary">
                              <input type='hidden' value='save' name='action'>
                            </div>
                        </div>
                    </div>
                  </div>
             </form>
        </div>
      </div>
EOF;

$this->msg = null;
$_SESSION['msg'] = null;


	}

	public function getworkingday(){
		global $db;
//select day
		$sql ="SELECT * FROM hrms_days";
		$query=mysqli_query($db,$sql);
        while ($row=mysqli_fetch_array($query)){
        	$day_id=$row['day_id'];
        	$day=$row['day'];

        	//select working day
        		$sql_day = "SELECT flag FROM hrms_working_days WHERE day_id = $day_id";
        		$query_day = mysqli_query($db,$sql_day);
        		$row = mysqli_fetch_array($query_day);
        		$flag = $row['flag'];

        		//check working day is flag
        		if ($flag ==1){
        			$checked = "CHECKED";
        		}else{
        			$checked = "";
        		}
echo<<<EOF
  <td>
  <input  type="checkbox" name="day[]" value="$day_id" class="flat" $checked> $day
  </td>
EOF;
        }
	}

	public function save(){
		global $db,$user_id;
     $timestamp= date("y/m/d H:i:s", time());
		$sql = "UPDATE hrms_working_days
		SET flag = 0";
		if(mysqli_query($db,$sql)) {
			foreach ($this->day as $key ) {
                $sql_update = "UPDATE hrms_working_days
                SET flag = 1,
                updated = '$timestamp',
                updatedby = $user_id
                WHERE working_days_id = $key";
                mysqli_query($db,$sql_update);
            }
         $_SESSION['msg']="<div class='alert alert-success'>
           Working Days Successfully Updated!
          </div>";

          return true;
		}else{
			$_SESSION['msg']="<div class='alert alert-info'>$sql\nCannot insert record into database! due to Error no:".mysqli_errno($db)."<br/>\n</div>";
       
       return false;
		}

	}
}