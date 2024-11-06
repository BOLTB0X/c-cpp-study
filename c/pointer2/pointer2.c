#include "stdio.h"

int main(void)
{
    // int arr[3] = {1, 2, 3};

    // printf("array의 주소 : %p\n", arr); // 0x7ff7b773a55c

    // for (int i = 0; i < 3; ++i)
    // {
    //     printf("%p ", &arr[i]);
    //     // 0x7ff7bdcc155c 0x7ff7bdcc1560 0x7ff7bdcc1564
    // }
    // printf("\n");

    int a = 1, b = 2, c = 3;
    int *arr[3] = {&a, &b, &c};

    printf("array의 주소 : %p\n", arr); // 0x7ff7b773a55c

    for (int i = 0; i < 3; ++i)
    {
        printf("arr[%d] 주소 : %p\n", i, (void *)arr[i]); // arr[i]의 주소 출력
        printf("arr[%d] 값 : %d\n", i, *arr[i]);          // arr[i]가 가리키는 값 출력
    }

    char *str[3];

    str[0] = "hello"; // 문자열 주소를 가리킴
    str[1] = "pointer";
    str[2] = "!!";

    for (int i = 0; i < 3; ++i)
    {
        printf("str[%d] 값: %s\n", i, str[i]);
        printf("str[%d] 주소: %p\n", i, str[i]);
    }

    int arr2d[2][3] = {
        {10, 20, 30},
        {40, 50, 60},
    };

    int(*ptr)[3] = arr2d; // 1 배열 포인터 선언

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", ptr[i][j]); // 2 배열 포인터로 참조
        }
        printf("\n");
    }

    char *ptr1 = 0;
    int *ptr2 = 0;
    double *ptr3 = 0;

    printf("%d, %d, %d\n", ptr1, ptr2, ptr3);
    // 0, 0, 0

    ptr1++;
    ptr2++;
    ptr3++;

    printf("%d, %d, %d\n", ptr1, ptr2, ptr3);
    // 1, 4, 8

    char *str_ptr = str[0];

    printf("%c %c %c %c %c\n", *str_ptr, *(str_ptr + 1), *(str_ptr + 2), *(str_ptr + 3), *(str_ptr + 4));
    // h e l l o

    int arr3[3] = {3, 4, 5};
    int *int_ptr = arr3;

    printf("%d %d %d\n", *int_ptr, *(int_ptr + 1), *(int_ptr + 2));
    // 3 4 5

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr2d[i][j]);
            printf("%d ", (*(arr2d + i))[j]);
            printf("%d ", *(arr2d[i] + j));
            printf("%d\n", *(*(arr2d + i) + j));
        }
    }
    return 0;
}