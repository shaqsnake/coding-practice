// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-17 17:09:53
 * @LastEditTime: 2019-10-17 17:13:09
 * @Description: Atomic types in C++11.
 */
#include <atomic>
#include <iostream>

int main() {
    std::atomic<int> value;
    value = 99;
    std::cout << value << std::endl;

    value++;
    std::cout << value << std::endl;

    return 0;
}