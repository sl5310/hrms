<?php
class print_payslip{


		public $company_name;
		public $email;
		public $company_address;
		public $mobile;
		public $hotline;
		public $email_address;
		public $logo;
		public $employment_id;
		public $employee_name;
		public $date_of_birth;
		public $identity_no;
		public $joining_date;
		public $designations_name;
		public $department_name;
		public $payslip_no;
		public $payment_month;

	public function form(){
echo<<<EOF
<table>
<tr><td>Payslip for the period of $this->payment_month</td></tr>
</table>
EOF;
	}


	public function company_info(){
		global $db;

		$sql = "SELECT
     hrms_gsettings.`name` AS company_name,
     hrms_gsettings.`email` AS email,
     concat(hrms_gsettings.`address`,' ',hrms_gsettings.`city`,' ',countries.`countryName`) as company_address,
     hrms_gsettings.`mobile` AS mobile,
     hrms_gsettings.`hotline` AS hotline,
     hrms_gsettings.`email` AS email_address,
     hrms_gsettings.`logo` AS logo,
     hrms_employee.`employment_id` AS employment_id,
     concat(hrms_employee.`first_name`,' ',hrms_employee.`last_name`) as employee_name,
     hrms_employee.`date_of_birth` AS date_of_birth,
     hrms_employee.`identity_no` AS identity_no,
     hrms_employee.`joining_date` AS joining_date,
     hrms_designations.`designations` AS designations_name,
     hrms_department.`department_name` AS department_name,
     hrms_salary_payment.`payslip_no` AS payslip_no,
     hrms_salary_payment.`payment_month` AS payment_month
     
   FROM `hrms_salary_payment` 
   INNER JOIN `hrms_employee` ON hrms_employee.employee_id = hrms_salary_payment.employee_id
   INNER JOIN `hrms_gsettings` ON hrms_gsettings.organization_id = hrms_employee.organization_id
   INNER JOIN `countries` ON countries.country_id = hrms_gsettings.country_id
   INNER JOIN `hrms_payment_type` ON hrms_payment_type.payment_type_id = hrms_salary_payment.payment_type
   INNER JOIN `hrms_designations` ON hrms_designations.designations_id = hrms_employee.designation_id
   INNER JOIN `hrms_department` ON hrms_department.department_id = hrms_designations.department_id
   where hrms_salary_payment.`payment_id` = 32";
    if ($query=mysqli_query($db,$sql)){
		$row=mysqli_fetch_assoc($query);

		$this->company_name = $row['company_name'];
		$this->email = $row['email'];
		$this->company_address = $row['company_address'];
		$this->mobile = $row['mobile'];
		$this->hotline = $row['hotline'];
		$this->email_address = $row['email_address'];
		$this->logo = $row['logo'];
		$this->employment_id = $row['employment_id'];
		$this->employee_name = $row['employee_name'];
		$this->date_of_birth = $row['date_of_birth'];
		$this->identity_no = $row['identity_no'];
		$this->joining_date = $row['joining_date'];
		$this->designations_name = $row['designations_name'];
		$this->department_name = $row['department_name'];
		$this->payslip_no = $row['payslip_no'];
		$this->payment_month = $row['payment_month'];
    }

	}
}//end class