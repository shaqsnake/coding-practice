#include <iostream>

using namespace std;

const int N = 12000;
int f[N], v[N], w[N];
int n, m;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while (k <= s) {
            idx++;
            v[idx] = k * a;
            w[idx] = k * b;
            s -= k;
            k *= 2;
        }
        
        if (s > 0) {
            idx++;
            v[idx] = s * a;
            w[idx] = s * b;
        }
    }
    
    n = idx;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            
    cout << f[m] << endl;
    return 0;
}