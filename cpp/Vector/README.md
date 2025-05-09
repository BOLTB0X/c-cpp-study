# Vector

> `std::vector`는 **동적 배열(Dynamic Array)**을 구현한 C++ 표준 컨테이너

- **컨테이너 (container)**

    같은 타입의 객체를 저장 , 관리할 목적으로 만들어진 Class

- **반복자 (iterator)**

   어떤 컨테이너에 접근하든 동일한 방법으로 접근하기 위해서 제공되는 객체

객체들을 순차적으로 보관하는 **시퀀스 컨테이너 (sequence container)** 와 키를 바탕으로 대응되는 값을 찾아주는 **연관 컨테이너 (associative container)** 존재



## `std::vector`

>  **시퀀스 컨테이너 (sequence container)** 중 대표적인게 vector

```cpp
#include <vector>
```

```cpp
vector<data type> [변수 명] 
```

- 배열과 달리 크기가 자동으로 조절됨

- 메모리가 **연속적(contiguous)** 으로 할당됨

- `std::vector<int>`, `std::vector<string>` 처럼 템플릿을 통해 다양한 타입 저장 가능

## 기본 사용법

```cpp
std::vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);

for (int i = 0; i < v.size(); i++)
    std::cout << v[i] << " ";
    // 10 20 30 
```

- `push_back()` : 요소 추가

- `v[i]` : 배열처럼 인덱스로 접근

## 주요 맴버 메소드

### `push_back()` : 뒤에 값 추가

```cpp
v.push_back(10);
```

### `pop_back()` : 마지막 요소 제거

```cpp
v.pop_back();
```

### `size()` : 요소의 개수 , 벡터의 길이

```cpp
v.size();
```

### `capacity()` : 현재 할당된 메모리 크기

```cpp
v.capacity()
```

### `resize(n)` : 크기 재설정

```cpp
v = {10, 20, 40, 50, 60};
```

- **크기 줄이기** : 뒤에 요소부터 pop

    ```cpp
    v.resize(3);
    ```

    ```cpp
    for (int i : v) 
        std::cout << i << " ";
    std::cout << "\n";

    // 10 20 40
    ```

    ---

- **크기 늘리기** : 뒤에서 부터 채워짐

   ```cpp
   v.resize(5, 70);
   ```

   ```cpp
   for (int i : v) std::cout << i << " ";
   std::cout << "\n";
   // resize(5, 9): 10 20 40 70 70
   ```
   
   ---


### `clear()` : 모든 요소 삭제

```cpp
v.clear();
```

### `empty()` : 비었는지 확인, `bool` 반환

```cpp
v.empty()
```

```cpp
std:: cout << v.empty() << '\n'; // 0
```

### `front()` : 벡터의 첫 번째 요소를 반환 

```cpp
v.front();
```

`v[0]` 반환

```cpp
std::cout << "front : " << v.front() << "\n"; // 10
```

### `back()` : 벡터의 마지막 요소를 반환 

```cpp
v.back();
```

`v[v.size() - 1]` 반환

```cpp
std::cout << "back(): " << v.back() << "\n";   // 50
```

### `begin()`

```cpp
v.begin();
```

벡터의 **첫 번째 요소를 가리키는 반복자(iterator)** 를 반환

### `end()`

```cpp
v.end();
```

벡터의 **마지막 요소의 다음을 가리키는 반복자** 를 반환

```cpp
// begin()과 end()를 사용한 반복
for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}
```

C++11 이후

```cpp
std::cout << "auto 사용 : ";
for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}
```

### `insert(pos, val)` : 특정 위치에 삽입

```cpp
v.insert(v.begin() + 2, 80);
std::cout << "insert at index 2: ";
for (int i : v) std::cout << i << " ";
std::cout << "\n";

// insert at index 2: 10 20 80 40 70 70
```

### `erase(pos)` : 특정 위치 요소 제거

```cpp
v.erase(v.begin() + 4);
std::cout << "erase at index 4: ";
for (int i : v) std::cout << i << " ";
std::cout << "\n";
// erase at index 4: 10 20 80 40 70
```

## 초기화

```cpp
std::vector<int> a = {1, 2, 3}; // 초기화
std::vector<int> b(5, 100); // 5개의 100으로 초기화
std::vector<int> c(b); // 복사 생성

v = std::vector<int>(5, 0);
```

##  반복자(iterator) 이용

```cpp
for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}
```

또는 C++11 이후

```cpp
for (int val : v) {
    std::cout << val << " ";
}
```

## 2차원 벡터

```cpp
std::vector<std::vector<int>> matrix(3, std::vector<int>(3, 0));
```

## 참고

- [모두의 코드 - 씹어먹는 C++ - <10 - 1. C++ STL - 벡터(std::vector), 리스트(list), 데크(deque)>](https://modoocode.com/223)

- [블로그 참고 - 가면 뒤의 기록(vector container 정리 및 사용법)](https://blockdmask.tistory.com/70)