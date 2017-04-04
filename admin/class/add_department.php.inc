<?php
class add_department{

public $department_id;
public $department_name;
public $department_code;
public $designations;
public $action;
public $msg;
	public function inputform($type){
    if (!empty($_SESSION['msg'])) {
       $this->msg = $_SESSION['msg'];
    }

    if($type=="new"){
      $title = "Add Department";
      $action = "save";
      $hidden ="";
    }elseif($type=="edit"){
      $title = "Edit Department";
      $action = "update";
      $hidden = "<input type='hidden' value='$this->department_id' name='department_id'>";
    }

echo<<<EOF
    <script type="text/javascript" src="../asset/js/jquery.min.js"></script>
<script type="text/javascript">
    $(document).ready(function() {
                var maxAppend = 0;
        $("#add_more").click(function() {
            if (maxAppend >= 9)
            {
                alert("Maximum 10 File is allowed");
            } else {
                var add_new ='<div class="form-group">'
                +'<label for="field-1" class="col-sm-3 control-label"></label>'
                +'<div class="col-sm-5"><input type="text" name="designations[]" class="form-control" placeholder="Enter Your Designations" required="required"/>'
    			+'</div>'
    			+'<div class="col-sm-2">'
    			+'<strong><a href="javascript:void(0);" class="remCF"><i class="fa fa-times"></i>&nbsp;Remove</a></strong>'
    +'</div>';
                maxAppend++;
                $("#add_new").append(add_new);
            }
        });

        $("#add_new").on('click', '.remCF', function() {
            $(this).parent().parent().parent().remove();
        });


    });

setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 2000); // <-- time in milliseconds

  function delete_designation(designation_id){
    if(confirm('Confirm to detele this designation permanently?')){

            var department_id = "$this->department_id"; 
      
              var data="action=delete&department_id="+department_id+"&designation_id="+designation_id;
              $.ajax({url: "add_department.php", type: "POST", data: data, cache: false, success: function (xml) {
               alert("Department Information Successfully Updated!");
               window.location.reload();
              }
              });
            
        }
  }
</script>


	<div class="right_col" role="main">
  <div class="">
      <div class="row">
        <div class="col-md-12 col-sm-12 col-xs-12">
            <div id="msg">
            $this->msg                         
            </div>
            <div class="x_title">
                <h2>$title</h2>
                <div class='pull-right'>
                   <a href="department_list.php" data-original-title='Department List' class='btn btn-success btn-xs'  data-toggle='tooltip' data-placement='top'><i class='fa fa-list'></i> Department List</a>
                    </div>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                    <form id="inputform" class="form-horizontal form-label-left" action="add_department.php" method="post" data-parsley-validate>

											<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Add Department <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input type="text" id="department_name" class="form-control col-md-7 col-xs-12" name="department_name" placeholder="Enter Your Department Name" required="required" value="$this->department_name">
                                            </div>
                      </div>

                      <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="lettersonly">Add Department Code <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input   type="text" id="department_name" class="form-control col-md-7 col-xs-12" name="department_code" placeholder="Enter Your Department Code" required="required" value="$this->department_code" data-parsley-pattern="^[a-zA-Z]+$">
                                            </div>
                      </div>

                      <div id="add_new">
EOF;
  if ($type == "new"){
    echo<<<EOF
 								       <div class="form-group">
                                    <label for="field-1" class="col-sm-3 control-label">Add Designations <span class="required"> *</span></label>

                                    <div class="col-sm-5">                            
                                        <input type="text" name="designations[]" class="form-control" placeholder="Enter Your Designations" required="required" value="$this->designations"/>
                                    </div>                           
                                    <div class="col-sm-2">                            
                                        <strong><a href="javascript:void(0);" id="add_more" class="addCF "><i class="fa fa-plus"></i>&nbsp;Add More</a></strong>
                                    </div>
                      </div>
                      
EOF;
  }elseif ($type == "edit") {
    $this->fetch_designations();
  }
echo<<<EOF
                      </div>

                                      <div class="ln_solid"></div>
                                        <div class="form-group">
                                            <div class="col-md-6 col-md-offset-3">

