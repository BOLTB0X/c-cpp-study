# Array를 함수 인자로 전달

> 배열을 통째로 전달하지 않는 대신 배열의 주소값을 전달할

## 1차원 배열

함수에서 배열을 매개변수로 사용할 경우 `( )` 안에서 매개변수 이름 뒤에 `[ ]` 를 붙이거나 매개변수를 `*` 로 지정

```
반환형 함수이름(자료형 매개변수[])
{

}

반환형 함수이름(자료형 *매개변수)
{

}

호출함수(배열)
```

_cf_ . 함수 인자로 전달할 때 `*` 나 `&` 를 명시적으로 붙이지 않아도 되는 이유: **배열 이름 자체가 포인터처럼 동작하기 때문**
<br/>

```c
void print_array1(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    return;
}

int main(void)
{
    int arr[] = {0, 1, 2, 3, 4};
    print_array1(arr, sizeof(arr) / sizeof(int));
    return 0;
}
```

```
0 1 2 3 4
```

<br/>

## 2차원 배열

2차원 배열을 매개변수로 사용하려면 `( )` 안에서 매개변수 이름 뒤에 `[가로크기]` 를 두 개 붙이고 가로 크기를 지정하거나 괄호로 묶은 `*(포인터)` 뒤에 `[ ]`를 붙이고 가로 크기를 지정

```
반환값자료형 함수이름(자료형 매개변수[][가로크기])
{

}

반환값자료형 함수이름(자료형 (*매개변수)[가로크기])
{

}
```

```c
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
// ,,,

int main(void) {
    // ..

    int twoArr[3][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };

    print_array2(twoArr, sizeof(twoArr) / sizeof(twoArr[0]), sizeof(twoArr[0]) / sizeof(int));

    // ...
}
```

```
0 1 2
3 4 5
6 7 8
```

_cf_ . `twoArr, sizeof(twoArr) / sizeof(twoArr[0])`: 배열이 차지하는 공간을 가로 한 줄의 크기로 나눠줌
<br/>

_cf_ . 복합 리터럴 사용(2차원 배열)

```c
print_array2((int[2][5]){{0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}}, 2, 5);
```

```
0 1 2 3 4
3 4 5 6 7
```

## 참고

- [세종대학교 학술정보원 연구학습지원 서비스(C언어 기초 가이드 STEP 2: 포인터&함수)](https://sejong-kr.libguides.com/c.php?g=942235&p=6822368)
- [코딩도장-함수에서 2차원 배열 매개변수 사용하기](https://dojang.io/mod/page/view.php?id=1969)
- [코딩도장-함수에서 배열 매개변수 사용하기](https://dojang.io/mod/page/view.php?id=1968)
