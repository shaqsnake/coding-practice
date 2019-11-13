#include <iostream>

using namespace std;

const int N = 55;
int a[N], incr[N], decr[N];
int n, res;

void dfs(int x, int icnt, int dcnt) {
    if (icnt + dcnt >= res)
        return;
    if (x == n) {
        res = min(res, icnt + dcnt);
        return;
    }

    int k = 0;
    while (k < icnt && a[x] <= incr[k])
        k++;
    if (k < icnt) {
        int t = incr[k];
        incr[k] = a[x];
        dfs(x + 1, icnt, dcnt);
        incr[k] = t;
    } else {
        incr[k] = a[x];
        dfs(x + 1, icnt + 1, dcnt);
    }

    k = 0;
    while (k < dcnt && a[x] >= decr[k])
        k++;
    if (k < dcnt) {
        int t = decr[k];
        decr[k] = a[x];
        dfs(x + 1, icnt, dcnt);
        decr[k] = t;
    } else {
        decr[k] = a[x];
        dfs(x + 1, icnt, dcnt + 1);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    while (cin >> n, n) {
        for (int i = 0; i < n; i++)
            cin >> a[i];

        res = n;
        dfs(0, 0, 0);

        cout << res << endl;
    }
}