                                                <input id="send" type='submit' value='Save' class="btn btn-primary">
                                                <input type='hidden' value='$action' name='action'>
                                                $hidden
                                            </div>
                                        </div>

                                    </form>
                          		
      </div>
EOF;
$this->msg = null;
$_SESSION['msg'] = null;
	}

//get maximun department id
 public function getMaxID(){
      global $user_id,$db;

      $sql="SELECT MAX(department_id) From hrms_department";
      $query = mysqli_query($db,$sql);
      $row = mysqli_fetch_assoc($query);
      return $row['MAX(department_id)'];

}

//check department name exist
public function checkExistDep(){
  global $db,$user_id;
  $sql = "SELECT * FROM hrms_department WHERE department_name = '$this->department_name'";
      $result = mysqli_query($db,$sql);
      //check if departname name exist redirect to department page else return true
      if (mysqli_num_rows($result) > 0) {
        $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
                          Faild to Add New Department due to Department / Department Code is already existed!</span>
                          </div>";
        header("Location: department_list.php");
        exit;
      }else{
        return true;
      }

  return $result;
}

//check designation name under same department exist
public function checkExistDes($designations_id){
  global $db,$user_id;
  $sql = "SELECT designations_id,designations FROM hrms_designations WHERE designations_id = $designations_id AND department_id = $this->department_id";
      $result = mysqli_query($db,$sql);
      //check if departname name exist redirect to department page else return true

      if (mysqli_num_rows($result) > 0) {
        $row=mysqli_fetch_assoc($result);

        $designations_id = $row['designations_id'];
        $result = "update";
        
      }else{
        $result = "insert";

      }

  return $result;
}

//save department infomation
public function save_department(){
		global $db,$user_id;
	$timestamp= date("y/m/d H:i:s", time());

  // check department exist
  $this->checkExistDep();
      //else save
      $sql = sprintf("INSERT INTO `hrms_department`
                (`department_name`,`department_code`,`created`,`createdby`,`updated`,`updatedby`) 
                VALUES 
                ('%s','%s','%s','%d','%s','%d');"
                ,$this->department_name,$this->department_code,$timestamp,$user_id,$timestamp,$user_id); 
      //insert department
      	if(mysqli_query($db,$sql)) {
              $_SESSION['msg']="<div class='alert alert-success'>
                 					Department Information Successfully Saved!
                					</div>";
             return true;
          }else{
              $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
              Failed to Add New Department, please contact webmaster.</span></div>";
          
           return false;
       	}
}


//save designation infomation
 public function save_designation(){
  global $db,$user_id;

  $timestamp= date("y/m/d H:i:s", time());
            //get max depatment id
          $department_id = $this->getMaxID();

        $sql = sprintf("INSERT INTO `hrms_designations`
                (`department_id`,`designations`,`created`,`createdby`,`updated`,`updatedby`) 
                VALUES 
                ('%d','%s','%s','%d','%s','%d');"
                ,$department_id,$this->designations,$timestamp,$user_id,$timestamp,$user_id); 

    //insert designation
   if(mysqli_query($db,$sql)) {
        $_SESSION['msg']="<div class='alert alert-success'>
                    Department Information Successfully Saved!
                    </div>";
         return true;
    }else{
      $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
      Failed to Add Designation, please contact webmaster.</span></div>";
    return true;
    }
            
 }

