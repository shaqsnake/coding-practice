#include <thread>
#include <chrono>
#include <iostream>
#include <utility>

using namespace chrono_literals;


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

int work() {
    this_thread::sleep_for(2s);
    return 42;
}

int main() {
    packaged_task<int()> task{work};
    auto fut = task.get_future();
    scoped_thread th{move(task)};

    this_thread::sleep_for(1s);
    cout << "I am waiting now" << endl;
    cout << "Answer: " << fut.get() << endl;

    return 0;
}