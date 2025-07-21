//
// Created by Amit Koshti on 18.07.25.
//
#include <stdio.h>
#include <string.h>

#define ROW  10
#define LENGTH  20

int main() {

    char name[ROW][LENGTH] = { "Amit", "Omkar K", "Omkar B", "Sunidhi", "END" };
           //   0   1   2   3    4    5   6   7 --> Lenght/column
   // name = [ 'A' 'M' 'I' 'T' '\0']                  //0
   //        [ 'O' 'M' 'K' 'A'  'R'  ' ' 'K' '\0']    //1
   //        [ 'O' 'M' 'K' 'A'  'R'  ' ' 'B' '\0']    //2
   //        [ 'S' 'U' 'N' 'I'  'D'  'H' 'I' '\0']    //3

    int matrix[ROW][LENGTH];

    int i = 0;

    int j = 0;
    for (i = 0; strcmp(name[i],"END") != 0 ; i++) {
        for (j =0; name[i][j] != '\0' ; j++) {
            printf("\'%c\' ", name[i][j]);
        }
        printf("\n");
    }
    int k = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++ ) {
            matrix[i][j] = k++;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
    /*    0  1  2
       0  1  2  3  (0,0)  (0,1) (0,2)
       1  4  5  6
       2  7  8  9 */

    return 0;
}
