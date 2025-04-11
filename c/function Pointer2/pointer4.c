#include "stdio.h"

struct Operator
{
    int (*fpr)(int, int);
};

int add(int a, int b) { return a + b; }

void func(int (*fpr)(int, int))
{
    printf("%d\n", fpr(7, 8));
}

int (*add_func())(int, int)
{
    return add;
}

int (*add_func2(int x, int y))(int, int)
{
    printf("add_func2 파라미터 : %d %d\n", x, y);
    return add;
}

typedef int (*FP)(int, int);

FP add_func3()
{
    return add;
}

struct Calc
{
    FP fp; // 함수 포인터 별칭을 구조체 멤버 자료형으로 사용
};

void executer(FP fp) // 함수 포인터 별칭을 매개변수 자료형으로 사용
{
    printf("%d\n", fp(70, 80));
}

int main(void)
{
    struct Operator op;

    op.fpr = add;

    printf("%d\n", op.fpr(5, 6)); // 11

    func(add); // 15

    int (*fp)(int, int) = add_func();
    printf("%d\n", fp(9, 10)); // 19

    printf("%d\n", add_func2(11, 12)(13, 14));
    // add_func2 파라미터 : 11 12
    // 27

    FP fp1; // 함수 포인터 별칭으로 변수 선언
    fp1 = add;
    printf("%d\n", fp1(10, 20)); // 30

    FP fp2[10]; // 함수 포인터 별칭으로 배열 선언
    fp2[0] = add;
    printf("%d\n", fp2[0](30, 40)); // 70

    struct Calc c;
    c.fp = add;
    printf("%d\n", c.fp(50, 60)); // 110

    executer(add); // 150: executer를 호출할 때 add 함수의 메모리 주소를 전달
    return 0;
}