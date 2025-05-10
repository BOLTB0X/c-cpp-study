#include <iostream>
#include <vector>
using namespace std;

// 추상 클래스: Animal
class Animal {
public:
    virtual void sound() = 0; // 순수 가상 함수
    void breathe() {
        cout << "동물이 숨을 쉽니다.\n";
    }
};

// 파생 클래스: Dog
class Dog : public Animal {
public:
    void sound() override {
        cout << "멍멍!\n";
    }
};

// 파생 클래스: Cat
class Cat : public Animal {
public:
    void sound() override {
        cout << "야옹~\n";
    }
};

// 추상 클래스
class Character {
public:
    virtual void attack() = 0; // 순수 가상 함수
    virtual void move() = 0;

    virtual ~Character() {} // 소멸자도 virtual로!
};

// 전사 클래스
class Warrior : public Character {
public:
    void attack() override {
        cout << "검으로 공격!\n";
    }
    void move() override {
        cout << "걸어서 이동!\n";
    }
};

// 마법사 클래스
class Mage : public Character {
public:
    void attack() override {
        cout << "마법을 사용!\n";
    }
    void move() override {
        cout << "순간이동!\n";
    }
};

int main() {
    // Animal a; // 객체 생성 불가 (추상 클래스이므로)
    
    Dog d;
    Cat c;

    d.sound();   // 멍멍!
    c.sound();   // 야옹~
    
    d.breathe(); // 동물이 숨을 쉽니다.

    vector<Character*> party;

    party.push_back(new Warrior());
    party.push_back(new Mage());

    for (auto c : party) {
        c->attack();
        c->move();
    }

    // 메모리 정리
    for (auto c : party) {
        delete c;
    }

    return 0;
}
