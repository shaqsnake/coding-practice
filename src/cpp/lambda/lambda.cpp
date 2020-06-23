#include <iostream>
#include <vector>

using namespace std;

auto adder = [](int n) {
    return [n](int x) {
        return n + x;
    };
};

int main() {
    cout << adder(2)(5) << endl;
    cout << [](int x) { return x * x; }(3) << endl;

    vector<int> v1;
    vector<int> v2;

    auto push_data = [&](int n) {
        v1.push_back(n);
        v2.push_back(n);
    };

    push_data(2);
    push_data(3);

    for (const auto& v: v1) {
        cout << v << " ";
    }

    for (const auto& v: v2) {
        cout << v << " "; 
    }
    cout << endl;

    return 0;
}

