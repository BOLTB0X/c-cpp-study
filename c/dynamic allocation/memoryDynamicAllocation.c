#include <stdio.h>
#include <stdlib.h>

void testStackMomoty(void)
{
    int n = 42;

    printf("스택 변수: %d\n", n);
}

int main(void)
{
    int *arr, size;

    scanf("%d", &size);

    // int형 size 개 동적 할당 (sizeof(int) * size)
    arr = (int *)malloc(sizeof(int) * size);  

    if (arr == NULL)
    {
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i * 10;
        printf("%d ", arr[i]);
    }
    printf("\n");

    testStackMomoty();

    int *ptr = (int*)calloc(10, sizeof(int));

    if (ptr == NULL)
    {
        printf("메모리 할당 실패 \n");
        return 1;
    }

    for (int i = 0; i < 10; ++i)
    {
        printf("indx: %d , value: %d\n", i, *(ptr + i));
    }

    free(ptr);

    arr = (int*)realloc(arr, sizeof(int) * 3);

    arr[0] = 500;
    arr[1] = 1;

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 동적 할당 해제
    free(arr); 
    return 0;
}