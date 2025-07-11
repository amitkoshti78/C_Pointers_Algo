//
// Created by Amit Koshti on 03.07.25.
//
#include <stdio.h>

void swap_value(int *x, int *y) {

    printf("Recieved value from main %p, %p \n", x, y);
    printf("Pointing to from main %d , %d \n", *x, *y);
    *x = 400;
    *y = 500;
    printf("Changed the value in swap %d , %d \n", *x, *y);
    printf("%p, %p \n", &x, &y);
}

int main() {

    int x = 10;

    int *p1 = &x;

    int **p2 = &p1;

    int ***p3 = &p2;

    int ****p4 = &p3;

    printf("Value of x  : %d\n", x);
    printf("Address of x : %p\n", &x);
    printf("Value of p1 : %p\n", p1);
    printf("Value of *p1 : %d\n", *p1);
    printf("Address of p1 : %p\n", &p1);
    printf("Value of p2 : %p\n", p2);
    printf("Value of *p2 : %p\n", *p2);
    printf("Address of **p2 : %d\n", **p2);
    printf("Value of p3 : %p\n", p3);
    printf("Value of p4 : %p\n", p4);





}

