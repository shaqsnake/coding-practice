#include <iostream>
#include <vector>

template <
    template <typename, typename>
    class OutContainer = std::vector,
    typename F, class R>
auto fmap(F&& f, R&& inputs) {
    typedef std::decay_t<decltype(f(*inputs.begin()))> result_type;
    OutContainer<result_type, std::allocator<result_type>> result;
    for (auto&& item: inputs) {
        result.push_back(f(item));
    }

    return result;
}

int add_one(int x) {
        return x + 1;
    }

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    auto result = fmap(add_one, v);

    for (const auto& r: result) {
        std::cout << r << " ";
    }
    std::cout << std::endl;

    return 0;
}