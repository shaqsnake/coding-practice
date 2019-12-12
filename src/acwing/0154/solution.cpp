#include <iostream>

using namespace std;

const int N = 1000010;
int a[N], q[N];
int n, k;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int head = 0, tail = -1;
    for (int i = 0; i < n; i++) {
        if (head <= tail && i - q[head] + 1 > k) head++;
        while (head <= tail && a[q[tail]] >= a[i]) tail--;
        q[++tail] = i;
        
        if (i >= k - 1) cout << a[q[head]] << " ";
    }
    cout << endl;
    
    head = 0, tail = -1;
    for (int i = 0; i < n; i++) {
        if (head <= tail && i - q[head] + 1 > k) head++;
        while (head <= tail && a[q[tail]] <= a[i]) tail--;
        q[++tail] = i;
        
        if (i >= k - 1) cout << a[q[head]] << " ";
    }
    cout << endl;
    
    return 0;
}