#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> PII;

const int N = 5010;
int f[N];
PII city[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> city[i].first >> city[i].second;

    sort(city, city + n);

    int res = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++)
            if (city[i].second > city[j].second)
                f[i] = max(f[i], f[j] + 1);

        res = max(res, f[i]);
    }

    cout << res << endl;

    return 0;
}