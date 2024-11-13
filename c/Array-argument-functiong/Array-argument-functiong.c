#include "stdio.h"

void print_array1(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    return;
}

void print_array2(int (*arr)[3], int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return;
}

int main(void)
{
    int arr[] = {0, 1, 2, 3, 4};
    // print_array1(arr, sizeof(arr) / sizeof(int));
    //  0 1 2 3 4

    int twoArr[3][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}};

    print_array2(twoArr, sizeof(twoArr) / sizeof(twoArr[0]), sizeof(twoArr[0]) / sizeof(int));
    // 배열이 차지하는 공간을 가로 한 줄의 크기로 나눠줌
    // 0 1 2
    // 3 4 5
    // 6 7 8

    print_array2((int[2][5]){{0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}}, 2, 5);

    return 0;
}