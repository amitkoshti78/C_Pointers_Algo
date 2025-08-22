//
// Created by Amit Koshti on 07.08.25.
//
#include <stdio.h>

void add_number(int number1, int number2) {
    number1 = number1 + 20;
    number2 = number2 + 40;
    printf("\n Value of parameter1 is %d \n", number1);
    printf("Value of parameter2 is %d \n", number2);
    printf("Addr parameter1 is %p \n", &number1);
    printf("Addr parameter2 is %p \n", &number2);

}

void add_number_ptr(int *number1, int *number2) {  /* 0x7ff7b688a888 = 10 , 0x7ff7b688a884 = 20 */
    printf("\n\n ## Passed by Reference using pointer ### \n");

    printf("\n Pointing to num1 value : %d \n", *number1);
    printf("Pointing to num2 value : %d \n", *number2);
    printf("Passed address of num1 : %p \n", number1);
    printf("Passed address of num2 : %p \n", number2);

    *number1 = *number1 + 20;      /*0x7ff7b688a888  = 10 + 20 = 30 */
    *number2 = *number2 + 40;      /*0x7ff7b688a884 = 20 + 40 = 60 */

    printf("\n\n Pointing to num1 value : %d \n", *number1);
    printf("Pointing to num2 value : %d \n", *number2);

    printf("Addr parameter1 : %p \n", &number1);
    printf("Addr parameter2 : %p \n", &number2);

}

int main() {
    int number1;
    int number2;

    printf("\n Enter a First number : ");
    scanf("%d", &number1);
    printf("\n Enter a Second number : ");
    scanf("%d", &number2);

    printf("Address of num1 : %p and num2 : %p", &number1, &number2);

    int *p1 = &number1;
    int *p2 = &number2;

    printf("\n Value of p1 (addr of num1)   : %p and p2 (addr of num2)   : %p", p1, p2);
    printf("\n Value pointed by p1  : %d             and p2   : %d", *p1, *p2);
    printf("\n Address of p1  : %p and p2   : %p", &p1, &p2);

    add_number(number1, number2);
    printf("\n Value of num1 : %d and num2 : %d", number1, number2);

    add_number_ptr(&number1, &number2);
    printf("\n Value of num1 : %d and num2 : %d", number1, number2);


    return 0;

    /*
     *  RAM -  Main memory :  0x00000001 to 0x0099999990   Machine level code compiled program assembly lang
     *
     *         Stack  :       0x01000001 to 0x8999999991   0x7ff7b8bce888 = num1 = 10,
     *                                                     0x7ff7b8bce884 = num2 = 20,
     *                                                     0x7ff7bbbd7878   =  p1 =  0x7ff7b8bce888
     *                                                     0x7ff7bbbd7870   =  p2 = 0x7ff7b8bce884
     *                                                     0x7ff7bcc1585c  =  parameter1 = 10 + 20 = 30
     *                                                     0x7ff7bcc15858  = parameter2 = 20 + 40 = 60
     *                                                     0x7ff7b688a858 = *number1 = 0x7ff7b8bce888 = 30
     *                                                     0x7ff7b688a850 = *number2 = 0x7ff7b8bce884 = 60
     *
     *         Heap :         0x100000000 to 0X999999991
     */

}