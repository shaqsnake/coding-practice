#include <iostream>
#include <cstring>

using namespace std;

const int N = 13;
int d[N], f[N];

int main()
{
    int n = 12;

    for (int i = 1; i <= n; i++)
        d[i] = 2 * d[i - 1] + 1;

    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            f[i] = min(f[i], 2 * f[j] + d[i - j]);
    }

    for (int i = 1; i <= n; i++)
        cout << f[i] << endl;
}