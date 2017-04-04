<?php
ob_start(); ?>
<div id="main-header" class="clearfix">
    <header id="header" class="clearfix">
        <div class="stripe_color"></div>
        <div class="stripe_image"></div>
        <div class="school-logo col-sm-12">
            <div class="container">
                    <img src="../asset/images/logo.png" class="img-circle" alt="school_logo" > 
                    <div class="head">
                        <h2>Human Resource Management System</h2>
                    </div>
            </div>
        </div>
        <div class="container">
            <div class="row main">
                <nav class="navbar navbar-custom" id="header_menu" role="navigation">
                    <div class="menu-bg">
                        <nav class="main-menu navbar navbar-collapse menu-bg" role="navigation">
                            <!-- Brand and toggle get grouped for better mobile display -->
                            <div class="navbar-header menu-bg">
                                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                                    <span class="sr-only">Toggle navigation</span>
                                    <span class="icon-bar"></span>
                                    <span class="icon-bar"></span>
                                    <span class="icon-bar"></span>
                                </button>
                            </div>
                            <!-- Collect the nav links, forms, and other content for toggling -->
                            <div class="main-menu collapse navbar-collapse menu-bg" id="bs-example-navbar-collapse-1">
                                <ul class="nav navbar-nav">
                                    <li class="">
                                        <a href="dashboard.php">Home</a>
                                    </li>
                                    <li class="dropdown">
                                        <a href="#" class="dropdown-toggle" data-toggle="dropdown">Mailbox<b class="caret"></b></a>
                                        <ul class="dropdown-menu">
                                            <li class=""><a href="employee/dashboard/inbox">Inbox</a></li>
                                            <li class=""><a  href="employee/dashboard/sent">Sent</a></li>
                                        </ul>
                                    </li>
                                    <li class=""><a href="leave_application.php">Leave Application</a></li>
                                    <li class=""><a href="all_notice.php">Notice</a></li>
                                    <li class=""><a href="all_holidays.php">Holidays</a></li>

                                </ul>
                                <ul class="main-menu nav navbar-nav navbar-right">
                                    <li class="dropdown">
                                        <a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="fa fa-user"></i> Profile<b class="caret"></b></a>
                                        <ul class="dropdown-menu">
                                            <li class=""><a href="change_password.php">Change Password</a></li>
                                            <li><a href="logout.php">Logout</a></li>
                                        </ul>
                                    </li>
                                </ul>
                            </div><!-- /.navbar-collapse -->
                        </nav>
                    </div>
                </nav>
            </div>     
        </div>
    </header>
</div>