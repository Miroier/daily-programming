/* 方格分割 */
#include <iostream>
using namespace std;
typedef long long LL;
LL ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[7][7];
void dfs(int x, int y)
{
    if (x == 0 || y == 0 || x == 6 || y == 6)
    {
        ans++;
        return;
    }
    vis[x][y] = 1;
    vis[6 - x][6 - y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx < 0 || tx > 6 || ty < 0 || ty > 6)
            continue;
        if (!vis[tx][ty])
            dfs(tx, ty);
    }
    vis[x][y] = 0;
    vis[6 - x][6 - y] = 0;
}
int main()
{
    dfs(3, 3);
    cout << ans / 4; //509
    return 0;
}
