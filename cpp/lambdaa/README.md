# lambda

> C++11 이상에서는 lambda 식은 함수에 인수로 호출되거나 전달되는 위치에서 클로저 를 정의하는 편리한 방법

- 람다는 함수를 값처럼 다루는 문법

- 코드 블록을 변수처럼 저장하거나 다른 함수에 전달 가능

## 특징

- 람다는 알고리즘 또는 비동기 함수에 전달되는 몇 줄의 코드를 캡슐화하는 데 사용

- lambda은 콜백 함수나 일회성 함수를 사용할 때 유용하며, `[]` 을 사용해 캡처 목록을 지정

| 특징            | 설명                                  |
| ------------- | ----------------------------------- |
| **익명 함수**     | 이름 없는 함수                            |
| **간결함**       | 짧고 빠르게 정의 가능                        |
| **capture List**    | 외부 변수 접근을 위한 제어                     |
| **고차 함수에 사용** | `std::sort`, `std::for_each` 등에서 유용 |
| **성능**        | 함수 포인터보다 효율적 (컴파일러 최적화 가능)          |


## 기본 구조

```cpp
[capture_list](parameters) -> return_type {
    // 함수의 본문
}
```

| 구성 요소      | 설명                        |
| ---------- | ------------------------- |
| `[capture_list]` | 람다 함수 바깥의 변수를 어떻게 사용할지 정함 |
| `(parameters)`   | 함수의 인자들                   |
| `-> return_type`  | 반환 타입 (생략 가능)             |
| `{함수의 본문}`     | 실제 실행될 코드                 |

- **capture_list**
  
  외부 변수를 lamdba 내에서 사용 가능하도록 하는 캡쳐 부분

  - `[=, &변수명]` _(C++14 이상)_ : 값으로 캡처, 특정 변수만 참조로 캡처
    <br/>

- **parameters**

  함수의 매개변수 목록으로 일반 함수와 비슷하게 사용

- **return_type**

  반환 형식, 생략 가능하며, 생략 시 컴파일러가 자동 추론

## Capture list

바깥의(메인 함수 밖, 클래스 등) 지역 변수를 다양한 **캡쳐 문법** 으로 캡처해서 사용할 수 있음

| 문법        | 설명                        |
| --------- | ------------------------- |
| `[ ]`     | 아무것도 캡처하지 않음              |
| `[=]`     | 모든 외부 변수를 **값으로 복사해서 캡처** |
| `[&]`     | 모든 외부 변수를 **참조로 캡처**      |
| `[x]`     | 변수 `x`만 값으로 캡처            |
| `[&x]`    | 변수 `x`만 참조로 캡처            |
| `[=, &y]` | 기본은 값 캡처, `y`만 참조         |
| `[&, x]`  | 기본은 참조 캡처, `x`만 값으로 캡처    |

## 예시

1. **add**

   ```cpp
   auto add = [](int a, int b) -> int {
        return a + b;
    };

    cout << add(1, 2) << '\n'; // 3
   ```

   ---

2. **외부변수 참조 캡처**

   ```cpp
   int x = 1, y = 2;

   auto refe = [=, &y]() {
        y += x;
   };

   refe();
   cout << x << ' ' << y << '\n'; // 1 3
   ```

   ---

3. **std::sort() STL 알고리즘 활용**

   ```cpp
   void abssort(float* x, unsigned n) {
       sort(x, x + n, [](float a, float b) {
               return (abs(a) < abs(b));
           }
       );
   }

   int main(void) {
       float numbers[5] = {4, -3, 5, -1, 2};

       // ...

        abssort(numbers, 5);

        for (int i = 0; i < 5; ++i) {
           cout << numbers[i] << ' ';
           // -1 2 -3 4 5
        }
        cout << '\n';
   }
   ```

## 대표적인 키워드

1. `mutable`

   - 람다는 기본적으로 캡처한 변수를 `const` 로 처리하여 내부 수정이 불가능
     
   - `mutable` 키워드를 사용하면 복사된 캡처 변수를 수정 가능

   ```cpp
   #include <iostream>

   int main(void) {
       int x = 10;

       auto lam = [x]() mutable {
           x += 5;
           std::cout << "람다 내부 x: " << x << '\n';
       };

       lam();
       std::cout << "main 함수 x: " << x << '\n';
   }
   ```

   ```
   람다 내부 x: 15
   main 함수 x: 10
   ```

   - `mutable` 은 캡처된 값이 복사된 경우에만 사용 가능
     
   - 원본은  영향을 받지 않음

---

2. `auto`(Generic Lambda)

   - C++14부터 지원되는 기능
     
   - 매개변수 타입을 `auto`로 지정하면 
   템플릿처럼 다양한 타입을 처리

   ```cpp
   #include <iostream>

   int main() {
       auto print = [](auto value) {
           std::cout << "값: " << value << '\n';
       };

       print(42);
       print(3.14);
       print("Hello");
   }
   ```
   
   ```
   값: 42
   값: 3.14
   값: Hello
   ```

   - 내부에서 `decltype(value)` 같은 표현도 사용 가능

---

3. constexpr 람다

   - C++17부터 `constexpr` 람다가 지원
   
   - 컴파일 타임에 실행 가능한 람다를 만들 수 있어 상수 연산에 활용

   ```cpp
   #include <iostream>

   constexpr auto square = [](int x) constexpr {
       return x * x;
   };

   int main() {
       constexpr int result = square(5);
       std::cout << "결과: " << result << '\n';
   }
   ```
   
   ```
   결과: 25
   ```


## 참고

- [공식문서-learn(lambda)](https://learn.microsoft.com/ko-kr/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)

- [모두의 코드-람다(lambda) 함수](https://modoocode.com/196)

- [공식문서-learn(람다 식의 예)](https://learn.microsoft.com/ko-kr/cpp/cpp/examples-of-lambda-expressions?view=msvc-170)

- [cppreference-Lambda expressions (since C++11)](https://en.cppreference.com/w/cpp/language/lambda)
