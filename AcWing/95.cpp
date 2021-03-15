#include "cstring"
#include "iostream"
using namespace std;
int n;
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, -1, 0, 1};
char g[6][6], backup[6][6];
void turn(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5)
            continue;
        g[a][b] ^= 1;
    }
}
int main()
{
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 5; i++)
            cin >> g[i];
        int res = 10;
        for (int i = 0; i < (1 << 5); i++)
        {
            memcpy(backup, g, sizeof g);
            int step = 0;
            for (int j = 0; j < 5; j++)
            {
                if (i & 1 << j)
                {
                    step++;
                    turn(0, j);
                }
            }
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 5; k++)
                {
                    if (g[j][k] == '0')
                    {
                        step++;
                        turn(j + 1, k);
                    }
                }

            bool dark = 0;
            for (int j = 0; j < 5; j++)
                if (g[4][j] == '0')
                {
                    dark = true;
                    break;
                }
            if (!dark)
                res = min(res, step);

            memcpy(g, backup, sizeof g);
        }
        if (res > 6)
            res = -1;
        cout << res << endl;
    }
    return 0;
}
