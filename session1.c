/******************************************************************************

Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int int_number = 4;
    int int_num1 = 6;

    char c_char = 'a';
    char c_char1 = 'h';

    float f_num = 3.14;
    float f_num1 = 10.23;

    int *p_num = &int_number;
    char *p_char = &c_char;
    float *p_float = &f_num;
    float *p_float1 = &f_num1;

    int *p_num1 = &int_num1;
    char *p_char1 = &c_char1;

    printf("Hello World \n");

    printf("Value %d --> address %p \n ", int_number, &int_number);

    printf("Value %p --> address %p --> value %d \n ", p_num, &p_num, *p_num);

    printf("Value %c --> address %p \n ", c_char, &c_char);

    printf("Value %p --> address %p --> value %x \n ", p_char, &p_char, *p_char);

    printf("Value %d --> address %p \n ", int_num1, &int_num1);

    printf("Value %p --> address %p --> value %d \n ", p_num1, &p_num1, *p_num1);

    printf("Value %c --> address %p \n ", c_char1, &c_char1);

    printf("Value %p --> address %p --> value %x \n ", p_char1, &p_char1, *p_char1);

    printf("Value %f --> address %p \n ", f_num, &f_num);

    printf("Value %p --> address %p --> value %f \n ", p_float, &p_float, *p_float);

    printf("Value %f --> address %p \n ", f_num1, &f_num1);

    printf("Value %p --> address %p --> value %f \n ", p_float1, &p_float1, *p_float1);


    return 0;
}