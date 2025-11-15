# Container

C++ **표준 템플릿 라이브러리(Standard Template Library, STL)** 에서 컨테이너는 데이터를 저장하고 관리하는 객체

| 분류 | 컨테이너 예시 | 특징 |
|------|----------------|-------|
| 순차(Sequence) | `std::vector`, `std::list`, `std::deque` | 요소들이 순서대로 저장되며, 인덱스 접근과 순차적 접근에 용이함 |
| 연관(Associative) | `std::map`, `std::set` | 키 기반으로 요소를 저장하며, 빠른 검색과 정렬을 보장함 |
| 어댑터(Adapter) | `std::stack`, `std::queue` | 기존 컨테이너 기반의 LIFO/FIFO 인터페이스 제공 |

---

## `begin()` 과 `end()`

C++에서 컨테이너의 요소들을 순차적으로 접근하기 위해 사용되는 **반복자(Iterator)** 를 반환

- `begin()` : 순회의 시작점

- `end()` : 순회의 종료점

C++ 표준 라이브러리의 모든 순회는 **[begin, end)** 와 같은 반열린 구간(Half-Open Range)을 따름

```cpp
for (auto it = container.begin(); it != container.end(); ++it) {
    // 순회 조건: 반복자가 end()가 아닐 때까지
    // *it를 통해 현재 요소를 안전하게 사용
}
```


### `sort` 에서 활용

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> data = {30, 10, 40, 20};

std::sort(data.begin(), data.end());

for (int val : data) {
    std::cout << val << " "; // 10 20 30 40
}
```

### `find` 에서 활용

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

void pra_find() {
    std::vector<int> numbers = {10, 15, 20, 25, 30};
    int target_found = 15;
    int target_not_found = 99;

    std::cout << "현재 컨테이너: {10, 15, 20, 25, 30}\n\n";

    // std::find(시작 반복자, 종료 반복자, 찾을 값)
    auto it_found = std::find(numbers.begin(), numbers.end(), target_found);

    if (it_found != numbers.end()) {
        // 성공: 찾았을 경우, 해당 요소를 가리키는 반복자를 반환
        
        // *it_found로 찾은 요소의 값을 역참조
        std::cout << "검색 성공: " << target_found << "를 찾았습니다. (값: " << *it_found << ")\n";
        
        // 반복자가 begin()에서 얼마나 떨어져 있는지 (인덱스) 계산
        // std::distance는 두 반복자 사이의 거리를 계산
        auto index = std::distance(numbers.begin(), it_found);
        std::cout << "   -> 인덱스: " << index << "\n";
    } else {
        // 실패
        std::cout << "검색 실패.\n";
    }

    auto it_not_found = std::find(numbers.begin(), numbers.end(), target_not_found);

    if (it_not_found != numbers.end()) {
        // 성공
        std::cout << "검색 성공.\n";
    } else {
        // 실패
        std::cout << "검색 실패: " << target_not_found << "를 찾지 못했습니다.\n";
        std::cout << "   -> 반환된 반복자는 numbers.end()와 같습니다.\n";
    }
}

int main() {
    pra_find();
    return 0;
}
```