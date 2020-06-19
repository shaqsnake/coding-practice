#include <cstdio>

constexpr int factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Arg must be non-negative");
    } else if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    constexpr int n = factorial(10);
    printf("%d\n", n);

    return 0;
}