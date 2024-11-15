# function Pointer 2

함수 포인터를 이용하여

- **구조체 멤버**로 사용
- **함수의 파라미터**로 사용
- **함수의 반환값**으로 사용
- `typedef`로 함수 포인터 별칭 정의

<br/>

## 구조체 멤버로 사용

- **정의**
  `struct` 멤버로 사용하려면 구조체를 정의할 때 멤버로 지정해주면 함수 포인터도 포인터이므로 `struct` 멤버로 사용 가능
  <br/>

  ```c
  struct 구조체이름 {
      반환값자료형 (*함수포인터이름)(매개변수자료형1, 매개변수자료형2);
  };
  ```

  <div style="text-align: center;">
  <img src="https://github.com/BOLTB0X/c-cpp-study/blob/main/c/function%20Pointer2/img/%ED%95%A8%EC%88%98%ED%8F%AC%EC%9D%B8%ED%84%B0-%EA%B5%AC%EC%A1%B0%EC%B2%B4%EB%A7%B4%EB%B2%84.png?raw=true" alt="Example Image" width="100%">
  </div>

    <br/>

- **예시**

  ```c
  struct Operator
  {
      int (*fpr)(int, int);
  };

  int add(int a, int b) { return a + b; }

  int main(void)
  {
      struct Operator op;

      op.fpr = add;

      printf("%d\n", op.fpr(5, 6)); // 11
      return 0;
  }
  ```

  `add` 함수의 메모리 주소를 구조체 `op`의 멤버에 저장
  <br/>

## 함수의 파라미터로 사용

- **정의**
  함수를 정의할 때 매개변수 부분에 함수 포인터로 작성
  <br/>

  ```
  반환값자료형 함수이름(함수포인터반환값자료형 (*함수포인터이름)(함수포인터매개변수자료형1, 함수포인터매개변수자료형2))
  {

  }
  ```

    <div style="text-align: center;">
  <img src="https://github.com/BOLTB0X/c-cpp-study/blob/main/c/function%20Pointer2/img/%ED%95%A8%EC%88%98%ED%8F%AC%EC%9D%B8%ED%84%B0-%EB%A7%A4%EA%B0%9C%EB%B3%80%EC%88%98.png?raw=true" alt="Example Image" width="100%">
  </div>

  <br/>

- **예시**

  ```c
  void func(int (*fpr)(int, int))
  {
      printf("%d\n", fpr(7, 8));
  }

  // ...

  func(add); // 15
  ```

  `func` 함수 호출할 때 `add` 함수의 메모리 주소를 전달
  <br/>

## 함수의 반환값으로 사용

- **정의**

  ```c
  함수포인터반환값자료형 (*함수이름(매개변수자료형 매개변수))(함수포인터매개변수자료형1, 함수포인터매개변수자료형2)
  {

  }
  ```

  <div style="text-align: center;">
  <img src="https://github.com/BOLTB0X/c-cpp-study/blob/main/c/function%20Pointer2/img/%ED%95%A8%EC%88%98%ED%8F%AC%EC%9D%B8%ED%84%B0-%EB%B0%98%ED%99%98%EA%B0%92.png?raw=true" alt="Example Image" width="100%">
  </div>

  <br/>

- **예시**

  ```c
  int (*add_func())(int, int)
  {
      return add;
  }

  int main(void)
  {
      // ...
      int (*fp)(int, int) = add_func();
      printf("%d\n", fp(9, 10)); // 19
      return 0;
  }
  ```

  `int (*fp)(int, int) = add_func()` 반환값을 함수 포인터 fp에 저장
  <br/>

- _cf_ . **매개변수가 있는 함수에서 함수 포인터 반환**

  ```c
  int (*add_func2(int x, int y))(int, int)
  {
      printf("add_func2 파라미터 : %d %d\n", x, y);
      return add;
  }

  // ...

  printf("%d\n", add_func2(11, 12)(13, 14));
  ```

  ```
  add_func2 파라미터 : 11 12
  27
  ```

  <br/>

## 함수 포인터 별칭 정의

> 일일이 반환값 자료형과 매개변수 자료형을 명시해주는데 이런 방식을 full pointer type이라고 함

즉 매번 사용하기가 상당히 번거로움 -> 이때는 typedef로 별칭을 정의하면 함수 포인터를 매번 만들지 않아도 됌

<br/>

- **정의**

  ```
  typedef 반환값자료형 (*함수포인터별칭)(매개변수자료형1, 매개변수자료형2);
  ```

    <div style="text-align: center;">
  <img src="https://github.com/BOLTB0X/c-cpp-study/blob/main/c/function%20Pointer2/img/%ED%95%A8%EC%88%98%ED%8F%AC%EC%9D%B8%ED%84%B0-%EB%B3%84%EC%B9%AD.png?raw=true" alt="Example Image" width="100%">
  </div>

  <br/>

- **예시**

  ```c
  typedef int (*FP)(int, int);

  FP add_func3()
  {
      return add;
  }

  struct Calc {
      FP fp;   // 1
  };

  void executer(FP fp)    // 2
  {
      printf("%d\n", fp(70, 80));
  }

  int main(void)
  {
      FP fp1; // 3
      fp1 = add;
      printf("%d\n", fp1(10, 20)); // 30

      FP fp2[10]; // 4
      fp2[0] = add;
      printf("%d\n", fp2[0](30, 40)); // 70

      struct Calc c;
      c.fp = add;
      printf("%d\n", c.fp(50, 60)); // 110

      executer(add); // 150, 5
      return 0;
  }
  ```

  1. 함수 포인터 별칭을 구조체 멤버 자료형으로 사용
  2. 함수 포인터 별칭을 매개변수 자료형으로 사용
  3. 함수 포인터 별칭으로 변수 선언
  4. 함수 포인터 별칭으로 배열 선언
  5. executer를 호출할 때 add 함수의 메모리 주소를 전달

<br/>

## 참고

- [코딩도장 - 함수 포인터 활용하기](https://dojang.io/course/view.php?id=2&section=89)
