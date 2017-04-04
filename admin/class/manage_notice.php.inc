<?php 
class manage_notice{

    public $notice_id;

    public $action;
    public $msg;

//input form
	public function listform(){
global $selectcrtl;

if (!empty($_SESSION['msg'])) {
   $this->msg = $_SESSION['msg'];
}

echo<<<EOF
 <!-- Datatables -->
      <link href="https://cdn.datatables.net/1.10.9/css/dataTables.bootstrap.min.css" rel="stylesheet">
      <link href="https://cdn.datatables.net/responsive/1.0.7/css/responsive.bootstrap.min.css" rel="stylesheet">

<div class="right_col" role="main">
<div class="">
        <div class="row">
            <div class="col-md-12 col-sm-12 col-xs-12">
                <h4><a href="add_notice.php"><i class="fa fa-plus"></i> Create Notice</a></h4>
                            <div id="msg">
                               $this->msg                         
                            </div>

                            <div class="x_title">
                                    <h2>List of All Notice</h2>
                                    <div class="clearfix"></div>
                            </div>
            
                <div class='x_content'>

                        <table id="example" class="table table-hover table-bordered dt-responsive" cellspacing="0" width="100%">
                                        <thead>
                                            <tr>
                                                <th>#</th>
                                                <th>Title</th>
                                                <th>Created</th>
                                                <th>Short Description</th>
                                                <th>Last Updated</th>
                                                <th>Status</th>
                                                <th>Action</th>
                                            </tr>
                                        </thead>
                                        <tbody>

           

EOF;
$this->fetch();
echo<<<EOF
        </div>
    </div>

       <script src="https://cdn.datatables.net/1.10.9/js/jquery.dataTables.min.js"></script>
        <script src="https://cdn.datatables.net/1.10.9/js/dataTables.bootstrap.min.js"></script>
        <script src="https://cdn.datatables.net/responsive/1.0.7/js/dataTables.responsive.min.js"></script>

        <script>

$('#example').DataTable( {
    responsive: true
} );


setTimeout(function() {
    $('#msg').fadeOut('slow');
}, 3000); // <-- time in milliseconds


  function delete_notice(notice_id){
    if(confirm('Confirm to detele this Notice permanently?')){
      
              var data="action=delete&notice_id="+notice_id;
              $.ajax({url: "manage_notice.php", type: "POST", data: data, cache: false, success: function (xml) {
               window.location.reload();
              }
              });
            
        }
  }
        </script>
EOF;

$this->msg = null;
$_SESSION['msg'] = null;

	}
 public function fetch(){
     global $db;

     $sql="SELECT notice_id, title, short_description,flag,concat(hrms_notice.created,' by ', CREATEDBY.first_name,' ',CREATEDBY.last_name) as createdby,
    concat(hrms_notice.updated,' by ',UPDATEDBY.first_name,' ',UPDATEDBY.last_name) as updatedby
         FROM hrms_notice
         INNER JOIN hrms_admin CREATEDBY ON CREATEDBY.user_id = hrms_notice.createdby
         INNER JOIN hrms_admin UPDATEDBY ON UPDATEDBY.user_id = hrms_notice.updatedby ";

            $query=mysqli_query($db,$sql);
$warning_msg="This Notice Will Be Deleted. Are you sure?";
           $i=0;
            while ($row=mysqli_fetch_assoc($query)) {
                $i++;
                $notice_id = $row['notice_id'];
                $title = $row['title'];
                $short_description = $row['short_description'];
                $flag = $row['flag'];

                $createdby = $row['createdby'];
                $updatedby = $row['updatedby'];

                if ($flag == 1) {
                $flag =  '<span class="label label-success">Published</span>';
                 } else {
                 $flag =  '<span class="label label-danger">Unpublished</span>';
                }
            $str = strlen($title);
            if ($str > 50) {
                $ss = '<strong>......</strong>';
            } else {
                $ss = '&nbsp';
             } $title = substr($title, 0, 50) . $ss;

               $str = strlen($short_description);
            if ($str > 50) {
                $ss = '<strong>......</strong>';
            } else {
                $ss = '&nbsp';
             } $short_description = substr($short_description, 0, 50) . $ss;
echo<<<EOF
    <tr>
    <td >$i</td>
    <td>$title</td>
    <td>$createdby</td>
    <td>$short_description</td>
    <td>$updatedby</td>
    <td>$flag</td>

    <td >
    <a href="view_notice.php?notice_id=$notice_id" class="btn btn-info btn-xs" data-toggle="tooltip" data-placement="top" title="" data-original-title="View"><span class="fa fa-list-alt"></span> View</a>
    <a href="add_notice.php?action=edit&notice_id=$notice_id" data-original-title='Edit' class='btn btn-primary btn-xs'  data-toggle='tooltip' data-placement='top' '><i class='fa fa-pencil-square-o'></i> Edit</a>
    <a data-original-title='Delete' class='btn btn-danger btn-xs' data-toggle='tooltip' data-placement='top' onclick="delete_notice($notice_id)"><i class='fa fa-trash-o'></i> Delete</a>

     </tr>
EOF;
 }
echo "</tbody></table>";
}
//delete department
 public function delete(){
    global $db,$user_id;


     $sql = "DELETE FROM hrms_notice WHERE notice_id = $this->notice_id";
        if(mysqli_query($db,$sql)) {
              $_SESSION['msg'] ="<div class='alert alert-success'>
           Notice Successfully Deleted!
          </div>";
          return true;
        }else {
              $_SESSION['msg'] ="<div class='alert alert-info'>Cannot delete notice, please contact webmaster.</div>";
        return true;
        }
 }
}//END CLASS