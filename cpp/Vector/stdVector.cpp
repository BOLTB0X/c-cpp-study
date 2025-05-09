#include <iostream>
#include <vector>

void print_vector(std::vector<int> v);

int main(void) {
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    print_vector(v);

    v.pop_back();
    
    print_vector(v);

    std::cout << v.size() << '\n';

    std::cout << "Capacity: " << v.capacity() << '\n';

    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    v.resize(3);
    std::cout << "resize(3): ";
    for (int i : v) std::cout << i << " ";
    std::cout << "\n";
    
    v.resize(5, 70);
    std::cout << "resize(5, 9): ";
    for (int i : v) std::cout << i << " ";
    std::cout << "\n";
    // resize(5, 9): 10 20 40 70 70

    v.insert(v.begin() + 2, 80);
    std::cout << "insert at index 2: ";
    for (int i : v) std::cout << i << " ";
    std::cout << "\n";
    // insert at index 2: 10 20 80 40 70 70

    std:: cout << v.empty() << '\n'; // 0

    v.erase(v.begin() + 4);
    std::cout << "erase at index 4: ";
    for (int i : v) std::cout << i << " ";
    std::cout << "\n";
    // erase at index 4: 10 20 80 40 70

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << '\n';

    std::vector<int> a = {1, 2, 3}; // 초기화
    std::vector<int> b(5, 100); // 5개의 100으로 초기화
    std::vector<int> c(b); // 복사 생성

    v = std::vector<int>(5, 0);
    print_vector(v);

    v = {10, 20, 30, 40, 50};

    // front()와 back()
    std::cout << "front : " << v.front() << "\n"; // 10
    std::cout << "back(): " << v.back() << "\n";   // 50

    // begin()과 end()를 사용한 반복
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // C++11 이후는 auto로 더 간단하게 작성 가능
    std::cout << "auto 사용 : ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}

void print_vector(std::vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << '\n';
}