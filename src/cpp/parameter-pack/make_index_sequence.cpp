#include <cstdlib>
#include <iostream>
#include <tuple>

// using namespace std;

template <class T, T... Ints>
struct integer_sequece {};

template <size_t... Ints>
using index_sequence = integer_sequece<size_t, Ints...>;

template <size_t N, size_t... Ints>
struct index_sequence_helper {
    typedef typename index_sequence_helper<N-1, N-1, Ints...>::type type;
};

template <size_t... Ints>
struct index_sequence_helper<0, Ints...> {
    typedef index_sequence<Ints...> type;
};

template <size_t N>
using make_index_sequence = typename index_sequence_helper<N>::type;


template <class F, class Tuple, size_t... I>
constexpr decltype(auto) apply_impl(F&& f, Tuple&& t, index_sequence<I...>) {
    return f(std::get<I>(std::forward<Tuple>(t))...);
}


template <class F, class Tuple>
constexpr decltype(auto) apply(F&& f, Tuple&& t) {
    return apply_impl(std::forward<F>(f),
        std::forward<Tuple>(t),
        make_index_sequence<std::tuple_size_v<std::remove_reference_t<Tuple>>>{});
}

constexpr int count_bits(unsigned char value) {
    if (value == 0) {
        return 0;
    } else {
        return (value & 1) + count_bits(value >> 1);
    }
}

template <size_t... V>
struct bit_count_t {
    unsigned char count[sizeof...(V)] = {
        static_cast<unsigned char>(count_bits(V))...
    };
};

template <size_t... V>
bit_count_t<V...> get_bit_count(index_sequence<V...>) {
    return bit_count_t<V...>();
}


int main() {
    auto bit_count = get_bit_count(make_index_sequence<256>());

    for (auto&& i: bit_count.count) {
        std::cout << static_cast<unsigned>(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}