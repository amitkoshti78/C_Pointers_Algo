//
// Created by Amit Koshti on 24.07.25.
//

#include <stdio.h>

int fun_factorial(int num) {

    /* base case exit criteria */
    if (num == 0) {
        return 1;
    } else {
        return num * fun_factorial(num - 1);

        /*5 * 24  --> 4 * 6 --> 3 * 2 ---> 2 * 1  --> 1 * 1 */

    }
}

int fun_factorial5(int num);
int fun_factorial4(int num);
int fun_factorial3(int num);
int fun_factorial2(int num);
int fun_factorial1(int num);
int fun_factorial0(int num);

int main() {
    int number_input;
    printf("\n !!!Program to calculate factorial of Number using Recursion!!!");
    printf("\n Enter number : ");
    scanf("%d", &number_input);
    printf("\n Factorial of %d is : %d", number_input, fun_factorial(number_input));

    printf("\n !!!Program to calculate factorial of Number using Series of functions!!!");
    printf("\n Factorial of %d is : %d", number_input, fun_factorial5(number_input)); //120

    return 0;
}

int fun_factorial5(int num) {  //5
    int result = fun_factorial4(num - 1);
    int return_value =  num *  result;
    return return_value;      //return 5 * fact(4)  --> return 5 * 24
}

int fun_factorial4(int num) {     //4
    int result = fun_factorial3(num - 1);
    int return_value =  num *  result;
    return return_value;
    //return num * fun_factorial3(num - 1);  //return 4 * fact(3)  --> return 4 * 6
}

int fun_factorial3(int num) {   //3
    return num * fun_factorial2(num - 1);  //return 3 * fact(2) --> return 3 * 2
}
int fun_factorial2(int num) {   //2
    return num * fun_factorial1(num - 1); //return 2 * fact(1) --> return 2 * 1
}
int fun_factorial1(int num) {  //1
    return num * fun_factorial0(num - 1); //return 1 * fact(0) --> return 1 * 1
}

int fun_factorial0(int num) {  //0
    return 1;
}
