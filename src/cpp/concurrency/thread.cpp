#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>

using namespace std;

mutex ouput_lock;

void func(const char* name) {
    this_thread::sleep_for(100ms);
    lock_guard<mutex> guard{ouput_lock};
    cout << "I am thread " << name << endl;
}

int main() {
    thread t1{func, "A"};
    thread t2{func, "B"};
    t1.join();
    t2.join();
    return 0;
}