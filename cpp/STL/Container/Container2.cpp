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
        std::cout << "✅ 검색 성공: " << target_found << "를 찾았습니다. (값: " << *it_found << ")\n";
        
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