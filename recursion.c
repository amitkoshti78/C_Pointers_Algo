//
// Created by Amit Koshti on 24.07.25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* calling counter function recursively */
void counter(int count) {


    /* Base case */
    if (count == 0) {
        printf("\n Returning from 0\n");
        return;
    }
    printf("Calling function counter with Count - 1  = %d\n", count - 1);
    counter(count - 1);
    printf("Returning from Current counter  = %d\n", count);
    return;
}
/* below functions are just to show how recursion works as each call of
 function is considered as separate function call */
void counter5(int count);
void counter4(int count);
void counter3(int count);
void counter2(int count);
void counter1(int count);
void counter0(int count);

int main() {

    int count = 5;

    printf("\n Main calling function counter5 with count = %d\n", count);
    counter5(count);


    printf("\n Main calling function counter recursively with count = %d\n", count);
    counter(count);
    return 0;

}

void counter5(int count) {
    printf("Calling function counter4 with Count - 1  = %d\n", count - 1);
    counter4(count - 1);
    printf("Current counter  = %d\n", count);
    return;
}

void counter4(int count) {
    printf("Calling function counter3 with Count - 1  = %d\n", count - 1);
    counter3(count - 1);
    printf("Current counter  = %d\n", count);
    return;
}

void counter3(int count) {
    printf("Calling function counter2 with Count - 1  = %d\n", count - 1);
    counter2(count - 1);
    printf("Current counter  = %d\n", count);
    return;
}

void counter2(int count) {
    printf("Calling function counter1 with Count - 1  = %d\n", count - 1);
    counter1(count - 1);
    printf("Current counter  = %d\n", count);
    return;
}

void counter1(int count) {
    printf("Calling function counter0 with Count - 1  = %d\n", count - 1);
    counter0(count - 1);
    printf("Current counter  = %d\n", count);
    return;
}

void counter0(int count) {
    return;
}

/*counter(10)  --> counter(9) --> counter(8)  --> counter(7)  --> counter(6)  --> counter(5)  --> counter(4)  --> counter(3)  --> counter(2)  --> counter(1)  --> counter(0) */

