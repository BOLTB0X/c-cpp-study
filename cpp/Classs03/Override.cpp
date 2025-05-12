#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "동물의 소리는!?" << '\n';
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "멍멍!" << '\n';
    }
};

int main(void) {
    Animal* a = new Dog();

    a->sound();

    delete a;
}
