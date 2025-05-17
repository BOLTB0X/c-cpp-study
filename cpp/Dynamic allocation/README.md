# C++의 동적 메모리 할당

 > C++에선 `malloc` , `free` 보다 `new` , `delete` 를 사용

 ## `new`

> 객체 생성 + 메모리 할당 (생성자 호출 포함)

```cpp
int* p = new int;         // int 1개
int* arr = new int[5];    // int 5개 (배열)
```

- 기본값은 초기화되지 않음 (C++11 이후 `new int()` 로 `0` 초기화 가능)

## `delete`

> `new`로 할당된 메모리 해제

```cpp
delete p;         // 단일 객체 해제
delete[] arr;     // 배열 해제 시 반드시 [] 필요
```

- `delete[]` 를 잘못 쓰면 **메모리 누수** 또는 **undefined behavior**

## C 와 차이

| 항목     | C (`malloc/calloc`)                   | C++ (`new`)                  |
| ------ | ------------------------------------- | ---------------------------- |
| 메모리 할당 | `malloc(size)`, `calloc(count, size)` | `new type`, `new type[n]`    |
| 반환 타입  | `void*` → 형변환 필요                      | 형변환 불필요 (자동)                 |
| 초기화    | `malloc`: X, `calloc`: 0으로 초기화        | 기본은 X (`new int()`로 초기화 가능)  |
| 생성자 호출 | X                                     | O 객체 생성자 호출                  |
| 해제     | `free(ptr)`                           | `delete ptr`, `delete[] ptr` |
| 재할당    | `realloc()` 사용                        | 직접 새로 할당하고 복사                |
| 사용 편의  | 덜 안전하고 수동적                            | 객체지향적, 예외 지원                 |

## `new` + 초기화

`calloc` : 0으로 초기화된 메모리를 할당하는 함수

```c
int* arr = (int*)calloc(5, sizeof(int));
// 0으로 초기화된 int 5개
```

```cpp
int* arr = new int[5]();
```

`()` 를 붙이면 `0` 으로 초기화

## 새 배열 생성 + 복사 + 삭제

C++에는 `realloc()`이 없으므로 직접 수동으로 구현해야 함

- **배열**

   ```cpp
   int* newArr = new int[10];
   copy(arr, arr + 5, newArr);

   delete[] arr;
   arr = newArr;
   ```

   ---

- **`vector`**

   ```cpp
   v.resize(10);
   ```

   ---

## 참고

- [jeckl - 메모리 동적할당 new, delete](https://jeckl.tistory.com/entry/C-23%EA%B0%95-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EB%8F%99%EC%A0%81%ED%95%A0%EB%8B%B9-new-delete)

- [songsite123 - 동적 메모리 할당 : new / delete 연산자](https://songsite123.tistory.com/43)

- [여러가지 개발/학습 블로그 - C++ 중급(동적 메모리 사용하기)](https://todamfather.tistory.com/102#google_vignette)