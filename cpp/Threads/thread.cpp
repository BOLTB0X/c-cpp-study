#include <iostream>
#include <thread>

void say_hello() {
    std::cout << "Hello from thread!\n";
}

int main(void) {
    std::thread t(say_hello);  // 스레드 시작
    t.join();  // 메인 스레드가 t가 끝날 때까지 기다림
    std::cout << "Main thread done.\n";
    return 0;
}
