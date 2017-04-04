<?php 
class all_notice{
	public function form(){
echo<<<EOF

    <div class="container">
        <div class="row">
            <div class="margin">    
                <div class="col-md-12">
                    <div class="main_content">
                        <div class="row">
<div class="col-md-12">
    <div class="row">
        <div class="col-sm-12" data-offset="0">                            
            <div class="panel panel-info">
                <!-- Default panel contents -->

                <div class="panel-heading">
                    <div class="panel-title">                 
                        <strong>List of All Notices</strong>
                    </div>
                </div>
                <!-- Table -->
                <div class="panel-body ">
                <table id="example" class="table table-bordered table-hover dt-responsive" cellspacing="0" width="100%">
                    <thead>
                        <tr>                                                   
                            <th class="col-sm-1">#</th>
                            <th >Created</th>
                            <th >Title</th>
                            <th>Short Description</th>
                            <th >Last Updated</th>
                            <th>Action</th>
                        </tr>
                    </thead>
EOF;
$this->get_all_notice();
echo<<<EOF
                    <tbody>

                    </tbody>
                </table>
                </div>     
            </div>
        </div>
    </div>        
</div>
					</div>
        		</div>
	        </div>
        </div>
    </div>        
</div>

<script>
    $(document).ready(function() {
          $('#example').dataTable();
    });
</script>
EOF;
	}

	public function get_all_notice(){
		global $db;

		 $sql="SELECT notice_id, title, short_description,concat(hrms_notice.created,' by ', CREATEDBY.first_name,' ',CREATEDBY.last_name) as createdby,
    concat(hrms_notice.updated,' by ',UPDATEDBY.first_name,' ',UPDATEDBY.last_name) as updatedby
         FROM hrms_notice
         INNER JOIN hrms_admin CREATEDBY ON CREATEDBY.user_id = hrms_notice.createdby
         INNER JOIN hrms_admin UPDATEDBY ON UPDATEDBY.user_id = hrms_notice.updatedby
         WHERE flag = 1
         ORDER BY hrms_notice.updated ASC";
         $query=mysqli_query($db,$sql);
          $i=0;
            while ($row=mysqli_fetch_assoc($query)) {
                $i++;
                $notice_id = $row['notice_id'];
                $title = $row['title'];
                $short_description = $row['short_description'];

                $createdby = $row['createdby'];
                $updatedby = $row['updatedby'];
            $str = strlen($short_description);
			if ($str > 40) {
                $ss = '<strong>......</strong>';
            } else {
                $ss = '&nbsp';
             } $short_description = substr($short_description, 0, 40) . $ss;
echo<<<EOF
<tr>
    <td>$i</td>
    <td>$createdby</td>
    <td>$title</td>
    <td>$short_description</td>
    <td>$updatedby</td>
    <td><a href="notice_detail.php?notice_id=$notice_id" data-original-title='View' class='btn btn-info btn-xs' data-toggle='tooltip' data-placement='top' ><i class='fa fa-list-alt'></i> View</a></td>                                                                                                     
</tr>
EOF;
}
	}
}//END CLASS