#include <iostream>
using namespace std;

class Animal {
private:
    void substance(void) {
        cout << "유기체" << '\n';
    }
public:
    void eat(void) {
        cout << "먹는다!" << '\n';
    }
protected:
    string jong = "종";
};

// Animal을 public 상속받은 Dog 클래스
class Dog : public Animal {
public:
    void bark(void) {
        cout << "멍멍!" << '\n';
    }

    void question(void) {
        cout << jong << '\n';
    }
};

class Cat: protected Animal {
public:
    void act(void) {
        eat();
    } 
};

class Derived_dog : private Animal {
public:
    void eating(void) { // 가능, but 외부/자식에서는 불가
        eat();
    } 

    void show(void) {
        cout << jong << '\n'; // 내부에선 가능
    }
};

class GrandChild_dog : public Derived_dog {
public:
    void display() {
        // eat();  // 자식의 자식은 접근 불가
    }
};

int main(void) {
    Dog d;
    Cat c;

    Derived_dog dd;
    
    d.eat();   // 부모 클래스의 함수 사용
    d.bark();  // 자식 클래스 고유 함수

    // cout << d.jong << '\n'; 불가
    d.question();

    // c.eat(); 외부에서 불가
    c.act();

    //dd.eat();
    dd.eating();
    dd.show();
    return 0;
}
