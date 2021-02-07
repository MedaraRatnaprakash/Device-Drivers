#!/bin/bash
echo "Simple Calculator"
count=0
echo "Enter the first number"
read number1
echo "Enter the second number"
read number2
while [ 1 ]
do
echo "1.Addition"
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Division"
echo "5.Exit"
echo "Enter the choice"
read choice
case $choice in
1)count=$(echo " $number1 + $number2" | bc -l)
echo "Addition of two numbers is =" $count;;
2)count=$(echo "$number1 - $number2" | bc -l)
echo "Subtraction of two numbers is =" $count;;
3)count=$(echo "$number1 * $number2" | bc -l)
echo "Multiplication of two numbers is =" $count;;
4)count=$(echo "$number1 / $number2" | bc -l)
echo "divison is =" $count;;
5)
break;;
*)
echo "invalid choice";;
esac
done

