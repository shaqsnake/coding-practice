#include <iostream>
#include <cstring>

using namespace std;

const int N = 20010;
int f[N], g[N], q[N];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        memcpy(g, f, sizeof f);
        for (int j = 0; j < v; j++) {
            int head = 0, tail = -1;
            for (int k = j; k <= m; k += v) {
                if (head <= tail && (k - q[head]) / v > s) head++;
                if (head <= tail) f[k] = max(f[k], g[q[head]] + (k - q[head]) / v * w);
                while (head <= tail && g[q[tail]] - (q[tail] - j) / v * w <= g[k] - (k - j) / v * w) tail--;
                q[++tail] = k;
            }
        }
    }
    
    cout << f[m] << endl;
    
    return 0;
}