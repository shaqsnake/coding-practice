#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

int work() {
    this_thread::sleep_for(2s);
    return 42;
}

int main() {
    auto fut = async(launch::async, work);
    cout << "I am waiting now" << endl;
    cout << "Anwser: " << fut.get() << endl;

    return 0;
}