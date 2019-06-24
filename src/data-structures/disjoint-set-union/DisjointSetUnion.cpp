#include "DisjointSetUnion.h"

void DisjointSetUnion::unite(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb)
        parent[pa] = pb;
}

int DisjointSetUnion::find(int x) {
    if (x != parent[x]) parent[x] = find(parent[x]);
    return parent[x];
}