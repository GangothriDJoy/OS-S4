#!/bin/bash
set -u
addition(){
        echo -n "Enter the first number: "
        read num1
        echo -n "Enter the second number: "
        read num2
        echo "Sum = $((num1+num2))"
}
subtraction(){
        echo -n "Enter the first number: "
        read num1
        echo -n "Enter the second number: "
        read num2
        echo "Difference = $((num1-num2))"
}
multiplication(){
        echo -n "Enter the first number: "
        read num1
        echo -n "Enter the second number: "
        read num2
        echo "Product = $((num1*num2))"
}
division(){
        echo -n "Enter the dividend: "
        read dividend
        echo -n "Enter the divisor: "
        read divisor
        if [ $divisor -eq 0 ]; then
                echo "ERROR: Division by zero is not allowed!"
        else
                echo "Result = $((dividend/divisor))"
        fi
}
modulus(){
        echo -n "Enter the first number: "
        read num1
        echo -n "Enter the second number: "
        read num2
        echo "Modulo = $((num1%num2))"
}
echo -e "MENU\n\t\ta)Addition\n\t\tb)subtraction\n\t\tc)Multiplication\n\t\td)Division\n\t\te)Modulus\n\t\tq)QUIT"
while true; do
        echo -n "Enter your choice: "
        read choice
        case $choice in
                a)addition;;
                b)subtraction;;
                c)multiplication;;
                d)division;;
                e)modulus;;
                q)echo "Exiting the program.."
                        exit;;
                *)echo "INVALID OPTION, choose again";;
        esac
done


