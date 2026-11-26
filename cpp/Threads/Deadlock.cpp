#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

namespace DeadlockCase {

std::mutex mutexA;
std::mutex mutexB;

void WorkerA() {
    std::lock_guard<std::mutex> lockA(mutexA);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lockB(mutexB);

    std::cout << "[Deadlock] Worker A\n";
}

void WorkerB() {
    std::lock_guard<std::mutex> lockB(mutexB);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lockA(mutexA);

    std::cout << "[Deadlock] Worker B\n";
}

void Run() {
    std::cout << "--- 1. Deadlock Case (hangs if circular wait occurs) ---\n";
    std::thread t1(WorkerA);
    std::thread t2(WorkerB);
    t1.join();
    t2.join();
}

} // namespace DeadlockCase

namespace StdLockCase {

std::mutex mutexA;
std::mutex mutexB;

void WorkerA() {
    // std::lock이 교착 상태 회피 알고리즘으로 mutexA, mutexB를 안전하게 잠금
    std::lock(mutexA, mutexB);
    // 이미 잠긴 뮤텍스의 소유권을 lock_guard에 인계(소멸 시 자동 unlock)
    std::lock_guard<std::mutex> lockA(mutexA, std::adopt_lock);
    std::lock_guard<std::mutex> lockB(mutexB, std::adopt_lock);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "[std::lock] Worker A\n";
}

void WorkerB() {
    std::lock(mutexB, mutexA);
    std::lock_guard<std::mutex> lockB(mutexB, std::adopt_lock);
    std::lock_guard<std::mutex> lockA(mutexA, std::adopt_lock);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "[std::lock] Worker B\n";
}

void Run() {
    std::cout << "--- 2. std::lock + std::adopt_lock Case ---\n";
    std::thread t1(WorkerA);
    std::thread t2(WorkerB);
    t1.join();
    t2.join();
}

} // namespace StdLockCase

namespace ScopedLockCase {

std::mutex mutexA;
std::mutex mutexB;

void WorkerA() {
    // C++17 이상: 여러 뮤텍스를 한 번에 잠그고 스코프 종료 시 자동 해제
    std::scoped_lock lock(mutexA, mutexB);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "[std::scoped_lock] Worker A\n";
}

void WorkerB() {
    std::scoped_lock lock(mutexB, mutexA);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "[std::scoped_lock] Worker B\n";
}

void Run() {
    std::cout << "--- 3. std::scoped_lock Case ---\n";
    std::thread t1(WorkerA);
    std::thread t2(WorkerB);
    t1.join();
    t2.join();
}

} // namespace ScopedLockCase

int main() {
    // 1. 데드락
    // DeadlockCase::Run();

    // 2. std::lock + std::adopt_lock 기본 해결
    StdLockCase::Run();

    // 3. std::scoped_lock 해결 (C++17+)
    ScopedLockCase::Run();

    return 0;
}