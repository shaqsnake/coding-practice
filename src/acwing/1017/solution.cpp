#include <iostream>

using namespace std;

const int N = 110;
int a[N], f[N];

int main() {
    freopen("input.txt", "r", stdin);
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        int res = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = 1;
            for (int j = 1; j < i; j++) {
                if (a[i] < a[j]) f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }
        
        for (int i = n; i; i--) {
            f[i] = 1;
            for (int j = n; j > i; j--) {
                if (a[i] < a[j]) f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }
        
        cout << res << endl;
    }
    
    return 0;
}