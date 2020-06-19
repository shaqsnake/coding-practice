#include <array>
#include <iostream>
#include <string_view>
#include <memory>

using namespace std;

constexpr int sqr(int n) {
    return n * n;
}

int main() {
    constexpr int n = sqr(3);
    array<int, n> a;
    int b[n];

    constexpr string_view sv{"hi"};
    constexpr pair pr{sv[0], sv[1]};
    constexpr array arr{pr.first, pr.second};
    constexpr int n1 = arr[0];
    constexpr int n2 = arr[1];
    cout << n1 << ' ' << n2 << '\n';

    return 0;
}