//
// Created by Amit Koshti on 04.07.25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool fun_search_char(char *ptr_str, char search_char) {

    bool isFound = false;
    char lower_char = ' ';

    if (search_char >= 'A' &&  search_char <= 'Z') {
        search_char = search_char + 32;

    }

    while (*ptr_str != '\0') {

        if (*ptr_str >= 'A' && *ptr_str <= 'Z') {   // 65 "A"   a 95 = 32
            lower_char = *ptr_str + 32;
        } else {
            lower_char = *ptr_str;
        }

        printf("lower_char %c : search_char %c \n",  *ptr_str, search_char);
        if (lower_char == search_char) {
            printf("Match found\n");
            isFound = true;
        } else {
            printf("Match not found\n");
        }
        ptr_str++;

    }
    return isFound;

}
int fun_strlen(char *ptr_str, char search_char) {
    int length = 0;

    //for (; *ptr_str != '\0'; ptr_str++, length++);

    while (*ptr_str != '\0') {

        length++;
        printf("%d : %c\n", length, *ptr_str);
        ptr_str++;

    }
    return length;

}
int main() {

    char name[] = "Amit Koshti";  //"Amit Koshti\0"
                 /*01245679801 */

    bool isFound = false;
    char seach_char = 'H';

    int str_length = 0;

    str_length = fun_strlen(name, seach_char); // call by refernce

    printf("\nLength of string is %d\n", str_length);


    isFound = fun_search_char(name, seach_char);
    if (isFound) {
        printf("Character %c is found in %s", seach_char, name);
    } else {
        printf("\nCharacter \' %c \' is not found in %s\n", seach_char, name);
    }

    return 0;
}
