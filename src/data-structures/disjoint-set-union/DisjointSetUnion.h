#pragma once

class DisjointSetUnion {
public:
    DisjointSetUnion(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++)
            parent[i] = i;
    };
    ~DisjointSetUnion() { delete[] parent; }

    bool isConnected(int a, int b) { return find(a) == find(b); }
    void unite(int a, int b);
    int find(int x);

private:
    int *parent;
    int count;
};