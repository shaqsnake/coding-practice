#include <iostream>

struct length {
    double value;
    enum unit {
        metre,
        centimetre,
        inch,
    };
    static constexpr double factors[] = {
        1.0,
        1e-2,
        0.0254,
    };

    explicit length(double v, unit u = metre) {
        value = v * factors[u];
    }
};

length operator+(length lhs, length rhs) {
    return length(lhs.value + rhs.value);
}

length operator"" _m(long double v) {
    return length(v, length::metre);
}

length operator"" _cm(long double v) {
    return length(v, length::centimetre);
}

std::ostream& operator<<(std::ostream& os, const length& len) {
    os << len.value << "_m";
    return os;
}

int main() {
    std::cout << 1.0_m + 10.0_cm << std::endl;
    return 0;
}