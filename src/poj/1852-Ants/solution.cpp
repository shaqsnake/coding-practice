#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int l, n;
        scanf("%d%d", &l, &n);
        int a[n];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        int minT = 0;
        for (int i = 0; i < n; i++) {
            minT = max(minT, min(a[i], l - a[i]));
        }

        int maxT = 0;
        for (int i = 0; i < n; i++) {
            maxT = max(maxT, max(a[i], l-a[i]));
        }

        printf("%d %d\n", minT, maxT);
    }
}