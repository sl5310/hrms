<?php 
class set_overtime_rate{

	public $overtime_rate;
	public $hours_week;
	public $msg;
	public $action;
  public $flag;
	public function inputform(){

    if (!empty($_SESSION['msg'])) {
   $this->msg = $_SESSION['msg'];
    }

            if($this->flag == 1){
              $checked = "Checked";
            }else{
              $checked = "";
            }
echo<<<EOF
      <!-- icheck -->
      <script src="/aspirez_hrms/application/asset/js/icheck/icheck.min.js"></script>
<script>
 $(document).ready(function () {

     $('input').iCheck({
          checkboxClass: 'icheckbox_flat-blue'
        });
});
setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 2000); // <-- time in milliseconds


</script>
<div class="right_col" role="main">
  <div class="">
      <div class="row">
        <div class="col-md-12 col-sm-12 col-xs-12">
              <div id="msg">
              $this->msg                         
              </div>

            <div class="x_title">
                <h2>Set Overtime Rate</h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                    <form id="inputform" class="form-horizontal form-label-left" action="set_overtime_rate.php" method="post" >

                                  <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Overtime rate <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input type="number" step="any" class="form-control col-md-7 col-xs-12" name="overtime_rate" placeholder="Enter Your Overtime Rate" required="required" value="$this->overtime_rate">
                                            </div>
                                    </div>

                                    <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">No. of hours worken in a week <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                 <input type="number" step="any" class="form-control col-md-7 col-xs-12" name="hours_week" placeholder="No.of hours worken in a week" required="required" value="$this->hours_week">
                                            </div>
                                    </div>

                                    <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Is Active 
                                            <abbr title="When this section is set and is active, you can caluclate overtime pay at Payroll Management > Employee Salary List > Make Payment"><i class="fa fa-question-circle"></i></abbr>
                                            <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                               <input type="checkbox" name="flag" class="flat" $checked>
                                            </div>
                                    </div>

                                      <div class="ln_solid"></div>
                                        <div class="form-group">
                                            <div class="col-md-6 col-md-offset-3">

                                                <input type='submit' value='Save' class="btn btn-primary">
                                                <input type='hidden' value='$this->action' name='action'>
                                            </div>
                                        </div>
                                    </form>

 </div>
<div class="clearfix"></div>
  <div class="x_title">
                <h2>Formula of Calculate Overtime Pay</h2>
                 <div class="clearfix"></div>
            </div>
<div class="x_content">
 		<div class="bs-example" data-example-id="simple-jumbotron">
                                    <div class="jumbotron">
                                        <h4><strong>Overtime pay = </strong></h4>
                                        <p><h4>Hourly basic rate of pay x Overtime rate x Number of hours worked overtime</h4></p>
                                        <h4><strong>Hourly basic rate of pay =</strong></h4>
                                        <p><h4>(12 x Monthly basic rate of pay) / (52 x No.of hours worken in a week)</h4></p>
                                        <small>Reference : <a href="http://www.mom.gov.sg/employment-practices/calculate-overtime-pay" target="_blank">Ministry of Manpower Singapore</a></small>
                                    </div>
        </div>
</div>
EOF;
$this->msg = null;
$_SESSION['msg'] = null;
	}

	public function checkexist(){
    global $user_id,$db;
     $sql="SELECT * from hrms_overtime_rate";
     $result = mysqli_query($db,$sql);
     if ($result === false) {
            echo "Could not successfully run query ($sql) from DB: " . mysqli_error() .". Please contact webmaster.";
            exit;
        }

     if (mysqli_num_rows($result) > 0) {
        $this->action="update";
     }else{
         $this->action="save";
     }
}

//save function
    public function save(){
         global $user_id,$db;
    if($_SESSION['account_type']!=1){
        exit;
    }
      $timestamp= date("y/m/d H:i:s", time());
      $sql = sprintf("INSERT INTO `hrms_overtime_rate`
                (`overtime_rate`,`hours_worken_week`,
                  `created`,`createdby`,`updated`,`updatedby`) 
                VALUES 
                ('%s','%s',
                '%s','%d','%s','%d');"
                ,
               $this->overtime_rate,$this->hours_week,
               $timestamp,$user_id,$timestamp,$user_id); 

        if(mysqli_query($db,$sql)) {

            $_SESSION['msg']="<div class='alert alert-success'>
           Overtime Rate Save Successfully!
          </div>";

          return true;
        }else {
           $_SESSION['msg']="<div class='alert alert-info'>Cannot insert record into database! due to Error no:".mysqli_errno($db)."<br/>\n</div>";
       return false;
        }
    }
//fetch function
    public function fetch(){
         global $user_id,$db;

    $sql="SELECT * from hrms_overtime_rate";
            
            $query=mysqli_query($db,$sql);
            $row=mysqli_fetch_assoc($query);
            $this->overtime_rate=$row['overtime_rate'];
            $this->hours_week=$row['hours_worken_week'];
            $this->flag=$row['flag'];



    }
    //update function
    public function update(){
      global $user_id,$db;

      $timestamp= date("y/m/d H:i:s", time());
      $sql="UPDATE hrms_overtime_rate
      SET overtime_rate='$this->overtime_rate',
      hours_worken_week='$this->hours_week',
      flag = '$this->flag',
      updated='$timestamp',updatedby='$user_id'";


        if(mysqli_query($db,$sql)) {
            $_SESSION['msg']="<div class='alert alert-success'>
            Overtime Rate Updated Successfully!
          </div>";
          return true;
        }else {
             $_SESSION['msg']="<div class='alert alert-info'>
              Overtime Rate Cannot Update!</div>";
       
       return false;
        }


}
}
?>