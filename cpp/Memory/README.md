## C++ & Memory

```text
C++ & Memory
│
├── 1. 프로그램과 메모리
│   ├── Code
│   ├── Data
│   ├── Heap
│   └── Stack
│
├── 2. Stack
│   ├── 함수 호출
│   ├── 지역 변수
│   ├── Stack Frame
│   └── Stack Overflow
│
├── 3. Heap
│   ├── 동적 할당
│   ├── new / delete
│   ├── 객체의 생명주기
│   └── Memory Leak
│
├── 4. Pointer & Reference
│   ├── 주소
│   ├── Pointer
│   ├── Reference
│   ├── nullptr
│   └── Dangling Pointer
│
├── 5. C++ 객체와 메모리
│   ├── 생성자 / 소멸자
│   ├── 복사
│   ├── 이동
│   ├── RAII
│   └── Smart Pointer
│
└── 6. 메모리 관련 오류
    ├── Stack Overflow
    ├── Buffer Overflow
    ├── Integer Overflow
    ├── Memory Leak
    └── Dangling Pointer
```

- Code 메모리: 프로그램의 실행 가능한 기계어 명령어가 저장되는 읽기 전용 공간

- Data 메모리: 전역 변수와 정적 변수(Static)처럼 프로그램 시작부터 종료까지 유지되는 변수가 저장되는 공간

- Heap 메모리: 개발자가 프로그래밍을 통해 실행 중에 동적으로 할당하고 해제하는 자유 공간

- Stack 메모리: 함수 호출 시 필요한 지역 변수와 매개 변수가 쌓였다가 함수가 끝나면 자동으로 사라지는 임시 공간

---

## 프로그램이 실행되었을 때

```
             프로그램 실행
                   │
        ┌──────────┴──────────┐
        │                     │
     Code/Data              Runtime
                              │
                    ┌─────────┴─────────┐
                    │                   │
                  Stack                Heap
                    │                   │
              함수 호출              동적 할당
              지역 변수              new / delete
              매개변수              객체 생명주기
                    │                   │
             Stack Frame          동적 객체
```

## 헷갈리는 것

- **Stack과 Heap의 차이는?**

   Stack은 함수 호출과 함께 생성·해제되는 지역 변수나 호출 정보를 관리하는 메모리 영역이고, Heap은 프로그램 실행 중 동적으로 메모리를 할당하고 해제하는 영역

   ---

- **Stack Overflow**

   > Stack에서 사용할 수 있는 공간을 초과하는 경우 발생

   대표적으로 과도한 재귀 호출이나 큰 지역 배열 등이 원인이 될 수 있음

   ---

- **Integer Overflow**

   정수형이 표현할 수 있는 범위를 넘어서는 값을 저장하려고 할 때 발생

---