<?php
session_start();

    if (!isset($_SESSION['is_logged_in'])) {
    	
        header("Location:../login.php");
        die;
    }

    if($_SESSION['account_type']!=1){
	    exit;
    }

require_once 'mysql.class.php'; 
include "setting.php.inc";
include "main_layout.php";
//include "header.php.inc";
$user_id=$_SESSION['user_id'];
$db = new mysqli($dbhost,$dbuser,$dbpassword,$dbname) or die ('ERROR: Could not connect to database!');
if($db->connect_errno > 0){
    die('Unable to connect to database [' . $db->connect_error . ']');
}
            mysqli_select_db($db, $dbname);
include_once("../class/SelectCtrl.inc.php");
$selectcrtl = new SelectCtrl();
?>