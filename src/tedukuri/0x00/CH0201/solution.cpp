#include <iostream>
#include <cstring>

using namespace std;

char board[5][5];

void turn(int x, int y)
{
    int dx[5] = {0, 0, -1, 0, 1}, dy[5] = {0, 1, 0, -1, 0};
    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
            board[nx][ny] ^= 1;
    }
}

int work()
{
    int res;
    memset(&res, 0x3f, sizeof(res));

    // 枚举第一行的所有开灯策略
    for (int i = 0; i < (1 << 5); i++)
    {
        char backup[5][5];
        memcpy(backup, board, sizeof(board));

        int cnt = 0;
        // 把第一行的状态确定下来
        for (int j = 0; j < 5; j++)
        {
            if (i >> j & 1)
            {
                turn(0, j);
                cnt++;
            }
        }

        // 把 1 到 n-1 行的灯都打开
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (board[j][k] == '0')
                {
                    turn(j + 1, k);
                    cnt++;
                }
            }
        }

        // 检查最后一行灯的状态，如果都是打开就记录下结果
        bool done = true;
        for (int j = 0; j < 5; j++)
        {
            if (board[4][j] == '0')
            {
                done = false;
                break;
            }
        }
        memcpy(board, backup, sizeof(backup));
        if (done)
            res = min(res, cnt);
    }

    return res <= 6 ? res : -1;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 5; i++)
            cin >> board[i];
        cout << work() << endl;
    }
}