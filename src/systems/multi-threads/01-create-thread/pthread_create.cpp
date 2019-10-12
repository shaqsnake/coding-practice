// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-12 10:35:38
 * @LastEditTime: 2019-10-12 10:40:30
 * @Description: Use pthread_create to create new thread.
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *threadfunc(void *arg) {
    while (true) {
        sleep(1);
        printf("I am new thread!\n");
    }
}

int main() {
    pthread_t tid;
    pthread_create(&tid, nullptr, threadfunc, nullptr);

    while (true) {
        sleep(1);
        printf("I am main thread!\n");
    }

    return 0;
}