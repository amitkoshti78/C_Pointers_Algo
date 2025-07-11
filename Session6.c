//
// Created by Amit Koshti on 11.07.25.
//

#include <stdio.h>

int main() {

    char numString[] = "34781";   // '3' '4' '7' '8' '1' '\0'
                                //   0   1   2   3   4   5
    char Str[20] = "Amit"; //'A' 'm' 'i' 't' '\0'  garbage values
                          //  0   1   2   3  4  5  6 7 ....... 18 19 20
    int num1 = 0;
    int number = 0;
    int i;
    char Str1[20];

    for (i = 0; numString[i] != '\0'; i++) {

        num1 = numString[i] - '0';
        printf("\n%d : %c : %d \n", numString[i], numString[i], num1);
        number = number * 10 + num1;

    }
    printf("\n Number : %d \n", number);

     /*'1'           '2'          '9'
    00110001 49   00110010 50  00111001  57
    00110000 48   00110000 48  00110000  48
    00000001   1   00000010  2  00001001   9 */

    for (i = 0; Str[i] != '\0'; i++) {

        printf("\n%d : %c \n", Str[i], Str[i]);

        if (Str[i] >= 'a' && Str[i] <= 'z') {
            Str[i] = Str[i] - 32;
        }
        else {
            Str[i] = Str[i];
        }
        printf("\n%d : %c \n", Str[i], Str[i]);
    }

    Str1[0] = 'a';
    Str1[1] = 'm';
    Str1[2] = 'i';
    Str1[3] = 't';
    Str1[4] = '\0';


    for (i = 0;  i < 20; i++) {
        printf("\n %x :  %d ", Str1[i],Str1[i]);
    }


}
