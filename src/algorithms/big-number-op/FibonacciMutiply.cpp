#include <iostream>

using namespace std;

int main()
{

    int x[] = {4, 3, 9};
    int y[] = {4, 1, 3};
    int m = sizeof(x) / sizeof(*x);
    int n = sizeof(y) / sizeof(*y);
    int z[m+n];

    int hold = 0;
    for (int k = 0; k < m + n; k++) {
        for (int i = 0; i < m; i++) {
            if (k - i >= 0 && k - i < n) 
                hold += x[i] * y[k-i];
        }
        z[k] = hold % 10;
        hold /= 10;
    }

    for (int i = 0; i < m+n; i++) cout << z[i];
    cout << endl;
    return 0;
}