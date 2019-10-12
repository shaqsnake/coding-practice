// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-12 10:48:36
 * @LastEditTime: 2019-10-12 11:38:44
 * @Description: Use C Runtime to create thread.
 */
#include <thread>
#include <cstdio>

void threadproc1() {
    while (true) {
        printf("I am thread #1!\n");
    }
}

void threadproc2(int a, int b) {
    while (true) {
        printf("I am thread #2!\n");
    }
}

int main() {
    std::thread t1(threadproc1);
    std::thread t2(threadproc2, 1, 2);

    while (true) {
        
    }

    return 0;
}