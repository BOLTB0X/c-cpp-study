#include <stdio.h>

void func(int a)
{
    a = a + 5;
    printf("number in func : %d\n", a);
    return;
}

void funct(int *a)
{
    *a = *a + 5;
    printf("number in funct : %d\n", *a);
    return;
}

int main(void)
{
    int number = 5;

    func(number);
    printf("number in main : %d\n", number);

    funct(&number);
    printf("number in main : %d\n", number);

    return 0;
}