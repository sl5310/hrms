<?php

class leave_category{

  public $leave_category_id;
	public $msg;
  public $category;
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
        $hidden = "<input type='hidden' value = '$this->leave_category_id' name='leave_category_id'>";

         
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
                <h2>Leave Category </h2>
                  <div class='pull-right'>
                           <a href="leave_category.php" data-original-title='Leave Category' class='btn btn-success btn-xs'  data-toggle='tooltip' data-placement='top' data-original-title='Add Leave Category'><i class='fa fa-plus'></i> New Leave Category</a>
                  </div>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
                                    <form id="inputform" class="form-horizontal form-label-left" action="leave_category.php" method="post" data-parsley-validate>

						          <div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Leave Category <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input type="text" id="category" class="form-control col-md-7 col-xs-12" name="category" placeholder="Enter Your Leave Category" required="required" value="$this->category">
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
                <h2>Leave Category List</h2>
                 <div class="clearfix"></div>
            </div>

               <div class="x_content">
         <table id="example" class="table table-bordered table-hover dt-responsive" cellspacing="0" width="100%">
                                        <thead>
                                            <tr height="10">
                                                <th class="col-sm-1">#</th>
                                                <th class="col-sm-8">Leave Category</th>
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

    <script type="text/javascript">


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
      $sql = sprintf("INSERT INTO `hrms_leave_category`
                (`category`,`isactive`,
                  `created`,`createdby`,`updated`,`updatedby`) 
                VALUES 
                ('%s','%d',
                '%s','%d','%s','%d');"
                ,
               $this->category,$this->isactive,
               $timestamp,$user_id,$timestamp,$user_id);


        if(mysqli_query($db,$sql)) {

            $_SESSION['msg']="<div class='alert alert-success'>
           Leave Category save successfully.
          </div>";

          return true;
        }else {
           $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>Failed to Add New Leave Category due to Leave Category is already existed.</span></div>";
       return false;
        }
  }

  public function fetch(){
 global $db;

$warning_msg = "Are you want to delete this Leave Category?";
    $sql="SELECT *
    FROM hrms_leave_category";
            $query=mysqli_query($db,$sql);

           $i=0;
            while ($row=mysqli_fetch_assoc($query)) {
                $i++;
                $leave_category_id = $row['leave_category_id'];
                $category = $row['category'];
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
    <td>$isactive</td>
    <td >
    <a href="leave_category.php?action=edit&leave_category_id=$leave_category_id" data-original-title='Edit' class='btn btn-primary btn-xs'  data-toggle='tooltip' data-placement='top' data-original-title='Edit'><i class='fa fa-pencil-square-o'></i>Edit</a>

    <a href="leave_category.php?action=delete&leave_category_id=$leave_category_id" data-original-title='Delete'  onclick="return confirm('$warning_msg')" class='btn btn-danger btn-xs'  data-toggle='tooltip' data-placement='top' data-original-title='Deactive'><i class='fa fa-trash-o'></i>Delete</a>
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
    FROM hrms_leave_category
    WHERE leave_category_id = $this->leave_category_id ";
   if($query=mysqli_query($db,$sql)){
    $row=mysqli_fetch_assoc($query);
     $this->category = $row['category'];
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

  $sql= "UPDATE hrms_leave_category
  SET category = '$this->category',
   isactive = '$this->isactive',
   updated = '$timestamp',
   updatedby = '$user_id'
   WHERE leave_category_id = $this->leave_category_id ";

       if(mysqli_query($db,$sql)) {
           $_SESSION['msg']="<div class='alert alert-success'>
           Leave Category updated successfully.
          </div>";
          return true;

        }else {
             $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
          Leave Category cannot update, please contact webmaster.</span>
          </div>";
       return false;
    }

 }
 //check department in used
 public function checkDel(){
    global $db,$user_id;

    $sql = "SELECT leave_category_id FROM hrms_employee_leave
    WHERE leave_category_id = $this->leave_category_id";
    $query=mysqli_query($db,$sql);

        // if no data to show
        if (mysqli_num_rows($query) == 0) {
            return true;
        }else{

             $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
          Failed to Delete Leave Category due to this Leave Category already in used.</span>
          </div>";
          return false;
        }

 }

  public function delete(){
    global $db;

    $sql = "DELETE FROM hrms_leave_category
          WHERE leave_category_id = $this->leave_category_id";

    if(mysqli_query($db,$sql)) {
           $_SESSION['msg']="<div class='alert alert-success'>
           Leave Category deleted successfully.
          </div>";
          return true;

        }else {
             $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
          Failed to Delete Leave Category, please contact webmaster.</span>
          </div>";
       return false;
    }
 }

}