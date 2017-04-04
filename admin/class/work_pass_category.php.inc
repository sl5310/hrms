<?php 

class work_pass_category{

  public $work_pass_category_id;
  public $msg;
  public $category;
  public $category_code;
    public $isactive;

	public function inputform($type){

		    if (!empty($_SESSION['msg'])) {
       $this->msg = $_SESSION['msg'];
    }

    if($type == "new"){
        $checked = "Checked";
        $action = "save";
        $hidden = "";
      }else{

        $action = "update";
        $hidden = "<input type='hidden' value = '$this->work_pass_category_id' name='work_pass_category_id'>";

         
            if($this->isactive == 1){
              $checked = "Checked";
            }else{
              $checked = "";
            }
  

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
                <h2>Work Pass Category </h2>
                  <div class='pull-right'>
                           <a href="work_pass_category.php" class='btn btn-success btn-xs'  data-toggle='tooltip' data-placement='top' data-original-title='Add Work Pass Category'><i class='fa fa-plus'></i> Add Work Pass Category</a>
                  </div>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                    <form id="inputform" class="form-horizontal form-label-left" action="work_pass_category.php" method="post" data-parsley-validate>

						          	<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Work Pass Category<span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input type="text" class="form-control col-md-7 col-xs-12" id="category" name="category" placeholder="Enter Your Work Pass Category" required="required" value="$this->category">
                                            </div>
                      				</div>

						          	<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Work Pass Category Code<span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input type="text" class="form-control col-md-7 col-xs-12" id="category_code" name="category_code" placeholder="Enter Your Work Pass Category Code" required="required" value="$this->category_code">
                                            </div>
                      				</div>
                      				

                      				<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="lettersonly">Is Active<span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                            	 <input type="checkbox" name="isactive" class="flat" $checked>
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
</div>
        <div class="col-md-12 col-sm-12 col-xs-12">
            <div class="x_title">
                <h2>Work Pass Category List</h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
         <table id="example" class="table table-bordered table-hover dt-responsive" cellspacing="0" width="100%">
                                        <thead>
                                            <tr>
                                                <th>#</th>
                                                <th>Work Pass Category</th>
                                                <th>Work Pass Category Code</th>
                                                <th>Is Active </th>
                                                <th>Action</th>
                                            </tr>
                                        </thead>
                                         <tbody>

EOF;
$this->fetch();
echo<<<EOF
      </div>
</div>

      <!-- icheck -->
        <script src="../asset/js/icheck/icheck.min.js"></script>

    <script>

         
 $(document).ready(function () {

     $('input').iCheck({
          checkboxClass: 'icheckbox_flat-blue'
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

	  public function save(){
    global $db,$user_id;
     if($_SESSION['account_type']!=1){
        exit;
    }
      $timestamp= date("y/m/d H:i:s", time());
      $sql = sprintf("INSERT INTO `hrms_work_pass_category`
                (`category`,`category_code`,`isactive`,
                  `created`,`createdby`,`updated`,`updatedby`) 
                VALUES 
                ('%s','%s','%d',
                '%s','%d','%s','%d');"
                ,
               $this->category,$this->category_code,$this->isactive,
               $timestamp,$user_id,$timestamp,$user_id);


        if(mysqli_query($db,$sql)) {

            $_SESSION['msg']="<div class='alert alert-success'>
           Work Pass Category Save Successfully!
          </div>";

          return true;
        }else {
           $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
           Failed to Add New Work Pass Category due to Work Pass Category is already existed.</div></span>";
       return false;
        }
  }

	  public function fetch(){
 global $db;

$warning_msg = "Are you want to delete this Work Pass Category?";
    $sql="SELECT *
    FROM hrms_work_pass_category";
            $query=mysqli_query($db,$sql);

           $i=0;
            while ($row=mysqli_fetch_assoc($query)) {
                $i++;
                $work_pass_category_id = $row['work_pass_category_id'];
                $category = $row['category'];
                $category_code = $row['category_code'];
                $isactive = $row['isactive'];

                if ($isactive == 1) {
                $isactive =  '<span class="label label-success">Active</span>';
                 } else {
                 $isactive =  '<span class="label label-danger">Deactive</span>';
                }
              
echo<<<EOF
<form action='leave_category.php' method='post'>
    <tr>
    <td >$i</td>
    <td>$category</td>
    <td>$category_code</td>
    <td>$isactive</td>
    <td >
    <a href="work_pass_category.php?action=edit&work_pass_category_id=$work_pass_category_id" class='btn btn-primary btn-xs'  data-toggle='tooltip' data-placement='top' data-original-title='Edit'><i class='fa fa-pencil-square-o'></i>Edit</a>

    <a href="work_pass_category.php?action=delete&work_pass_category_id=$work_pass_category_id" onclick="return confirm('$warning_msg')" class='btn btn-danger btn-xs'  data-toggle='tooltip' data-placement='top' data-original-title='Deactive'><i class='fa fa-trash-o'></i>Delete</a>
    </td>   
     </tr>
</form>
EOF;
 }
echo "</tbody></table>";
}

 public function edit(){
  global $db;

   $sql="SELECT *
    FROM hrms_work_pass_category
    WHERE work_pass_category_id = $this->work_pass_category_id ";
   if($query=mysqli_query($db,$sql)){
    $row=mysqli_fetch_assoc($query);
     $this->category = $row['category'];
     $this->category_code = $row['category_code'];
     $this->isactive = $row['isactive'];
  }else{

    $_SESSION['msg']="<div class='alert alert-success'><span class='text-danger'>
           Cannot fetch the data, please contact Administrator.</span>
          </div>";
  }
 }

 public function update(){
  global $db,$user_id;

  $timestamp = date("y/m/d H:i:s", time());

  $sql= "UPDATE hrms_work_pass_category
  SET category = '$this->category',
  category_code = '$this->category_code',
   isactive = '$this->isactive',
   updated = '$timestamp',
   updatedby = '$user_id'
   WHERE work_pass_category_id = $this->work_pass_category_id ";

       if(mysqli_query($db,$sql)) {
           $_SESSION['msg']="<div class='alert alert-success'>
           Work Pass Category Updated Successfully!
          </div>";
          return true;

        }else {
             $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
         Failed to Update Work Pass Category, please contact webmaster.</span>
          </div>";
       return false;
    }

 }

 //check work pass category in used
 public function checkDel(){
    global $db,$user_id;

    $sql = "SELECT work_pass_category_id FROM hrms_employee EMP
    WHERE work_pass_category_id = $this->work_pass_category_id";
    $query=mysqli_query($db,$sql);

        // if no data to show
        if (mysqli_num_rows($query) == 0) {
            return true;
        }else{

             $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
         Failed to Delete Work Pass Category due to this Work Pass Category already in used.</span>
          </div>";
          return false;
        }

 }

  public function delete(){
    global $db;

     $sql = "DELETE FROM hrms_work_pass_category
          WHERE work_pass_category_id = $this->work_pass_category_id";

    if(mysqli_query($db,$sql)) {
           $_SESSION['msg']="<div class='alert alert-success'>
           Work Pass Category Updated Successfully!
          </div>";
          return true;

        }else {
             $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
          Failed to Delete Work Pass Category, please contact webmaster.</span>
          </div>";
       return false;
    }
 }
}