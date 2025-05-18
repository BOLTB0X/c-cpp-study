#include <memory>
#include <iostream>

struct B; // 전방 선언

// struct A {
//     std::shared_ptr<B> b_ptr;
// };

// struct B {
//     std::shared_ptr<A> a_ptr;
// };

struct A {
    std::shared_ptr<B> b_ptr;
};

struct B {
    std::weak_ptr<A> a_ptr;  // 순환 참조 방지
};

int main() {
    std::unique_ptr<int> uptr = std::make_unique<int>(100);
    std::cout << *uptr << "\n";  // 100

    // 소유권 이전 (move semantics)
    std::unique_ptr<int> uptr2 = std::move(uptr);
    // uptr 은 이제 null 상태

    std::shared_ptr<int> sp1 = std::make_shared<int>(100);
    std::shared_ptr<int> sp2 = sp1; // 참조 카운트 증가

    std::cout << *sp2 << "\n";  // 100
    std::cout << sp1.use_count() << "\n"; // 2

    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->b_ptr = b;
    b->a_ptr = a;  // weak_ptr로 참조하므로, 순환 X

    std::shared_ptr<int> sp = std::make_shared<int>(42);
    std::weak_ptr<int> wp = sp;

    if (auto spt = wp.lock()) { // shared_ptr로 잠시 승격
        std::cout << *spt << std::endl;
    }

    return 0;
}
