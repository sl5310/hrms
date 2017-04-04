<?php 
class general_setting{

    public $name;
    public $logo;
    public $full_path;
    public $email;
    public $address;
    public $city;
    public $country_id;
    public $phone;
    public $mobile;
    public $hotline;
    public $fax;
    public $website;
    public $currency;
    public $action;
    public $msg;

//input form
	public function inputform(){
global $selectcrtl,$up_path;

$countries=$selectcrtl->getSelectCountries($this->country_id,'Y');
$currency=$selectcrtl->getSelectCurrency($this->currency,'Y');
if (!empty($_SESSION['msg'])) {
   $this->msg = $_SESSION['msg'];
}

echo<<<EOF
        <script type="text/javascript">
            $(document).ready(function () {

                $.listen('parsley:field:validate', function () {
                    validateFront();
                });
                $('#inputform .btn').on('click', function () {
                    $('#inputform').parsley().validate();
                    validateFront();
                });
                var validateFront = function () {
                    if (true === $('#inputform').parsley().isValid()) {
                        $('.bs-callout-info').removeClass('hidden');
                        $('.bs-callout-warning').addClass('hidden');
                    } else {
                        $('.bs-callout-info').addClass('hidden');
                        $('.bs-callout-warning').removeClass('hidden');
                    }
                };
            });

            try {
                hljs.initHighlightingOnLoad();
            } catch (err) {}


        function readURL(input) {

            if (input.files && input.files[0]) {
                var reader = new FileReader();
                reader.onload = function (e) {
                    $('#preview').attr('src', e.target.result);
                }

                reader.readAsDataURL(input.files[0]);
            }
        }

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
                                    <h2>General Setting</h2>
                                    <div class="clearfix"></div>
                                </div>

                                 <div class="x_content">

                                    <form id="inputform" class="form-horizontal form-label-left" action="general_setting.php" method="post" data-parsley-validate enctype="multipart/form-data">

											<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="name">Company Name <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input id="name" class="form-control col-md-7 col-xs-12" name="name" placeholder="Enter Your Company Name" required="required" type="text" value="$this->name">
                                            </div>
                                        	</div>

                                        	<div class="item form-group">
                                            
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" >Logo</label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                            
                                            <div class="fileupload-preview thumbnail" style="width: 200px; height: 150px;">
                                            <img id="preview" src="$up_path/logo/$this->logo" alt="Your Company Logo" /></div>
                                            <span class="btn btn-default btn-file">
  
                                            <input id="logo" name="logo" type="file" class="file"  accept="image/*" onchange="readURL(this);">
                              
                                        	</span>
     
                                        	</div>
                                        	</div>


                                        	<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="email">Email Address <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                             <input type="email" id="email" class="form-control" name="email" data-parsley-trigger="change" placeholder="Enter Your Email Address" required="required" value="$this->email">
                                            </div>
                                        	</div>

                                        	<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="address">Address <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input id="address" class="form-control col-md-7 col-xs-12" name="address" placeholder="Enter Your Company Address" required="required" type="text" value="$this->address">
                                            </div>
                                        	</div>

                                        	<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="city">City
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input id="city" class="form-control col-md-7 col-xs-12" name="city" placeholder="Enter City" type="text" value="$this->city">
                                            </div>
                                        	</div>

        									<div class="form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12">Country <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                            	<select name='country_id' class="select2_single form-control" tabindex="-1" required="required">
                                            		$countries
                                            	</select>
                                            </div>
                                        	</div>

                                        	<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="phone">Phone
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input id="phone" class="form-control col-md-7 col-xs-12" name="phone" type="number" placeholder="Enter Your Phone Number" value="$this->phone">
                                            </div>
                                        	</div>

                                        	<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="number">Mobile <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input id="mobile" class="form-control col-md-7 col-xs-12" name="mobile" placeholder="Enter Your Mobile Number" required="required" type="number" value="$this->mobile">
                                            </div>
                                        	</div>

                                        	<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="number">Hotline <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input id="hotline" class="form-control col-md-7 col-xs-12" name="hotline"  placeholder="Enter Your Hotline Number" required="required" type="number" value="$this->hotline">
                                            </div>
                                        	</div>

                                        	<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="fax">Fax
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input id="fax" class="form-control col-md-7 col-xs-12" name="fax" placeholder="Enter Your Fax Number" type="number" value="$this->fax">
                                            </div>
                                        	</div>

                                        	<div class="item form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12" for="website">Website
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <input id="website" class="form-control col-md-7 col-xs-12" name="website"  placeholder="Enter Your Website Address" type="text" value="$this->website">
                                            </div>
                                        	</div>

                                            <div class="form-group">
                                            <label class="control-label col-md-3 col-sm-3 col-xs-12">Currency <span class="required">*</span>
                                            </label>
                                            <div class="col-md-6 col-sm-6 col-xs-12">
                                                <select name='currency' class="form-control" required="required">
                                                    $currency
                                                </select>
                                            </div>
                                            </div>
                                            

                                      <div class="ln_solid"></div>
                                        <div class="form-group">
                                            <div class="col-md-6 col-md-offset-3">

                                                <input id="send" type='submit' value='Save' class="btn btn-primary">
                                                <input type='hidden' value='$this->action' name='action'>
                                            </div>
                                        </div>

                                    </form>
                                

                            </div>
               

EOF;

$this->msg = null;
$_SESSION['msg'] = null;

	}

public function checkexist(){
    global $user_id,$db;
     $sql="SELECT * from hrms_gsettings";
     $result = mysqli_query($db,$sql);
     if ($result === false) {
            echo "Could not successfully run query. Please contact webmaster.";
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
      $sql = sprintf("INSERT INTO `hrms_gsettings`
                (`name`,`logo`,`full_path`,`email`,`address`,
                `city`,`country_id`,`phone`,`mobile`,`hotline`,`fax`,
                  `website`,`currency`,`updated`,`updatedby`) 
                VALUES 
                ('%s','%s','%s','%s','%s',
                '%s','%d','%d','%d','%d','%d',
                '%s','%d','%s','%d');"
                ,
               $this->name,$this->logo,$this->full_path,$this->email,$this->address,$this->city,$this->country_id,$this->phone,$this->mobile,$this->hotline,$this->fax,
               $this->website,$this->currency,$timestamp,$user_id); 


        if(mysqli_query($db,$sql)) {

            $_SESSION['msg']="<div class='alert alert-success'>
           Company Information Successfully Updated!
          </div>";

          return true;
        }else {
           $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
           Failed to Save General Setting, please contact webmaster.</span></div>";
       return false;
        }
    }

//fetch function
    public function fetch(){
         global $user_id,$db;

    $sql="SELECT * from hrms_gsettings";

            $query=mysqli_query($db,$sql);
            $row=mysqli_fetch_assoc($query);
            $this->name=$row['name'];
            $this->logo=$row['logo'];
            $this->email=$row['email'];
            $this->address=$row['address'];

            $this->city=$row['city'];
            $this->country_id=$row['country_id'];
            $this->phone=$row['phone'];
            $this->mobile=$row['mobile'];

            $this->hotline=$row['hotline'];
            $this->fax=$row['fax'];
            $this->website=$row['website'];
            $this->currency=$row['currency'];


    }

//update function
    public function update(){
      global $user_id,$db,$upload_path;

if(!empty($_FILES['logo']['name'])){
    $errors= array();
    $logo_name = $_FILES['logo']['name'];
    $file_size =$_FILES['logo']['size'];
    $file_tmp =$_FILES['logo']['tmp_name'];
    $file_type=$_FILES['logo']['type'];   
    $file_ext=strtolower(end(explode('.',$_FILES['logo']['name'])));
    $extensions = array("jpeg","jpg","png");        
    if(in_array($file_ext,$extensions )=== false){
     $errors[]="extension not allowed, please choose a JPEG or PNG file.";
    }
    if($file_size > 2097152){
    $errors[]='File size must be excately 2 MB';
    }       
}

    if ($logo_name==""){
        $filter = "";
    }else{
        $this->unlink($logo_name);
        $filter = ",logo='$logo_name'";
    }
      $timestamp= date("y/m/d H:i:s", time());
      $sql="UPDATE hrms_gsettings
      SET name='$this->name',
      email='$this->email',
      address='$this->address',
      city='$this->city',
      country_id='$this->country_id',
      phone='$this->phone',
      mobile='$this->mobile',
      hotline='$this->hotline',
      fax='$this->fax',
      website='$this->website',
      currency='$this->currency',
      updated='$timestamp',updatedby='$user_id'
      $filter";


        if(mysqli_query($db,$sql)) {
        if(empty($errors)==true){

            move_uploaded_file($file_tmp,$upload_path."/logo/".$logo_name);

        }else{
            print_r($errors);
        }
            $_SESSION['msg']="<div class='alert alert-success'>
           Company Information Successfully Updated!
          </div>";


          return true;

        }else {
             $_SESSION['msg']="<div class='alert alert-info'><span class='text-danger'>
             Failed to Update General Setting, please contact webmaster.</span></div>";
       
       return false;
        }


}

//delete file from folder
    public function unlink($logo_name){
        global $db,$upload_path;

  $sql = "SELECT logo FROM hrms_gsettings";
        $query=mysqli_query($db,$sql);
        $row=mysqli_fetch_assoc($query);
        $logo = $row['logo'];

        if($logo != $logo_name){
        unlink($upload_path."/logo/".$logo);
        }


}
}