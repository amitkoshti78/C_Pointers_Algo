//
// Created by Amit Koshti on 13/11/25.
//

/* 5 * 5 = o(n2)
row/col   1      2       3       4       5
1         0      1       1       1       0

2         1      0       0       0       1

3         1      0       0       1       1

4         1      0       1       0       0

5         0      1       1       0       0

for (i = 1; i < 6; i++)
    for (j = 1; j < 6; j++)
        if (graph[i][j] == 1)
            printf(%d --> %d, i, j)*/

/*1  1 --> 2 --> 3 --> 4

2  2 --> 1 --> 5

3  3 --> 1 --> 4

4  4 --> 1 --> 3

5  5 --> 2 --> 3  */

#include <stdio.h>

int main() {
    int graph[5][5];
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("\n Link exists %d --> %d  (1 otherwise 0) : ", i + 1, j + 1);
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (graph[i][j] == 1) {
                printf("%d --> %d   ", i + 1, j + 1);
            }

        }
        printf("\n");
    }
    return 0;

}