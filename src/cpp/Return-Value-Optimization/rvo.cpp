#include <iostream>

using namespace std;

class A {
public:
    A() { cout << "Create A\n"; }
    ~A() { cout << "Destory A\n"; }
    A(const A &) { cout << "Copy A\n"; }
    // A(const A&) = delete;
    A(A &&) { cout << "Move A\n"; }
};

A getA_unnamed() { return A(); }

A getA_named() {
    A a;
    return a;
}

A getA_duang() {
    A a1;
    A a2;
    if (rand() > 42) {
        return a1;
    } else {
        return a2;
    }
}

int main() {
    auto a1 = getA_unnamed();
    auto a2 = getA_named();

    auto a = getA_duang();

    return 0;
}