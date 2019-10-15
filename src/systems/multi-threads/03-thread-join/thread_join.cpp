// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-15 18:05:37
 * @LastEditTime: 2019-10-15 18:40:13
 * @Description: How to stop a thread by using system lib.
 */
#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define TIME_FILENAME "time.txt"

void *fileThreadFunc(void *arg) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timeStr[32] = {0};
    snprintf(timeStr, 32, "%04d/%02d/%02d %02d:%02d:%02d", t->tm_year + 1900,
             t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

    FILE *fp = fopen(TIME_FILENAME, "w");
    if (fp == NULL) {
        printf("Failed to create time.txt.\n");
        return NULL;
    }

    size_t sizeToWrite = strlen(timeStr) + 1;
    size_t ret = fwrite(timeStr, 1, sizeToWrite, fp);
    if (ret != sizeToWrite) {
        printf("Write file error.\n");
    }

    fclose(fp);
}

int main() {
    pthread_t fileThread;
    int ret = pthread_create(&fileThread, NULL, fileThreadFunc, NULL);
    if (ret != 0) {
        printf("Failed to create fileThread.\n");
        return -1;
    }

    int *retval;
    pthread_join(fileThread, (void **)&retval);

    FILE *fp = fopen(TIME_FILENAME, "r");
    if (fp == NULL) {
        printf("Open file error.\n");
        return -2;
    }

    char buf[32] = {0};
    int sizeRead = fread(buf, 1, 32, fp);
    if (sizeRead == 0) {
        printf("Read file error.\n");
        return -3;
    }

    printf("Current time is: %s.", buf);

    return 0;
}