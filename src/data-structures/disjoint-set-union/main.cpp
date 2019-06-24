#include "DisjointSetUnion.h"
#include <ctime>
#include <iostream>
#include <memory>

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

    cout << "Disjoint: " << 2 * n << "ops, " << elapsedTime / CLOCKS_PER_SEC
         << "s" << endl;

    // auto disjoint = make_shared<DisjointSetUnion>(10);
    // disjoint->unite(1, 3);
    // disjoint->unite(3, 5);
    // disjoint->unite(5, 7);
    // disjoint->unite(9, 1);
    
    // cout << disjoint->isConnected(1, 7) << endl;
    // cout << disjoint->isConnected(1, 2) << endl;

    return 0;
}