# pointer 활용 - Array

> Array는 자료형이 같은 변수를 메모리에 연속으로 할당한 것

<br/>

- **포인터 배열** : 각 배열 요소는 일정한 간격(자료형의 크기)으로 주소를 갖음 -> `int *ptr[3];`
  <br/>

- **배열 포인터** : 배열의 주소 == 첫 번째 요소의 주소(컴파일러는 첫 번째 요소의 주소를 쉽게 사용하도록 배열의 주소를 첫 번째 배열 요소의 주소로 변경) -> `int (*ptr)[3];`
  <br/>

## Pointer Array

> 배열의 각 요소가 일반 자료형 변수가 아닌 "pointer"로 구성, 각각 다른 변수나 메모리 주소를 가리킴

<br/>

- 일반적인 배열
  <br/>

  <div style="text-align: center;">
  <img src="https://github.com/BOLTB0X/c-cpp-study/blob/main/c/pointer2/%EB%B0%B0%EC%97%B4.png?raw=true" alt="Example Image" width="90%">
  </div>

  ```c
  int arr[3] = {1, 2, 3};

  printf("array의 주소 : %p\n", arr); // 0x7ff7b773a55c

  for (int i = 0; i < 3; ++i)
  {
      printf("%p ", &arr[i]);
      // 0x7ff7bdcc155c 0x7ff7bdcc1560 0x7ff7bdcc1564
  }
  printf("\n");

  return 0;
  ```

  - 일반적인 자료형 타입 배열

  - 주소를 접근시 `&` 이용
  
  - 배열 내 원소들이 **일정 간격(자료형의 크기)** 으로 주소를 갖음을 알수 있음
    <br/>

- 포인터 배열
  <br/>

  <div style="text-align: center;">
  <img src="https://github.com/BOLTB0X/c-cpp-study/blob/main/c/pointer2/%ED%8F%AC%EC%9D%B8%ED%84%B0%20%EB%B0%B0%EC%97%B4.png?raw=true" alt="Example Image" width="90%">
  </div>
  <br/>

  ```c
  int a = 1, b = 2, c = 3;
  int *arr[3] = {&a, &b, &c};

  printf("array의 주소 : %p\n", arr); // 0x7ff7b773a55c

  for (int i = 0; i < 3; ++i) {
     printf("arr[%d] 주소 : %p\n", i, (void *)arr[i]); // arr[i]의 주소 출력
     printf("arr[%d] 값 : %d\n", i, *arr[i]);          // arr[i]가 가리키는 값 출력
  }
  ```

  ```
  array의 주소 : 0x7ff7b0afa550
  arr[0] 주소 : 0x7ff7b0afa528
  arr[0] 값 : 1
  arr[1] 주소 : 0x7ff7b0afa524
  arr[1] 값 : 2
  arr[2] 주소 : 0x7ff7b0af
  ```

  - 포인터를 요소로 갖는 배열
  - 동적으로 메모리 주소가 연속적으로 할당
  - `a`, `b`, `c` 을 미리 선언할겨우 포인터 배열 `int *arr[3]` 선언할 때 값을 복사하고 새로 메모리 주소를 연속적으로 할당
    <br/>

- 문자열
  <br/>

  ```c
  char *str[3];

  str[0] = "hello"; // 문자열 주소를 가리킴
  str[1] = "pointer";
  str[2] = "!!";

  for (int i = 0; i < 3; ++i)
  {
      printf("str[%d] 값: %s\n", i, str[i]);
      printf("str[%d] 주소: %p\n", i, str[i]);
  }
  ```

  ```
  str[0] 값: hello
  str[0] 주소: 0x10f408f79
  str[1] 값: pointer
  str[1] 주소: 0x10f408f7f
  str[2] 값: !!
  str[2] 주소: 0x10f408f87
  ```

  - 각 포인터가 서로 다른 길이의 문자열을 가리킴 -> **가변 길이 문자열**
  - 각각의 문자열은 별도의 메모리 공간에 저장됨, 배열에는 주소만 저장되므로 메모리 사용이 효율적
    <br/>

## Array Pointer

> 배열을 가리킬 수 있는 'Pointer'

<div style="text-align: center;">
<img src="https://github.com/BOLTB0X/c-cpp-study/blob/main/c/pointer2/%EB%B0%B0%EC%97%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0.png?raw=true" alt="Example Image" width="90%">
 </div>

위에서 1차원 배열(이름 자체)이 곧 -> **Array Pointer**

```
자료형 (*포인터이름)[가로(행)길이]
```

```c
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
```

```
10 20 30
40 50 60
```

- 2차원 이상의 배열을 가리킬 때 포인터를 배열처럼 사용하기 위해 **배열 포인터** 를 사용
  <br/>

- **배열 '포인터'는 배열의 시작주소값을 저장할 수 있는 '포인터'**
  <br/>

## 증감 연산

- 자료형 크기만큼 변화
  <br/>

  ```c
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
  ```

   <br/>

- 1차원 배열에서 활용
  <br/>

  ```c
  char *str_ptr = str[0];

  printf("%c %c %c %c %c\n", *str_ptr, *(str_ptr + 1), *(str_ptr + 2), *(str_ptr + 3), *(str_ptr + 4));
  // h e l l o

  int arr3[3] = {3, 4, 5};
  int *int_ptr = arr3;

  printf("%d %d %d\n", *int_ptr, *(int_ptr + 1), *(int_ptr + 2));
  // 3 4 5
  ```

  <br/>

- 2차원 배열에서 활용
  <br/>

  ```c
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
  ```

  ```
  10 10 10 10
  20 20 20 20
  30 30 30 30
  40 40 40 40
  50 50 50 50
  60 60 60 60
  ```

     <br/>

## 참고

- [세종대학교 학술정보원 연구학습지원 서비스(포인터&배열)](https://sejong-kr.libguides.com/c.php?g=942235&p=6822367)

- [MS-Learn(포인터)](https://learn.microsoft.com/ko-kr/cpp/cpp/pointers-cpp?view=msvc-170)

- [블로그 참조 - blockdmask(배열포인터, 포인터배열 정리 (pointer))](https://blockdmask.tistory.com/56)

- [TCP스쿨 - 포인터 배열과 배열 포인터](https://tcpschool.com/c/c_pointerArray_arrayPointer)

- [블로그 참조 - piaflu(학습복습 - 포인터, 포인터 연산 및 배열, 다중 포인터, 배열 포인터, 함수 포인터, 스트림, EOF, 문자열 입출력 함수 및 버퍼)](https://piaflu.tistory.com/134)

- [블로그 참조 - ideadummy([C언어] 배열 요소 접근과 포인터의 관계)](https://ideadummy.tistory.com/58)

- [블로그 참조 - kangworld([C, C++] 배열(Array)은 포인터(Pointer)가 아니다!)](https://kangworld.tistory.com/50)
