# Dynamic Allocation (동적 할당)

*프로그램*이 실행되기 위해서는 **메모리** 가 필요, *컴파일러* 는 컴파일 시점에 Source Code 를 읽고, **변수 타입들의 크기에 따라 메모리를 할당**

- **C** 에선 `malloc` , `calloc` , `realloc` 및 `free` 를 사용하여 **동적 메모리를 할당** 및 **해제**

- **C++** 에선 `new` 와 `delete` 연산자를 사용하여 **동적 메모리를 할당** 및 **해제**

## `malloc` : 메모리 동적할당의 개념

> 프로그램 실행 중(runtime) 에 필요한 만큼 메모리를 할당받는 방식 <br/>
> 크기가 유동적인 배열, 객체 등을 다룰 때 사용

```c
void* malloc(size_t size)
```

   - 지정한 바이트만큼 메모리 할당, 반환값은 `void *`

   - 대표적으로 개발자가 배열의 크기를 정하여 그 크기만큼 배열을 생성하려할 때, **동적할당** 을 사용

   ---

```c
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

// 동적 할당 해제
free(arr); 
```

- `malloc` : 할당 된 메모리를 받아서 사용

   - **지정한 바이트만큼 Heap 메모리 영역에 메모리 할당** 하고 **메모리 주소를 반환**

   - `#include <stdlib.h>` 헤더에 정의되어 있음

   - `(int *)malloc(sizeof(int) * size);` 처럼 반환형과 타입의 길이를 정해줘야함

   ---

- `free` : 할당된 메모리 해제

## Stack 메모리

```cpp
void testStackMomoty(void)
{
    int n = 42;

    printf("스택 변수: %d\n", n);
}
```

- 컴파일 타임에 크기가 결정되는 변수( *함수의 로컬변수* , *매개변수* 등 )들이 저장되는 공간 -> 새로운 **Stack Frame** 이 생성

- 함수가 종료될 경우 해당 **Stack Frame** 소멸(그 함수 내 변수들도 함께 소멸)

- **Stack 메모리는 컴파일러에 의해 자동관리**

    ---
 
| 구분     | 스택(Stack)            | 힙(Heap)                                              |
| ------ | -------------------- | ---------------------------------------------------- |
| 메모리 할당 | **컴파일 타임에 정적으로**     | **런타임에 동적으로**                                        |
| 사용 방식  | 함수 호출 시 자동으로 할당/해제   | 프로그래머가 직접 할당(`new`, `malloc`) / 해제(`delete`, `free`) |
| 관리 주체  | **컴파일러** (자동)        | **프로그래머 or 스마트 포인터** (수동/자동)                         |
| 속도     | 빠름 (메모리 접근 순차적)      | 느림 (메모리 탐색 필요)                                       |
| 크기 제한  | 작음 (보통 수 MB)         | 큼 (물리 메모리 한도까지 사용 가능)                                |
| 생존 기간  | 함수 실행 중 일시적          | 명시적으로 해제하기 전까지 유지                                    |
| 위치     | 고정된 주소 영역 (보통 높은 주소) | 유동적 주소 영역 (보통 낮은 주소)                                 |

## `calloc`

```c
void* calloc(size_t num, size_t size);
```

- `0` 으로 초기화된 메모리 `n` 개 할당

---

```c
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
```

```
indx: 0 , value: 0
indx: 1 , value: 0
indx: 2 , value: 0
indx: 3 , value: 0
indx: 4 , value: 0
indx: 5 , value: 0
indx: 6 , value: 0
indx: 7 , value: 0
indx: 8 , value: 0
indx: 9 , value: 0
```

## `realloc`

```c
void* realloc(void* ptr, size_t newSize);
```

- 기존 메모리 크기 재조정

---

```c
// 기존 할당 했던
arr = (int *)malloc(sizeof(int) * size);  
```

```c
arr = (int*)realloc(arr, sizeof(int) * 3);

arr[0] = 500;
arr[1] = 1;

for (int i = 0; i < 3; i++)
{
    printf("%d ", arr[i]);
}
printf("\n");
```

```
500 1 20
```

## Memory Leak(메모리 누수)

> 할당된 메모리를 해제하지 않아서 사용하지 않는 메모리가 계속 차지되는 현상

1. **메모리 누수란?**

    - 힙에 메모리를 할당했지만, **해제** 하지 않아 영원히 메모리 점유

    - 사용하지 않는데 계속 메모리에 남아 있는 상태 -> **누수 (Leak)**

    ---

2. **위험한 이유**

   - 반복되면 시스템 전체 메모리 고갈

   - 특히 게임, 서버 같은 장시간 실행되는 앱에서 심각한 문제 발생

   - 디버깅도 까다롭고, 크래시가 나중에 발생하기도 함

   ---

3. **방지법**

   할당한 변수를 사용후 꼭 `free` 로 해제

   ```c
   int main(void)
   {
        // ...
        
        free(arr); 
        return 0;
   }
   ```

## 참고

- [GDNGY의 함께 만들어가는 테크노트 - 메모리 동적할당](https://gdngy.tistory.com/171)

- [saint6839 - C언어 동적 메모리 할당 개념잡기](https://velog.io/@saint6839/C%EC%96%B8%EC%96%B4-%EB%8F%99%EC%A0%81-%EB%A9%94%EB%AA%A8%EB%A6%AC-%ED%95%A0%EB%8B%B9-%EA%B0%9C%EB%85%90-%EC%9E%A1%EA%B8%B0)
