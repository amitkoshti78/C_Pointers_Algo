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
    printf("       | &x : %p |                    | &y : %p |\n", a, b);
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
    printf("       | &x : %p |                    | &y : %p |\n", a, b);
    printf("       |                     |                    |                     |\n");
    printf("       -----------------------                    -----------------------\n");
    printf("Addr &a: %p                            Addr &b: %p\n",&a, &b);

}

int main() {
    int x = 10;
    int y = 20;

    printf("\n \'&\' : Gives address of a variable in a memory and called as address of operator \n");
    printf(" \'*\' : Gives the value stored at address and termed as pointing to/deferencing operator \n");
    printf("\n ### In Side main start of program ### \n");
    printf("           variable x                              variable y\n");
    printf("        _____________________                 _____________________\n");
    printf("       |                     |               |                     |\n");
    printf("       |          %d         |               |          %d         |\n", x,y);
    printf("       |                     |               |                     |\n");
    printf("       -----------------------               ----------------------- \n");
    printf("Addr &x: %p                     Addr &y: %p\n\n ",&x, &y);

    swap(x,y); /* pass by value */

    printf("\n ### Inside main after swap by value ### \n");
    printf("           variable x                              variable y\n");
    printf("        _____________________                 _____________________\n");
    printf("       |                     |               |                     |\n");
    printf("       |          %d         |               |          %d         |\n", x,y);
    printf("       |                     |               |                     |\n");
    printf("       -----------------------               ----------------------- \n");
    printf("Addr &x: %p                    Addr &y: %p\n\n ",&x, &y);

    swap_ptr(&x, &y); /* pass by reference */

    printf("\n ### In Side main after pointer  sawp ### \n");
    printf("           variable x                              variable y\n");
    printf("        _____________________                 _____________________\n");
    printf("       |                     |               |                     |\n");
    printf("       |          %d         |               |          %d         |\n", x,y);
    printf("       |                     |               |                     |\n");
    printf("       -----------------------               ----------------------- \n");
    printf("Addr &x: %p                   Addr &y: %p\n\n ",&x, &y);
}