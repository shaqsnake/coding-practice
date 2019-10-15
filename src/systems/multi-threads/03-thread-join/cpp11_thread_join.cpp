// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-15 18:32:33
 * @LastEditTime: 2019-10-15 18:38:25
 * @Description: Wait thread stop in c++11.
 */
#include <cstdio>
#include <cstring>
#include <ctime>
#include <thread>

#define TIME_FILENAME "time.txt"

void FileThreadFunc() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timeStr[32] = {0};
    snprintf(timeStr, 32, "%04d/%02d/%02d %02d:%02d:%02d", t->tm_year + 1900,
             t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

    FILE *fp = fopen(TIME_FILENAME, "w");
    if (fp == NULL) {
        printf("Failed to create time.txt.\n");
        return;
    }

    size_t sizeToWrite = strlen(timeStr) + 1;
    size_t ret = fwrite(timeStr, 1, sizeToWrite, fp);
    if (ret != sizeToWrite) {
        printf("Write file error.\n");
    }

    fclose(fp);
}

int main() {
    std::thread t(FileThreadFunc);
    if (t.joinable())
        t.join();

    FILE *fp = fopen(TIME_FILENAME, "r");
    if (fp == NULL) {
        printf("open file error.\n");
        return -2;
    }

    char buf[32] = {0};
    int sizeRead = fread(buf, 1, 32, fp);
    if (sizeRead == 0) {
        printf("read file error.\n");
        return -3;
    }

    printf("Current Time is: %s.\n", buf);

    return 0;
}