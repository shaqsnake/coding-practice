#include <type_traits>
#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename = void_t<>>
struct has_reserve: false_type {};

template <typename T>
struct has_reserve<T, void_t<decltype(declval<T&>().reserve(1U))>>: true_type {};

template <typename C, typename T>
void _append(C& container, T* ptr, size_t size, true_type) {
    container.reserve(container.size() + size);
    for (size_t i = 0; i < size; ++i) {
        container.push_back(ptr[i]);
    }
}

template <typename C, typename T>
void _append(C& container, T* ptr, size_t size, false_type) {
    for (size_t i = 0; i < size; ++i) {
        container.push_back(ptr[i]);
    }
}

template <typename C, typename T>
void append(C& container, T* ptr, size_t size) {
    // _append(container, ptr, size, integral_constant<bool, has_reserve<C>::value>{});
    _append(container, ptr, size, has_reserve<C>());
}

int main() {
    vector<int> vec{1, 2, 3, 4, 5};
    int a[4] = {4, 3, 2, 1};
    append(vec, a, 4);

    for (const auto& v: vec) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}