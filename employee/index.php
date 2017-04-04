<?php session_start();

    if (($_SESSION['is_logged_in'])==1) {
        if($_SESSION['account_type']==1){
			header('Location:admin/dashboard.php');
            exit;
        }elseif($_SESSION['account_type']==2){
           header('Location:dashboard.php');
            exit;
        }
    }else{
    	 header('Location:../login.php');
            exit;
    }
?>
