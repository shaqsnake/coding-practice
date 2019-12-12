#include <iostream>

using namespace std;

const int N = 20010;
int a[N], f[N];
int m, n;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        for (int j = m; j >= v; j--)
            f[j] = max(f[j], f[j - v] + v);
    }
    
    cout << m - f[m] << endl;
    
    return 0;
}