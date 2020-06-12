#include <iostream>

template <typename E>
E my_gcd(E a, E b) {
    while (b != E(0)) {
        E r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    std::cout << my_gcd(100, 55) << std::endl;

    return 0;
}