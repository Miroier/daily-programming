/* 迷宫 */
#include "cstring"
#include <iostream>
using namespace std;
const int N = 15;
char g[N][N] = {
    "UDDLUULRUL",
    "UURLLLRRRU",
    "RRUURLDLRD",
    "RUDDDDUUUU",
    "URUDLLRRUU",
    "DURLRLDLRL",
    "ULLURLLRDU",
    "RDLULLRDDD",
    "UUDDUDUDLL",
    "ULRDLUURRR",
};
bool vis[N][N];
int ans;
bool dfs(int i, int j)
{
    if (i < 0 || i > 9 || j < 0 || j > 9)
        return true;
    if (vis[i][j])
        return false;
    vis[i][j] = true;
    if (g[i][j] == 'L')
        return dfs(i, j - 1);
    if (g[i][j] == 'R')
        return dfs(i, j + 1);
    if (g[i][j] == 'U')
        return dfs(i - 1, j);
    if (g[i][j] == 'D')
        return dfs(i + 1, j);
    return false;
}
int main()
{
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
        {
            memset(vis, 0, sizeof vis);
            // cout<<dfs(i,j)<<(j<n?" ":"\n");
            if (dfs(i, j))
                ans++;
        }
    cout << ans;
    return 0;
}
