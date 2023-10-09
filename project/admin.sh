choice="y"
while [ $choice="y" ]
do
clear
echo "------WELCOME TO ADMIN MENU-----"
echo "1. Add student"
echo "2. View student details"
echo "3. Add faculty"
echo "4. View faculty details"
echo "5. Activate Student"
echo "6. Block student"
echo "7. Modify student details"
echo "8. Modify faculty details"
echo "9. logout and exit"
echo "Enter your choice: "
read ch
case $ch in
1)
echo "enter student name: "
read name
echo "enter student roll: "
read roll
echo "enter student city: "
read city
echo "enter student phone number: "
read st_no
record="$name $roll $city $st_no"
echo $record >>stud
;;
2)
echo "showing student details:"
cat stud
;;
3)
echo "enter faculty name: "
read name
echo "enter faculty ID: "
read id
echo "enter faculty city: "
read city
echo "enter faculty phone number: "
read fa_no
record="$name $id $city $fa_no"
echo $record >>fa
;;
4)
echo "showing student details:"
cat fa
;;
9)
exit
;;
*)
echo "enter valid choice"
esac
echo -ne "\n Do you want to continue[y/n]?: "
read choice;
done
