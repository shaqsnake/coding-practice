#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std::chrono_literals;

int x = 0;
std::atomic<int> y;

void func1() {
    std::this_thread::sleep_for(100ms);
    x = 1;
    y.store(2, std::memory_order_release);
}

void func2() {
    std::this_thread::sleep_for(100ms);
    if (y.load(std::memory_order_acquire) == 2) {
        x = 3;
        y.store(4, std::memory_order_relaxed);
    }
}

int main() {
    std::thread t1{func1};
    std::thread t2{func2};

    t1.join();
    t2.join();

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << std::endl;

    return 0;
}