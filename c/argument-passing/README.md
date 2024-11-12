# Argument passing

> 함수나 메서드에 인수(또는 매개변수)를 전달하는 방식

<br/>

- **값에 의한 전달**
  인수의 값을 복사하여 함수에 전달하므로, 함수 내부에서의 변경이 원래 변수에 영향을 미치지 X
  <br/>

- **참조에 의한 전달**
  함수가 원래 변수에 대한 참조(또는 주소)를 받기 때문에 함수 내부에서의 변경이 원래 변수에 직접 영향 O
  <br/>

## 값에 의한 전달 (Call by Value)

> function을 호출할 때 단순히 값을 복사해서 전달하는 함수호출을 값에 의한 전달(Call-by-value)

<br/>

인수의 값을 복사하여 함수에 전달하는 것이므로 원래 변수에 영향 X

```c
void func(int a)
{
    a = a + 5;
    printf("number in func : %d\n", a);
    return;
}

int main(void)
{
    int number = 5;
    func(number);

    printf("number in main : %d\n", number);
    return 0;
}
```

```
number in func : 10
number in main : 5
```

- `func` 의 매개변수 `a`의 메모리 주소에 저장된 값을 `main 함수`로 넘겨주지 않고 복사만 함
  <br/>

- 매개변수 `a` 의 메모리 공간이 새로 생겨 `number` 의 값만 **복사** 전달 받음
  <br/>

- 완전히 별개의 변수
  <br/>

## 참조에 의한 전달 (Call by Reference)

> 인수로 변수의 값을 전달하는 것이 아닌, 주소값을 전달

<br/>

인수로 전달된 변수의 값을 함수 내에서 변경 가능

```c
void funct(int *a)
{
    *a = *a + 5;
    printf("number in funct : %d\n", *a);
    return;
}

int main(void)
{
    int number = 5;

    funct(&number);
    printf("number in main : %d\n", number);

    return 0;
}
```

```
number in funct : 10
number in main : 10
```

- `funct` 의 매개변수 포인터 변수 `*a`의 메모리 주소에 저장된 값을 넘겨줌 함
  <br/>

- 매개변수 `a` 에 `number` 의 주소 값을 **참조** 전달 받음
  <br/>

- 같은 변수
  <br/>

## 참고

## 참고

- [세종대학교 학술정보원 연구학습지원 서비스(포인터&함수)](https://sejong-kr.libguides.com/c.php?g=942235&p=6822368)

- [TCP스쿨 - 인수 전달 방법](https://tcpschool.com/c/c_pointer_callBy)

- [블로그 참조 - 소년코딩(참조로 전달 (Pass by reference))](https://boycoding.tistory.com/217)

- [블로그 참조 - [C++] 참조로 전달하기 (Pass by Reference)](https://code-studies.tistory.com/35)
