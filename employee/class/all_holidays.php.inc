<?php 
class all_holidays{
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
                        <strong>List of All Holidays</strong>
                    </div>
                </div>
                <!-- Table -->
                <table class="table table-bordered table-hover dt-responsive" cellspacing="0" width="100%" id="example">

                    <thead>
                        <tr>                                                   
                            <th class="col-sm-1">#</th>
                            <th>Event Name</th>
                            <th>Event Date</th>
                            <th>Description</th>
                            <th>Action</th>
                        </tr>
                    </thead>
                    <tbody>
EOF;
$this->get_all_holidays();
echo<<<EOF
                  

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
<script>
    $(document).ready(function() {
          $('#example').dataTable();
    });
</script>
EOF;
	}

	public function get_all_holidays(){
		global $db;

		$sql="SELECT holiday_id, event_name, event_date, description
         FROM hrms_holiday
         ORDER BY event_date asc";
         $query=mysqli_query($db,$sql);
          $i=0;
            while ($row=mysqli_fetch_assoc($query)) {
                $i++;
                $holiday_id = $row['holiday_id'];
                $event_name = $row['event_name'];
                $event_date = $row['event_date'];
                $description = $row['description'];

            $str = strlen($description);
			if ($str > 40) {
                $ss = '<strong>......</strong>';
            } else {
                $ss = '&nbsp';
             } $description = substr($description, 0, 40) . $ss;
echo<<<EOF
<tr>
    <td>$i</td>
    <td>$event_name</td>
    <td>$event_date</td>
    <td>$description</td>
    <td><a href="holiday_detail.php?holiday_id=$holiday_id" data-original-title='View' class='btn btn-info btn-xs' data-toggle='tooltip' data-placement='top' ><i class='fa fa-list-alt'></i> View</a></td>                                                                                                     
</tr>
EOF;
}
	}
}//END CLASS