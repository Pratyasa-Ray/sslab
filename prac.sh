#!/bin/bash

add_record(){
	echo "Enter the Employee Name:"
	read name
	echo "Enter Employee Number:"
	read emp_number
	echo "Enter TelephoneNumber:"
	read tele

	echo "$name:$emp_number:$tele" >> employee_record.txt
	echo "Employee record added successfully"
}

delete_record(){
	echo "Enter the Employee Number to be deleted:"
	read emp_number
	grep -v "^.*:$emp_number:.*" employee_record.txt > temp.txt
	mv temp.txt employee_record.txt
	echo "Employee record deleted successfully"
}

search_record(){
	echo "Enter Employee Number to search:"
	read emp_number
	grep "^.*:$emp_number:.*" employee_record.txt
}

list_record(){
	echo "Employee Records:"
	cat employee_record.txt
}

sort_record(){
	sort -t ':' -k2 -n employee_record.txt > sorted_employee_records.txt
	echo "Employee record sorted by Employee Number"
}

#Main menu
while true; do
	echo "__________Employee Mangement Menu__________"
	echo "1. Add Employee"
	echo "2. Delete Employee Record"
	echo "3. Search Record"
	echo "4. List All Employee Records"
	echo "5. Sort Employee Record"
	echo "6. Exit"

	read choice
	case $choice in 
		1) add_record;;
		2) delete_record;;
		3) search_record;;
		4) list_record;;
		5) sort_record;;
		6) exit 0;;
		*) echo "Invalid input.";;
	esac
	echo
done

