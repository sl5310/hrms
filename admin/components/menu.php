<?php
ob_start();
global $db,$img_path;
$sql="SELECT * from hrms_gsettings";
 $query=mysqli_query($db,$sql);
         if ($query === false) {
            echo "Could not successfully run query ($sql) from DB: " . mysqli_error() .". Please contact webmaster.";
            exit;
        }
    if (mysqli_num_rows($query) > 0) {
            $row=mysqli_fetch_assoc($query);
  $name=$row['name'];
    }
?>

<title>
Human Resource Management System
</title>
<body class="nav-md">
    <div class="container body">
        <div class="main_container">
            <div class="col-md-3 left_col">
                <div class="left_col scroll-view">
                     <div class="navbar nav_title" style="border: 0;">
                        <a href="dashboard.php" class="site_title"><img style="width:50px;height:50px;margin:10px;" class="img-circle profile_img"
                        src="../asset/images/logo.png" alt="..." ><span>Admin Panel</span></a>
                    </div>
                    <div class="clearfix"></div>
                    <div class="profile">
                        <div class="profile_pic">
                            <img src="../asset/images/admin.png" alt="..." class="img-circle profile_img">
                        </div>
                        <div class="profile_info">
                            <span>Welcome,</span>
                            <h2><?php echo $_SESSION['first_name']." ",$_SESSION['last_name']?></h2>
                        </div>
                    </div>
                    <br/>
                    <div id="sidebar-menu" class="main_menu_side hidden-print main_menu">
                        <div class="menu_section">
                            <h3>General</h3>
                                <ul class="nav side-menu">
<?php
    $main_menu = mysqli_query($db,"SELECT * FROM hrms_tbl_menu WHERE parent=0 ORDER BY sort ASC");
        while($row = $main_menu->fetch_assoc()){
            echo"<li><a href='".$row['link']."'><i class='".$row['icon']."'></i>".$row['English']."<span class='".$row['dropdown']."'></span></a>";
        $sub_menu = mysqli_query($db,"SELECT * FROM hrms_tbl_menu WHERE parent=" . $row['menu_id'] . " ORDER BY sort ASC");
            if(mysqli_num_rows($sub_menu) >0){
                echo"<ul class='nav child_menu' style='display:none'>";
                while($rowSub = $sub_menu->fetch_assoc()){
                    echo"<li><a href='".$rowSub['link']."'><i class='".$rowSub['icon']."'></i>".$rowSub['English']."</a></li>";
                 }
                 echo"</ul>";
            }
            echo"</li>";
};
?>
                                </ul>
                        </div>
                    </div>
                </div>
             </div>

             <!-- top navigation -->
            <div class="top_nav">
                <div class="nav_menu">
                    <nav class="" role="navigation">
                        <div class="nav toggle">
                            <a id="menu_toggle"><i class="fa fa-bars"></i></a>
                        </div>         

                        <ul class="nav navbar-nav navbar-right">
                            <li class="">
                                <a href="javascript:;" class="user-profile dropdown-toggle" data-toggle="dropdown" aria-expanded="false">
                                    <img src="../asset/images/admin.png" alt=""><?php echo $_SESSION['first_name']." ",$_SESSION['last_name']?>
                                    <span class=" fa fa-angle-down"></span>
                                </a>
                                <ul class="dropdown-menu dropdown-usermenu animated fadeInDown pull-right">
                                    <li><a href="update_profile.php">  Update Profile</a>
                                    </li>
                                    <li><a href="logout.php"><i class="fa fa-sign-out pull-right"></i> Log Out</a>
                                    </li>
                                </ul>
                            </li>

                            <li role="presentation" class="dropdown">

                                <a href="javascript:;" class="dropdown-toggle info-number" data-toggle="dropdown" aria-expanded="false">
                                 <i class="fa fa-flag-o"></i>
<?php 
//count total application is unview.
     $query = mysqli_query($db,"SELECT COUNT(*) as total_application FROM hrms_application_list WHERE application_status = 1");
    $row=mysqli_fetch_assoc($query);
    echo "<span class='badge bg-red'>".$row['total_application']."</span>";
?>
                                </a>

                                <ul id="menu1" class="dropdown-menu list-unstyled msg_list animated fadeInDown" role="menu">
<?php 
    $query = mysqli_query($db,"SELECT application_list_id as application_id, CONCAT(EMP.first_name,' ',EMP.last_name) as name, reason, APP.created
        FROM hrms_application_list APP
        INNER JOIN hrms_employee EMP ON APP.employee_id = EMP.employee_id 
        WHERE application_status = 1");
    if (mysqli_num_rows($query)>0){
    while($row=mysqli_fetch_assoc($query)){
    $name = $row['name'];
    $reason = $row['reason'];
    $created = $row['created'];
    $application_id = $row['application_id'];
     $str = strlen($reason);
            if ($str > 40) {
                $ss = '<strong>......</strong>';
            } else {
                $ss = '&nbsp';
             } $reason = substr($reason, 0, 40) . $ss;

 //$oldTime = date('h:i:s', strtotime($v_inbox_msg->send_time));
 // Past time as MySQL DATETIME value
 $oldtime = date('Y-m-d H:i:s', strtotime($created));

// Current time as MySQL DATETIME value
$csqltime = date('Y-m-d H:i:s');
// Current time as Unix timestamp
$ptime = strtotime($oldtime);
$ctime = strtotime($csqltime);

//Now calc the difference between the two
$timeDiff = floor(abs($ctime - $ptime) / 60);

//Now we need find out whether or not the time difference needs to be in
 //minutes, hours, or days
if ($timeDiff < 2) {
    $timeDiff = "Just now";
} elseif ($timeDiff > 2 && $timeDiff < 60) {
    $timeDiff = floor(abs($timeDiff)) . " minutes ago";
} elseif ($timeDiff > 60 && $timeDiff < 120) {
    $timeDiff = floor(abs($timeDiff / 60)) . " hour ago";
} elseif ($timeDiff < 1440) {
    $timeDiff = floor(abs($timeDiff / 60)) . " hours ago";
} elseif ($timeDiff > 1440 && $timeDiff < 2880) {
     $timeDiff = floor(abs($timeDiff / 1440)) . " day ago";
} elseif ($timeDiff > 2880) {
    $timeDiff = floor(abs($timeDiff / 1440)) . " days ago";
}
echo<<<EOF
<li style='cursor:pointer'>
 <a href='view_application.php?application_id=$application_id'><span><strong>$name</strong></span>
     <span class="time">$timeDiff</span>
     <span class="message">
    <strong>Reason: </strong>$reason
      </span>
    </a>
  </li>
EOF;
    }
}
?>
                                    <li>
                                        <div class="text-center">
                                            <a href='application_list.php'>
                                                <strong>See All Application</strong>
                                                <i class="fa fa-angle-right"></i>
                                            </a>
                                        </div>
                                    </li>
                                </ul>
                            </li>

                        </ul>  
                    </nav>
                </div>
            </div>
            <!-- /top navigation -->