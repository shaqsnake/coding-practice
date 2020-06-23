#include <array>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    array a{1, 2, 3, 4, 5};
    auto s = accumulate(a.begin(), a.end(), 0, [](auto x, auto y) { return x + y; });
    cout << s << endl;

    return 0;
}