#include <thread>
#include <chrono>
#include <iostream>
#include <utility>

using namespace std;

class scoped_thread {
public:
    template <typename... Arg>
    scoped_thread(Arg&&... arg): thread_(forward<Arg>(arg)...) {}
    scoped_thread(scoped_thread&& other): thread_(move(other.thread_)) {}
    scoped_thread(const scoped_thread&) = delete;
    ~scoped_thread() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }

private:
    thread thread_;
};

void work(promise<int> prom) {
    this_thread::sleep_for(2s);
    prom.set_value(42);
}

int main() {
    promise<int> prom;
    auto fut = prom.get_future();
    scoped_thread th{work, move(prom)};

    cout << "I am waiting now" << endl;
    cout << "Answer: " << fut.get() << endl;

    return 0;
}