#include <iostream>

using namespace std;

const int N = 1010;
int v[N], w[N], f[N];
int n, m;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    cout << f[m] << endl;
    return 0;
}