#include <iostream>
#include <ctime>
#include <memory>
#include "DisjointSetUnion.h"

using namespace std;

int main() {
    int n = 1000000;

    srand(time(NULL));
    auto disjoint = make_shared<DisjointSetUnion>(n);
    // DisjointSetUnion disjoint = DisjointSetUnion(n);

    time_t startTime = clock();
    for (int i = 0; i < n; i++) {
        int a = rand() % n;
        int b = rand() % n;
        disjoint->unite(a, b);
    }

    for (int i = 0; i < n; i++) {
        int a = rand() % n;
        int b = rand() % n;
        disjoint->isConnected(a, b);
    }
    double elapsedTime = clock() - startTime;

    cout << "Disjoint: " << 2*n << "ops, " << elapsedTime / CLOCKS_PER_SEC << "s" << endl;

    return 0;
}