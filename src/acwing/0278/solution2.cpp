#include <iostream>

using namespace std;

const int N = 10010;
int f[N];
int n, m;

int main() {
    freopen("input.txt", "r", stdin);
    f[0] = 1;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = m; j >= a; j--)
            f[j] += f[j-a];
    }
    
    cout << f[m] << endl;
    
    return 0;
}