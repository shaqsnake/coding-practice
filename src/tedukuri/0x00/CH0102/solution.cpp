#include <iostream>

using namespace std;

typedef long long ll;

ll a_mul_b_mod_p(ll a, ll b, ll p) {
    ll res = 0;
    for (; b; b >>= 1) {
        if (b & 1)
            res = (res + a) % p;
        a = 2 * a % p;
    }
    return res;
}

int main() {
    ll a, b, p;
    cin >> a >> b >> p;

    cout << a_mul_b_mod_p(a, b, p) << endl;
}