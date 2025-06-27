#import <stdio.h>
#import <string.h>

int main() {

    int arr_num[5] = {5,     2,     7,    4,     6};
              /* addr = 8830  8834  8838   883c  8840
                 i =      0     1     2      3     4 */

    int *ptr_num = &arr_num[0];

    char name[5] = "Amit"; /*{'A', 'm', 'i', 't', '\0'};*/

    char *ptr_name = name;

    int i;

    printf("%p --> %p ---> %d ---> %d \n", ptr_num, &arr_num[0], *ptr_num ,arr_num[0] );

    for (i = 0; i < 5; i++) {

        printf("Array address --> %p Pointer --> %p \n", &arr_num[i], ptr_num);
        printf("i = %d --> arr = %d --> ptr = %d \n", i, arr_num[i], *ptr_num);
        ptr_num++;
    }

    printf("%p --> %p ---> %c ---> %c \n", ptr_name, &name[0], *ptr_name ,name[0] );

    for (i = 0; i < 5; i++) {

    printf("Array address --> %p Pointer --> %p \n", &name[i], ptr_name);
    printf("i = %d --> arr = %c --> ptr = %c \n", i, name[i], *ptr_name);
    ptr_name++;
    }

}