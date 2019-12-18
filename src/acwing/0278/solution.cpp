#include <iostream>

using namespace std;

const int N = 110, M = 10010;
int f[N][M], a[N];
int n, m;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        f[i][0] = 1;
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i-1][j];
            if (j >= a[i]) f[i][j] += f[i-1][j - a[i]];
        }
    }
    
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++)
    //         cout << f[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    cout << f[n][m] << endl;
    
    return 0;
}