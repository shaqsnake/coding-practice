#include <iostream>

using namespace std;
#define ll long long

ll a_mul_b_mod_p(ll a, ll b, ll p) {
    ll res = 0;
    while (b) {
        if (b & 1)
            res = (res + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;
    cout << a_mul_b_mod_p(a, b, p) << endl;
    return 0;
}