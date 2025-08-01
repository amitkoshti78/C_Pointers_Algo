    //
// Created by Amit Koshti on 24.07.25.
//

#include <stdio.h>

int fun_factorial(int num) {
     int result;

    switch (num) {

        case 1:
            printf("\n You are in Factorial 1 function ");
            break;
        case 2:
            printf("\n You are in Factorial 2 function ");
            break;
        case 3:
            printf("\n You are in Factorial 3 function ");
            break;
        case 4:
            printf("\n You are in Factorial 4 function ");
            break;
        case 5:
            printf("\n You are in Factorial 5 function ");
            break;
    }
    /* base case exit criteria */
    if (num <= 1) {
        result = 1;

    } else {
        result = fun_factorial(num - 1);
        result = result * num;
    }

    printf("\n You are now returning from Factorial %d function with return value %d ", num, result);
    return result ;

        /*5 * 24  --> 4 * 6 --> 3 * 2 ---> 2 * 1  --> 1 * 1 */
}

int fun_factorial5(int num);
int fun_factorial4(int num);
int fun_factorial3(int num);
int fun_factorial2(int num);
int fun_factorial1(int num);
int fun_factorial0(int num);

int main() {
    int number_input;
    int fact_result;

    printf("\n !!!Program to calculate factorial of Number using Recursion!!!");
    printf("\n Enter number between 1 - 5 : ");

    scanf("%d", &number_input);
    if (number_input >  5) {
        printf("\n The number is greater than 5");
        return 0;
    }

    fact_result = fun_factorial(number_input);
    printf("\n Factorial of %d is : %d", number_input, fact_result);


    printf("\n\n !!!Program to calculate factorial of Number using Series of functions!!!");
    fact_result = fun_factorial5(number_input);
    printf("\n Factorial of %d is : %d", number_input, fact_result); //120

    return 0;
}

int fun_factorial5(int num) {  //5
    printf("\n You are in Factorial %d function ", num);
    int result = fun_factorial4(num - 1);
    int return_value =  num *  result;
    printf("\n You are now returning from Factorial %d function with return value %d ", num, return_value);
    return return_value;      //return 5 * fact(4)  --> return 5 * 24
}

int fun_factorial4(int num) {     //4
    printf("\n You are in Factorial %d function ", num);
    int result = fun_factorial3(num - 1);
    int return_value =  num *  result;
    printf("\n You are now returning from Factorial %d function with return value %d ", num, return_value);
    return return_value;
    //return num * fun_factorial3(num - 1);  //return 4 * fact(3)  --> return 4 * 6
}

int fun_factorial3(int num) {   //3
    printf("\n You are in Factorial %d function ", num);
    int result = fun_factorial2(num - 1);
    int return_value =  num *  result;
    printf("\n You are now returning from Factorial %d function with return value %d ", num, return_value);
    return return_value;  //return 3 * fact(2) --> return 3 * 2

}
int fun_factorial2(int num) {
    //2
    printf("\n You are in Factorial %d function ", num);
    int result = fun_factorial1(num - 1);
    int return_value =  num *  result;
    printf("\n You are now returning from Factorial %d function with return value %d ", num, return_value);
    return return_value;
}

int fun_factorial1(int num) {  //1
    printf("\n You are in Factorial %d function ", num);
    int return_value = 1;
    printf("\n You are now returning from Factorial %d function with return value %d ", num, return_value);
    return return_value;
}




