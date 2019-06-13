#include <algorithm>
#include <iostream>

using namespace std;

int lbsearch(int *a, int n, int target) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= target)
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

int ubsearch(int *a, int n, int target) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2 + 1;
        if (a[mid] <= target)
            l = mid;
        else
            r = mid - 1;
    }

    return r + 1;
}

int main() {
    int n = 10;
    int arr[] = {1, 2, 3, 3, 3, 5, 5, 5, 6, 6};
    cout << lbsearch(arr, 10, 4) << " " << ubsearch(arr, 10, 4) << endl;
    cout << lower_bound(arr, arr + n - 1, 4) - arr << " "
         << upper_bound(arr, arr + n, 4) - arr << endl;
    cout << lbsearch(arr, 10, 5) << " " << ubsearch(arr, 10, 5) << endl;
    cout << lower_bound(arr, arr + n - 1, 5) - arr << " "
         << upper_bound(arr, arr + n, 5) - arr << endl;
    return 0;
}