#include <stdio.h>

/*
arrays example
*/
int main(int argc, char** argv[]) {
    int arr_1d[5] = {9, 8, 7, 6, 5};

    printf("1-dimensional array: \n");
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", arr_1d[i]);
    }

    printf("-------------\n");

    int arr_2d[2][3] = {{9, 8, 7}, {6, 5, 4}};

    printf("2-dimensional array: \n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\n", arr_2d[i][j]);
        }
    }

    return 0;
}

/* 
Hello world example
*/
// int main(int argc, char** argv[]) {
//     printf("Hello\n");
//     return 0;
// }