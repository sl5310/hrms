<?php
/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
include_once('../class/class/tcpdf/tcpdf.php');
include_once("../class/class/PHPJasperXML.inc.php");
include_once ('components/setting.php.inc');


session_start();
if (isset($_GET['user_id'])){


 $user_id=mysql_real_escape_string($_GET['user_id']);

    if(!isset($_SESSION['employee_id']) || $_SESSION['employee_id']!=$user_id){
	    exit;
    }

$PHPJasperXML = new PHPJasperXML();
//$PHPJasperXML->debugsql=true;
$PHPJasperXML->arrayParameter=array("user_id"=>$user_id);
$PHPJasperXML->load_xml_file("profile.jrxml");

$PHPJasperXML->transferDBtoArray($dbhost,$dbuser,$dbpassword,$dbname);
$PHPJasperXML->outpage("I");    //page output method I:standard output  D:Download file
}

?>
