#include <iostream>
#include <cassert>

using namespace std;

int a_power_b_mod_p(int a, int b, int p)
{
    int res = 1 % p;
    while (b)
    {
        if (b & 1)
        {
            res = res * 1ll * a % p;
        }
        a = a * 1ll * a % p;
        b = b >> 1;
    }

    return res;
}

int main()
{
    assert(a_power_b_mod_p(3, 2, 7) == 2);
    assert(a_power_b_mod_p(3, 5, 10) == 3);
    assert(a_power_b_mod_p(123123, 0, 1) == 0);

    return 0;
}