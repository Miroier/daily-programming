#include "iostream"
#include "queue"
using namespace std;
struct point
{
    int x, y, z;
};
int m, n, L, T;
int arr[70][1300][130];
bool vis[70][1300][130];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};
void inp()
{
    cin >> m >> n >> L >> T;
    for (int k = 0; k < L; k++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[k][i][j];
}
bool judge(int x, int y, int z)
{
    if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= L)
        return false;
    if (vis[z][x][y] || !arr[z][x][y])
        return false;
    return true;
}
int bfs(int z, int x, int y)
{
    int cnt = 0;
    point tmp;
    tmp.x = x, tmp.y = y, tmp.z = z;
    queue<point> q;
    q.push(tmp);
    vis[z][x][y] = 1;
    while (!q.empty())
    {
        point top = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 6; i++)
        {
            int tx = top.x + dx[i];
            int ty = top.y + dy[i];
            int tz = top.z + dz[i];
            if (judge(tx, ty, tz))
            {
                vis[tz][tx][ty] = 1;
                tmp.x = tx, tmp.y = ty, tmp.z = tz;
                q.push(tmp);
            }
        }
    }
    if (cnt >= T)
        return cnt;
    else
        return 0;
}
void work()
{
    int ans = 0;
    for (int k = 0; k < L; k++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!vis[k][i][j] && arr[k][i][j] == 1)
                    ans += bfs(k, i, j);
    cout << ans;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    inp();
    work();
}
