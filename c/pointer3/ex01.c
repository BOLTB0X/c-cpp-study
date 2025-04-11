#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int row = 2, col = 3;
    int **arr;

    // row 메모리 할당
    arr = (int **)malloc(sizeof(int*) * row);

    // col 메모리 할당
    for(int i = 0; i < row; i++) {
        arr[i] = (int *)malloc(sizeof(int) * col);
    }

    // 값 초기화
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            arr[i][j] = (i+1) * 10 + j;
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    // 메모리 해제
    for(int i = 0; i < row; i++) {
        free(arr[i]);
    }
    
    free(arr);

    return 0;
}