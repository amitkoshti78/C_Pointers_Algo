//
// Created by Amit Koshti on 18.07.25.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isNumeric(char argument[]) {

    char *error_char;
    printf("Argument is %s : \n", argument);

    long int number = strtol(argument, &error_char, 10 );
    printf("Number is %ld : \n", number);

    if (*error_char == '\0') {
        printf("\n Valid Number return true \n");
        return true;
    }
    else {
        printf("\n Error: Number contains string %s, can not perform calulation on string return false\n", error_char);
        return false;
    }

}

int main(int argc, char *argv[]) {

    int i;
    bool isDigit1;
    bool isDigit2;
    int operation;
    int number1 = 0;
    int number2 = 0 ;
    int result = 0;


    printf("Total argument for main : %d \n", argc);
    for (i = 0; i < argc; i++) {
        printf("argv [ %d ] : %s \n", i, argv[i]);
    }

    if (argc != 4) {
        printf("Error : Arguments are not correctly provided");
        return 1;
    }

    isDigit1 = isNumeric(argv[1]);
    if (isDigit1) {
        number1 = atoi(argv[1]);
    }
    else {
       return 1;
    }
    isDigit2 = isNumeric(argv[3]);
    if (isDigit2) {
        number2 = atoi(argv[3]);
    }
    else {
        return 1;
    }

    operation = argv[2][0];



    switch (operation) {
        case '+' :
            result = number1 + number2;
            break;
        case '-' :
            result = number1 - number2;
            break;
        case '*' :
            result = number1 * number2;
            break;
        case '/' :
            result = number1 / number2;
            break;
        default:
            printf("Error : Allowed operations are + - * / \n");
            return 1;

    }
    printf("\n Result %d %c %d = %d \n", number1, operation, number2, result);
    return 0;


}
