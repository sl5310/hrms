<?php
/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
include_once('../class/class/tcpdf/tcpdf.php');
include_once("../class/class/PHPJasperXML.inc.php");
include_once ('components/setting.php.inc');

session_start();
if (isset($_GET['employee_id'])){

 $employee_id=mysql_real_escape_string($_GET['employee_id']);

    if(!isset($_SESSION['account_type']) || $_SESSION['account_type']!=1){
	    exit;
    }

$PHPJasperXML = new PHPJasperXML();
//$PHPJasperXML->debugsql=true;
$PHPJasperXML->arrayParameter=array("employee_id"=>$employee_id);
$PHPJasperXML->load_xml_file("view_employee.jrxml");

$PHPJasperXML->transferDBtoArray($dbhost,$dbuser,$dbpassword,$dbname);
$PHPJasperXML->outpage("I");    //page output method I:standard output  D:Download file
}

?>
