#include <iostream>

namespace My_Namespace {
    int age = 31;

    void show() {
        std::cout << "Hello My_Namespace!" << '\n';
    }
}

namespace A_Namespace {
    namespace B_Namespace {
        void show() {
            std::cout << "Hello A_Namespace::B_Namespace" << '\n';
        }
    }
}

namespace {
    int age = 33;

    void show() {
        std::cout << "anonymous(unnamed)" << std::endl;
    }
}
//using namespace My_Namespace;

namespace Alias = A_Namespace::B_Namespace;

int main() {
    // std::cout << age << '\n';
    // show();

    Alias:: show(); // Hello A_Namespace::B_Namespace
    show(); // anonymous(unnamed)
    //A_Namespace::B_Namespace::show(); // Hello A_Namespace::B_Namespace
    //std::cout << My_Namespace::age << '\n';
    //My_Namespace::show();
    return 0;
}