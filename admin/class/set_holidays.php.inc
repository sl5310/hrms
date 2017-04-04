<?php 
class set_holidays{

    public $holiday_id;
    public $msg;
    public $event_name;
    public $description;
    public $event_date;
    public $year;

	public function inputform($type){

    if (!empty($_SESSION['msg'])) {
   $this->msg = $_SESSION['msg'];
    }

    //if year is empty, then set this year
   if (empty($this->year)) {
   $this->year = date("Y", time());
    }

    if($type == "new"){
      $action ="save";
      $hidden = "";
    }else{
      $action ="update";
      $hidden = "<input type='hidden' value='$this->holiday_id' name='holiday_id'>";
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
                <h2>Add Holiday </h2>
                  <div class='pull-right'>
                           <a href="set_holidays.php" data-original-title='New Holiday' class='btn btn-success btn-xs'  data-toggle='tooltip' data-placement='top'><i class='fa fa-plus'></i> New Holiday</a>
                  </div>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                    <form id="inputform" class="form-horizontal form-label-left" action="set_holidays.php" method="post">

                                  <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Event Name <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input type="text" class="form-control col-md-7 col-xs-12" name="event_name" placeholder="Enter Your Event Name" required="required" value="$this->event_name">
                                            </div>
                                    </div>

                                    <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Description
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <textarea class="form-control col-md-7 col-xs-12" name="description" placeholder="Enter Your Description" value="">$this->description</textarea>
                                            </div>
                                    </div>

                                    <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Date<span class="required">*</span>
                                            </label>
                                             <div class="col-md-6 col-sm-6 col-xs-12">
                                         <input type="text" class="form-control datepicker" id="event_date" name="event_date" placeholder="yyyy-mm-dd" value="$this->event_date"> 
                                              </div>
                                    </div>


                                      <div class="ln_solid"></div>
                                        <div class="form-group">
                                            <div class="col-md-6 col-md-offset-3">

                                                <input type='submit' value='Save' class="btn btn-primary">
                                                <input type='hidden' value='$action' name='action'>
                                                $hidden
                                            </div>
                                        </div>
                                    </form>

 </div>
    <div class="clearfix"></div>

  <div class="row">
        <div class="col-md-12 col-sm-12 col-xs-12">
            <div class="x_title">
                <h2>Holiday List</h2>
                 <div class="clearfix"></div>
            </div>
        </div>
  </div>

<div class="x_content">
EOF;
$this->fetch();
echo<<<EOF
    </div>
   </div>

<script type="text/javascript">

$(function() {
   $('#event_date').datepicker({
      format: 'yyyy-mm-dd',
      autoclose: true,
      orientation: "top auto"
    });
});
$('#example').DataTable( {
    responsive: true
} );

setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 3000); // <-- time in milliseconds
</script>



EOF;
$this->msg = null;
$_SESSION['msg'] = null;
	}

//save holiday
    public function save(){
        global $db,$user_id;
          if($_SESSION['account_type']!=1){
        exit;
    }
      $timestamp= date("y/m/d H:i:s", time());
      $sql = sprintf("INSERT INTO `hrms_holiday`
                (`event_name`,`description`,`event_date`,
                  `created`,`createdby`,`updated`,`updatedby`) 
                VALUES 
                ('%s','%s','%s',
                '%s','%d','%s','%d');"
                ,
               $this->event_name,$this->description,$this->event_date,
               $timestamp,$user_id,$timestamp,$user_id); 


        if(mysqli_query($db,$sql)) {

            $_SESSION['msg']="<div class='alert alert-success'>
           Event Save Successfully!
          </div>";

          return true;
        }else {
           $_SESSION['msg']="<div class='alert alert-info'>Cannot insert record into database! due to Error no:".mysqli_errno($db)."<br/>\n</div>";
       return false;
        }
    }

//fetch holiday
    public function fetch(){
         global $db,$user_id;

         $i =0;
         $warning_msg = "Are you want to delete this Event?";
echo<<<EOF
         <table id="example" class="table table-bordered table-hover dt-responsive" cellspacing="0" width="100%" >
                                        <thead>
                                            <tr height="10">
                                                <th>#</th>
                                                <th>Event Name</th>
                                                <th>Event Date</th>
                                                <th>Description</th>
                                                <th>Action</th>
                                            </tr>
                                        </thead>
                                         <tbody>
EOF;


            $sql="SELECT * from hrms_holiday";

           if ($query=mysqli_query($db,$sql)){

                while ($row=mysqli_fetch_assoc($query)){
                    $i++;
                    $holiday_id=$row['holiday_id'];
                    $event_name=$row['event_name'];
                    $description=$row['description'];
                    $event_date=$row['event_date'];

echo<<<EOF

    <tr>
    <td>$i</td>
    <td>$event_name</td>
    <td>$event_date</td>
    <td>$description</td>
    <td>
    <a href="set_holidays.php?action=edit&holiday_id=$holiday_id" data-original-title='Edit' class='btn btn-primary btn-xs'  data-toggle='tooltip' data-placement='top' data-original-title='Edit'><i class='fa fa-pencil-square-o'></i>Edit</a>

    <a href="set_holidays.php?action=delete&holiday_id=$holiday_id" data-original-title='Delete'  onclick="return confirm('$warning_msg')" class='btn btn-danger btn-xs'  data-toggle='tooltip' data-placement='top' data-original-title='Deactive'><i class='fa fa-trash-o'></i>Delete</a>
    </td>   
     </tr>

EOF;
 }
            }else{
                $_SESSION['msg']="<div class='alert alert-info'>Cannot fetch the data from database.</div>";
             return false;
            }

echo "</tbody></table>";
    }

//edit mode fetch data to input text box
    public function edit(){
  global $db,$user_id;

   $sql="SELECT *
    FROM hrms_holiday
    WHERE holiday_id = $this->holiday_id";
   if($query=mysqli_query($db,$sql)){
    $row=mysqli_fetch_assoc($query);
     $this->event_name = $row['event_name'];
     $this->description = $row['description'];
     $this->event_date = $row['event_date'];
     return true;
  }else{

    $_SESSION['msg']="<div class='alert alert-success'>
           Cannot fetch the data, please contact Administrator.
          </div>";
          return false;
  }

 }
 public function update(){
  global $db,$user_id;

  $timestamp= date("y/m/d H:i:s", time());

   $sql="UPDATE hrms_holiday
    SET event_name = '$this->event_name',
    description = '$this->description',
    event_date = '$this->event_date',
    updated = '$timestamp',
    updatedby = $user_id
    WHERE holiday_id = $this->holiday_id ";
   if($query=mysqli_query($db,$sql)){

    $_SESSION['msg']="<div class='alert alert-success'>
    Holiday Save Successfully!
    </div>";
     return true;
  }else{

    $_SESSION['msg']="<div class='alert alert-info'>
           Cannot update the data, please contact Administrator.
          </div>";
          return false;
  }

 }

  public function delete(){
    global $db;
         $sql = "DELETE FROM hrms_holiday WHERE holiday_id = $this->holiday_id";
        if(mysqli_query($db,$sql)) {
              $_SESSION['msg'] ="<div class='alert alert-success'>
           Holiday Information Updated Successfully!
          </div>";
          return true;
        }else {
              $_SESSION['msg'] ="<div class='alert alert-info'>Holiday Information Cannot Update!</div>";
        return true;
        }
  }

}
