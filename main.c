#include <stdio.h>

void to_upper_char(char *lower_char) {

    if (*lower_char >= 'a' && *lower_char <= 'z') {
        *lower_char = *lower_char - 32;
    }
}

void to_lower_str(char *upper_str) {

    while (*upper_str != '\0') {
        if (*upper_str >= 'A' && *upper_str <= 'Z') {
            *upper_str = *upper_str + 32;
        }
        upper_str++;
    }
}

void multi_pointer() {
    int i = 20;

    int *p1    = &i;
    int **p2   = &p1;
    int ***p3  = &p2;
    int ****p4 = &p3;

    printf("-------------------------\n");

    printf("Addr of i  : %p \n", &i);
    printf("Addr of p1 : %p \n", &p1);
    printf("Addr of p2 : %p \n", &p2);
    printf("Addr of p3 : %p \n", &p3);
    printf("Addr of  p4 : %p \n", &p4);

    printf("-------------------------\n");

    printf("Value stored in i  : %d \n", i);
    printf("Value stored in p1 : %p \n", p1);
    printf("Value stored in p2 : %p \n", p2);
    printf("Value stored in p3 : %p \n", p3);
    printf("Value stored in p4 : %p \n", p4);

    printf("-------------------------\n");

    printf("Value stored in i   : %d \n", i);
    printf("Value stored in *p1 : %d \n", *p1);
    printf("Value stored in *p2 : %p \n", *p2);
    printf("Value stored in *p3 : %p \n", *p3);
    printf("Value stored in *p4 : %p \n", *p4);

    printf("-------------------------\n");

    printf("Value stored in i    : %d \n", i);
    printf("Value stored in *p1  : %d \n", *p1);
    printf("Value stored in **p2 : %d \n", **p2);
    printf("Value stored in **p3 : %p \n", **p3);
    printf("Value stored in **p4 : %p \n", **p4);

    printf("-------------------------\n");

    printf("Value stored in i     : %d \n", i);
    printf("Value stored in *p1   : %d \n", *p1);
    printf("Value stored in **p2  : %d \n", **p2);
    printf("Value stored in ***p3 : %d \n", ***p3);
    printf("Value stored in ***p4 : %p \n", ***p4);

    printf("-------------------------\n");

    printf("Value stored in i      : %d \n", i);
    printf("Value stored in *p1    : %d \n", *p1);
    printf("Value stored in **p2   : %d \n", **p2);
    printf("Value stored in ***p3  : %d \n", ***p3);
    printf("Value stored in ****p4 : %d \n", ****p4);


}

int main() {
    int int_number = 4;
    char character = 'a';
    char name[20] = "AMIT KOSHTI";


    int *i_pointer = &int_number;
    char *c_pointer = &character;

    printf("Hello World\n");

    printf("value %d , address %p \n", int_number, &int_number);
    printf("value %c , address %p \n", character, &character);

    printf("value %p , address %p, value %d \n", i_pointer, &i_pointer, *i_pointer);
    printf("value %p , address %p,  value %c \n", c_pointer, &c_pointer, *c_pointer);

    to_upper_char(&character);
    printf("Upper case : %c \n", character);

    to_lower_str(name);
    printf("Upper case : %s \n", name);


    multi_pointer();

    return 0;
}