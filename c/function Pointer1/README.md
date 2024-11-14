# function Pointer 1

> 함수의 메모리 주소를 저장하는 포인터로, 특정 함수를 가리키고 그 함수를 호출할 수 있게 함

- 배열의 이름이 배열의 시작 주소값을 의미하듯, 함수 이름은 함수가 정의되어 있는 메모리의 시작 위치
  <br/>

- _콜백 함수_ , _동적 함수 호출_ , _포인터 함수 배열_ 등 이용
  <Br/>

```c
void test(void)
{
    printf("Hello, world~\n");
    return;
}

int main(void) {
    // ...

    printf("%p\n", test);
    return;
}
```

```
0x10396ee20
```

## 함수 포인터 변수를 선언 방법

```
반환값자료형 (*함수포인터이름) (매개변수 자료형)
```

- 예시

  ```c

  int add(int a, int b)
  {
      return a + b;
  }

  // ....

  int main(void) {
    int (*fptr)(int, int);

    fptr = add;
    printf("%d\n", fptr(25, 25));
    // 50
    return 0;
  }

  ```

## 함수 포인터가 주로 사용되는 경우

- **callback 함수 구현**

  - 특정 이벤트가 발생하거나 특정 작업을 완료한 후 호출되는 함수
    <br/>
  - 함수 포인터를 사용하여 호출할 함수를 동적으로 전달 가능하여 **무한 콜백지옥 방지**
    <br/>
  - 예시 (퀵정렬)

    ```c
    int compare(const void *a, const void *b)
    {
       return (*(int *)a - *(int *)b);
    }

    int main(void) {
        int arr[] = {5, 2, 9, 1, 5, 6}, size = sizeof(arr) / sizeof(int);

        qsort(arr, size, sizeof(int), compare); // 비교 함수 포인터 전달

        for (int i = 0; i < size; i++)
        {
           printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
    ```

    ```
    1 2 5 5 6 9
    ```

    <br/>

- **동적 함수 호출 (플러그인 방식 구현)**

  - 특정 작업에 대해 여러 가지 함수가 있을 때, 함수 포인터를 사용하여 어떤 함수를 호출할지 동적으로 결정할 수 있음
    <br/>

  - 플러그인처럼 동작 방식을 런타임에서 변경하고 싶을 때 유용
    <br/>

  - 예시

    ```c
    int add(int a, int b)
    {
       return a + b;
    }

    int subtract(int a, int b)
    {
       return a - b;
    }

    // ...

    int main(void)
    {
        // ...
        int (*op)(int, int);

        op = add;
        printf("덧셈 : %d\n", op(5, 3));

        op = subtract;
        printf("빼기 : %d\n", op(5, 3));
        return 0;
    }
    ```

    <br/>

- **포인터 함수 배열**

  - 여러 함수를 배열에 저장한 후, 인덱스를 사용해 해당 함수에 접근 가능
    <br/>

  - **상태 머신(state machine)** 같은 패턴에서 자주 사용
    <br/>

  - 예시

    ```c
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }
    int multiply(int a, int b) { return a * b; }
    int divide(int a, int b) { return a / b; }

    // ,,,

    int main(void)
    {
        // ...

        int (*opArr[4])(int, int) = {add, subtract, multiply, divide};

        for (int i = 0; i < (sizeof(opArr) / sizeof(opArr[0])); i++)
        {
           printf("연산 결과: %d\n", opArr[i](10, 2));
        }
        return 0;
    }
    ```

    ```
    연산 결과: 12
    연산 결과: 8
    연산 결과: 20
    연산 결과: 5
    ```

    <br/>

## 참고

- [세종대학교 학술정보원 연구학습지원 서비스(C언어 기초 가이드 STEP 2: 포인터&함수)](https://sejong-kr.libguides.com/c.php?g=942235&p=6822368)

- [블로그 참고-gon(C 언어 - CallBack함수(콜백함수))](https://blog-of-gon.tistory.com/226)
- [코딩도장-함수 포인터 사용하기](https://dojang.io/course/view.php?id=2&section=88)
