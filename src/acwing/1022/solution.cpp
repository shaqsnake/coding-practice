#include <iostream>

using namespace std;

const int N = 1010;

int f[N][N];
int n, m, k;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    while (k--) {
        int v, w;
        cin >> v >> w;
        for (int i = n; i >= v; i--) {
            for (int j = m-1; j >= w; j--) {
                    f[i][j] = max(f[i][j], f[i - v][j - w] + 1);
            }
        }
    }
            
    cout << f[n][m-1] << " ";
    int k = m - 1;
    while (k > 0 && f[n][k - 1] == f[n][m - 1]) k--;
    cout << m - k << endl;
    
    return 0;
}