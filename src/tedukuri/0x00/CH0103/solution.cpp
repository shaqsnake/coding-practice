#include <cstring>
#include <iostream>

using namespace std;

constexpr int N = 20;
// f第一个维度表示当前点访问的状态，第二个维度表示最后一个访问的节点
int f[1 << N][N], weight[N][N];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> weight[i][j];

    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for (int i = 1; i < 1 << n; i++)
        for (int j = 0; j < n; j++) if (i >> j & 1) // 确定j确实已经记录在状态位上了
            for (int k = 0; k < n; k++) if ((i ^ (1 << j)) >> k & 1) // 因为是从k->j,所以要确定k在状态位上，而j不再状态位上
                f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + weight[k][j]);

    cout << f[(1 << n) - 1][n - 1] << endl;

    return 0;
}