/* 寒假作业 */
#include "iostream"
using namespace std;
int a[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int ans;
int v[12];
bool vis[14];
void dfs(int x)
{
    if (x == 12)
    {
        if (v[0] + v[1] == v[2] && v[3] - v[4] == v[5] && v[6] * v[7] == v[8] && v[9] == v[10] * v[11])
            ans++;
        return;
    }
    for (int i = 1; i <= 13; i++)
    {
        if (!vis[i])
        {
            v[x] = i;
            vis[i] = true;
            dfs(x + 1);
            vis[i] = false;
        }
    }
}
int main()
{
    dfs(0);
    cout << ans;
    return 0;
}