//update department infomation
 public function update_department(){
  global $db,$user_id;
  $timestamp= date("y/m/d H:i:s", time());

  //else update
  $sql="UPDATE hrms_department
      SET department_name='$this->department_name',
      department_code='$this->department_code',
      updated='$timestamp',updatedby='$user_id'
      WHERE department_id = $this->department_id ";

    if(mysqli_query($db,$sql)) {
           $_SESSION['msg']="<div class='alert alert-success'>
           Department Information Successfully Updated!
          </div>";
          return true;

        }else {
             $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
          Failed to Update Department due to Department / Department Code are already existed.</span>
          </div>";
        header("Location: department_list.php");
       return false;
    }

 }

 //update designation infomation
 public function update_designation($designations_id){
  global $db,$user_id;
  $timestamp= date("y/m/d H:i:s", time());

  //check designation name existed
  $result = $this->checkExistDes($designations_id);

  if($result == "update"){

   $sql=sprintf("UPDATE hrms_designations
      SET designations='$this->designations',
      updated='$timestamp',updatedby='$user_id'
      WHERE designations_id = $designations_id ");
    }else{

      $sql = sprintf("INSERT INTO `hrms_designations`
                (`department_id`,`designations`,`created`,`createdby`,`updated`,`updatedby`) 
                VALUES 
                ('%d','%s','%s','%d','%s','%d');"
                ,$this->department_id,$this->designations,$timestamp,$user_id,$timestamp,$user_id); 
    }
    if(mysqli_query($db,$sql)) {
           $_SESSION['msg']="<div class='alert alert-success'>
           Department Information Successfully Updated!
          </div>";
          return true;

        }else {
             $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
             Failed to Update Designation, please contact webmaster.</div>";
        header("Location: department_list.php");
       return false;
    }

 }

//delete designation 
   public function delete($designations_id){
    global $db,$user_id;

    $sql = "DELETE FROM hrms_designations WHERE designations_id = $designations_id";
        if(mysqli_query($db,$sql)) {
              $_SESSION['msg'] ="<div class='alert alert-success'>
           designations_id Information Successfully Delete!
          </div>";
          return true;
        }else {
              $_SESSION['msg'] ="<div class='alert alert-info'><span class='text-danger'>
              Failed to Delete Designation, please contact webmaster.</span></div>";
               header("Location: department_list.php");
        return false;
        }
 }

// fetch department information from database
    public function fetch(){
         global $user_id,$db;
    // select department
    $sql="SELECT department_name,department_code from hrms_department
          WHERE department_id = $this->department_id";

    $query=mysqli_query($db,$sql);
            if (!$query) {
        echo 'MySQL Error: ' . mysqli_error();
        exit;
    }
          // fetch department_name to input text
           $row=mysqli_fetch_assoc($query);
           $this->department_name = $row['department_name'];
           $this->department_code = $row['department_code'];

          }

// fetch designation information from database  
    public function fetch_designations(){
      global $user_id,$db;

    $i=0;
    // select designation
    $sql="SELECT designations_id,designations from hrms_designations
          WHERE department_id = $this->department_id";

    $query=mysqli_query($db,$sql);

            if (!$query) {
        echo 'MySQL Error: ' . mysqli_error();
        exit;
    }
          $results = array();
          while ($row=mysqli_fetch_assoc($query)) {
            $i++;
            $designations_id=$row['designations_id'];
            $designations=$row['designations'];
  
            // first input with label else without
            if ($i==1){
              echo<<<EOF
                    <div class="form-group">
                    <label for="field-1" class="col-sm-3 control-label">Add Designations <span class="required"> *</span></label>
                                    <div class="col-sm-5">                            
                                        <input type="text" name="designations[]" class="form-control" placeholder="Enter Your Designations" required="required" value="$designations"/>
                                    </div>                           
                                    <div class="col-sm-2">                            
                                        <strong><a href="javascript:void(0);" id="add_more" class="addCF"><i class="fa fa-plus"></i>&nbsp;Add More</a></strong>
                                    </div>
                    </div>
                    <input type='hidden' name="arr_designation_id[]" value='$designations_id'>
EOF;
            }else{
              echo<<<EOF
                    <div class="form-group">
                    <label for="field-1" class="col-sm-3 control-label"></label>
                                    <div class="col-sm-5">                            
                                        <input type="text" name="designations[]" class="form-control" placeholder="Enter Your Designations" required="required" value="$designations"/>
                                    </div>                           
                                    <div class="col-sm-2">                            
                                        <strong><a href="javascript:void(0);" onclick="delete_designation($designations_id)"><i class="fa fa-times"></i>&nbsp;Remove</a></strong>
                                    </div>
                    </div>
                    <input type='hidden' name="arr_designation_id[]" value='$designations_id'>
EOF;
            }
 

    }

  }
}