#include <stdio.h>

int main() {
    int int_number = 4;
    char character = 'a';

    int *i_pointer = &int_number;
    char *c_pointer = &character;

    printf("Hello World\n");

    printf("value %d , address %p \n", int_number, &int_number);
    printf("value %c , address %p \n", character, &character);

    printf("value %p , address %p, value %d \n", i_pointer, &i_pointer, *i_pointer);
    printf("value %p , address %p,  value %c \n", c_pointer, &c_pointer, *c_pointer);
    return 0;
}