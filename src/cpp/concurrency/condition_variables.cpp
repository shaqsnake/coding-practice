#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <iostream>
#include <utility>

using namespace std::chrono_literals;


class scoped_thread {
public:
    template <typename... Arg>
    scoped_thread(Arg&&... arg): thread_(std::forward<Arg>(arg)...) {}
    scoped_thread(scoped_thread&& other): thread_(std::move(other.thread_)) {}
    scoped_thread(const scoped_thread&) = delete;
    ~scoped_thread() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }

private:
    std::thread thread_;
};

void work(std::condition_variable&cv, int& result) {
    std::this_thread::sleep_for(2s);
    result = 42;
    cv.notify_one();
}

int main() {
    std::condition_variable cv;
    std::mutex mu;
    int result;

    scoped_thread th{work, std::ref(cv), std::ref(result)};

    std::cout << "I am waiting now" << std::endl;
    std::unique_lock lock(mu);
    cv.wait(lock);
    std::cout << "Answer: " << result << std::endl;

    return 0;
}