#include <iostream>
#include <vector>

struct magic {
    // static constexpr int number = 42;
    static inline int number = 42;
};

int main() {
    std::vector<int> v;
    v.push_back(magic::number);
    std::cout << v[0] << std::endl;

    return 0;
}