#include "cstring"
#include <iostream>
using namespace std;
const int N = 1005;
char g[N][N];
bool vis[N][N];
int ans = 0;
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool dfs(int x, int y)
{
  vis[x][y] = true;
  bool flag = true;
  for (int i = 0; i < 4; i++)
  {
    int tx = x + dx[i], ty = y + dy[i];
    if (tx >= 1 && tx <= n && ty >= 1 && ty <= n)
      if (g[tx][ty] != '#')
        flag = false;
  }
  for (int i = 0; i < 4; i++)
  {
    int tx = x + dx[i], ty = y + dy[i];
    if (tx >= 1 && tx <= n && ty >= 1 && ty <= n)
      if (g[tx][ty] == '#' && !vis[tx][ty])
        flag |= dfs(tx, ty);
  }
  return flag;
}
int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> g[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (g[i][j] == '#' && !vis[i][j])
        if (!dfs(i, j))
          ans++;
  cout << ans;
  return 0;
}
