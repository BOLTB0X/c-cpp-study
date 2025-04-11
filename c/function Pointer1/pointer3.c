#include "stdio.h"
#include "stdlib.h"

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

void test(void)
{
    printf("Hello, world~\n");
    return;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    printf("%p\n", test);
    // 0x10396ee20

    int (*fptr)(int, int);

    fptr = add;
    printf("%d\n", fptr(25, 25));

    int arr[] = {5, 2, 9, 1, 5, 6}, size = sizeof(arr) / sizeof(int);

    qsort(arr, size, sizeof(int), compare); // 비교 함수 포인터 전달

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // 1 2 5 5 6 9

    int (*op)(int, int);

    op = add;
    printf("덧셈 : %d\n", op(5, 3));

    op = subtract;
    printf("빼기 : %d\n", op(5, 3));

    int (*opArr[4])(int, int) = {add, subtract, multiply, divide};

    for (int i = 0; i < (sizeof(opArr) / sizeof(opArr[0])); i++)
    {
        printf("연산 결과: %d\n", opArr[i](10, 2));
    }

    return 0;
}