# include <stdio.h>

int swap(int a, int b) {

    printf("\n ### In Side Swap by Value before  swap(int a, int b) ### \n");

    printf("           variable a                              variable b\n");
    printf("        _____________________                 _____________________\n");
    printf("       |                     |               |                     |\n");
    printf("       |          %d         |               |          %d         |\n", a,b);
    printf("       |                     |               |                     |\n");
    printf("       -----------------------               ----------------------- \n");
    printf("Addr &a: %p                     Addr &b: %p\n\n ",&a, &b);


    a = a + b;
    b = a - b;
    a = a - b;

    printf("\n ### In Side Swap by Value After swap by value ### \n");

    printf("           variable a                              variable b\n");
    printf("        _____________________                 _____________________\n");
    printf("       |                     |               |                     |\n");
    printf("       |          %d         |               |          %d         |\n", a,b);
    printf("       |                     |               |                     |\n");
    printf("       -----------------------               ----------------------- \n");
    printf("Addr &a: %p                     Addr &b: %p\n\n ",&a, &b);

    return 0;

}

void swap_ptr(int *a, int *b) {

    printf("\n ### In swap pointer by reference swap_ptr(int *a, int *b) ### \n");
    printf("       variable *a                                  variable *b \n");
    printf("        _____________________                      _____________________\n");
    printf("       |                     |                    |                     |\n");
    printf("       |          %d         |                    |          %d         |\n", *a, *b);
    printf("       |           ^         |                    |           ^         |\n");
    printf("       |           |         |                    |           |         |\n");
    printf("       |     %p  |                    |     %p  |\n", a, b);
    printf("       |                     |                    |                     |\n");
    printf("       -----------------------                    -----------------------\n");
    printf("Addr &a: %p                            Addr &b: %p\n",&a, &b);


    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;

    printf("\n ### In swap pointer by reference after swapping values ### \n");
    printf("       variable *a                                  variable *b \n");
    printf("        _____________________                      _____________________\n");
    printf("       |                     |                    |                     |\n");
    printf("       |          %d         |                    |          %d         |\n", *a, *b);
    printf("       |           ^         |                    |           ^         |\n");
    printf("       |           |         |                    |           |         |\n");
    printf("       |     %p  |                    |     %p  |\n", a, b);
    printf("       |                     |                    |                     |\n");
    printf("       -----------------------                    -----------------------\n");
    printf("Addr &a: %p                            Addr &b: %p\n",&a, &b);

}

int main() {
    int a = 10;
    int b = 20;


    printf("\n ### In Side main start of program ### \n");
    printf("           variable a                              variable b\n");
    printf("        _____________________                 _____________________\n");
    printf("       |                     |               |                     |\n");
    printf("       |          %d         |               |          %d         |\n", a,b);
    printf("       |                     |               |                     |\n");
    printf("       -----------------------               ----------------------- \n");
    printf("Addr &a: %p                     Addr &b: %p\n\n ",&a, &b);

    swap(a,b); /* pass by value */

    printf("\n ### Inside main after swap by value ### \n");
    printf("           variable a                              variable b\n");
    printf("        _____________________                 _____________________\n");
    printf("       |                     |               |                     |\n");
    printf("       |          %d         |               |          %d         |\n", a,b);
    printf("       |                     |               |                     |\n");
    printf("       -----------------------               ----------------------- \n");
    printf("Addr &a: %p                    Addr &b: %p\n\n ",&a, &b);

    swap_ptr(&a, &b); /* pass by reference */

    printf("\n ### In Side main after pointer  sawp ### \n");
    printf("           variable a                              variable b\n");
    printf("        _____________________                 _____________________\n");
    printf("       |                     |               |                     |\n");
    printf("       |          %d         |               |          %d         |\n", a,b);
    printf("       |                     |               |                     |\n");
    printf("       -----------------------               ----------------------- \n");
    printf("Addr &a: %p                   Addr &b: %p\n\n ",&a, &b);
}