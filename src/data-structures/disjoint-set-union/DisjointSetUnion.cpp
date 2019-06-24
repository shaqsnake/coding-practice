#include "DisjointSetUnion.h"

void DisjointSetUnion::unite(int a, int b) {
    int pa = parent[a], pb = parent[b];
    if (pa != pb)
        parent[pa] = pb;
}
