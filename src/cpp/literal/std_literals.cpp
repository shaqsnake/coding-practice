#include <iostream>
#include <complex>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

int main() {
    cout << "i * i = " << 1i * 1i << endl;
    cout << "Waiting for 500ms" << endl;
    this_thread::sleep_for(500ms);
    cout << "Hello world"s.substr(0, 5) << endl;
    return 0;
}