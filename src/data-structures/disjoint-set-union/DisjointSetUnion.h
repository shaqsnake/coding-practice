#pragma once

class DisjointSetUnion {
public:
    DisjointSetUnion(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++)
            parent[i] = i;
    };
    ~DisjointSetUnion() { delete[] parent; }

    void unite(int a, int b);
    bool isConnected(int a, int b) { return parent[a] == parent[b]; }

private:
    int *parent;
    int count;
};