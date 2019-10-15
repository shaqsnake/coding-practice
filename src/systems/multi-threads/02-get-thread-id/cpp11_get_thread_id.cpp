// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-15 17:18:14
 * @LastEditTime: 2019-10-15 17:46:25
 * @Description: Get thread id by c++11 stdlib.
 */
#include <thread>
#include <iostream>
#include <sstream>

void worker_thread_func() {
    std::thread::id my_id = std::this_thread::get_id();
    std::ostringstream oss;
    oss << my_id;
    std::string str = oss.str();
    long long thread_id = atol(str.c_str());

    std::cout << "My thread id is " << thread_id << std::endl;

    return;
}

int main() {
    std::thread t(worker_thread_func);
    std::thread::id worker_thread_id = t.get_id();
    std::cout << "worker thread id: " << worker_thread_id << std::endl;

    std::thread::id main_thread_id = std::this_thread::get_id();
    std::cout << "main thread id: " << main_thread_id << std::endl;

    t.join();

    return 0;
}