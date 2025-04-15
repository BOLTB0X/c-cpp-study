# lambda

> C++11 이상에서는 lambda 식은 함수에 인수로 호출되거나 전달되는 위치에서 클로저 를 정의하는 편리한 방법

<br/>

- 일반적으로 람다는 알고리즘 또는 비동기 함수에 전달되는 몇 줄의 코드를 캡슐화하는 데 사용
  <br/>

- lambda은 콜백 함수나 일회성 함수를 사용할 때 유용하며, `[]` 을 사용해 캡처 목록을 지정
  <br/>

## 기본 구조

```cpp
[capture_list](parameters) -> return_type {
    // 함수의 본문
}
```

- **capture_list**
  외부 변수를 lamdba 내에서 사용 가능하도록 하는 캡쳐 부분

  - `[&]` : 모든 외부 변수를 참조(레퍼런스)로 캡처
  - `[=]` : 모든 외부 변수를 값으로 캡처
  - `[&변수명]` : 특정 변수를 참조로 캡처
  - `[=, &변수명]` _(C++14 이상)_ : 값으로 캡처, 특정 변수만 참조로 캡처
    <br/>

- **parameters**
  함수의 매개변수 목록으로 일반 함수와 비슷하게 사용

- **return_type**
  반환 형식, 생략 가능하며, 생략 시 컴파일러가 자동 추론

## 예시

1. **add**

   ```cpp
   auto add = [](int a, int b) -> int {
        return a + b;
    };

    cout << add(1, 2) << '\n'; // 3
   ```

   <br/>

2. **외부변수 참조 캡처**

   ```cpp
   int x = 1, y = 2;

   auto refe = [=, &y]() {
        y += x;
   };

   refe();
   cout << x << ' ' << y << '\n'; // 1 3
   ```

   <br/>

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

## 참고

- [공식문서-learn(lambda)](https://learn.microsoft.com/ko-kr/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)

- [모두의 코드-람다(lambda) 함수](https://modoocode.com/196)

- [공식문서-learn(람다 식의 예)](https://learn.microsoft.com/ko-kr/cpp/cpp/examples-of-lambda-expressions?view=msvc-170)

- [cppreference-Lambda expressions (since C++11)](https://en.cppreference.com/w/cpp/language/lambda)
