#include <iostream>

using namespace std;

const int N = 110;
int f[N][N];
int n, v, m;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> v >> m;
    for (int i = 1; i <= n; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        for (int j = v; j >= a; j --)
            for (int k = m; k >= b; k--)
                f[j][k] = max(f[j][k], f[j - a][k - b] + w);
    }
    
    cout << f[v][m] << endl;
    
    return 0;
}