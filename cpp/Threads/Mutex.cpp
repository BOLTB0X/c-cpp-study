#include <iostream>
#include <thread>
#include <mutex>

int count = 0;

std::mutex mtx;

void Worker()
{
    std::lock_guard<std::mutex> lock(mtx);

    count++;
}

int main() {
    std::thread t1(Worker);
    std::thread t2(Worker);

    t1.join();
    t2.join();

    std::cout << count << '\n';

    return 0;
}