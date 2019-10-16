// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-16 17:22:51
 * @LastEditTime: 2019-10-16 18:36:31
 * @Description: How to pass an instance pointer to a thread.
 */
#include <cstdio>
#include <memory>
#include <thread>
#include <chrono>

class MyThread {
public:
    MyThread() = default;
    ~MyThread() = default;

    void start() {
        _stillRunning = true;
        _spThread.reset(new std::thread(&MyThread::threadFunc, this, 233, 666));
    }

    void stop() {
        _stillRunning = false;
        if (_spThread) {
            if (_spThread->joinable()) {
                _spThread->join();
            }
        }
    }

private:
    void threadFunc(int a, int b) {
        while (_stillRunning) {
            printf("Running threadFunc(%d, %d) ...\n", a, b);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    
private:
    std::shared_ptr<std::thread> _spThread;
    bool _stillRunning;
};

int main() {
    MyThread myThread;
    myThread.start();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    myThread.stop();
    
    return 0;
}