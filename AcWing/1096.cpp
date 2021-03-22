#include "algorithm"
#include "cstring"
#include "iostream"
#include "queue"
using namespace std;
struct node
{
    int z, x, y;
    int len;
};
int t;
int l, r, c;
char g[105][105][105];
bool vis[105][105][105];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
node s;
void work()
{
    queue<node> q;
    q.push(s);
    vis[s.z][s.x][s.y] = true;
    while (q.size())
    {
        node tmp = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int z = tmp.z + dz[i];
            int x = tmp.x + dx[i];
            int y = tmp.y + dy[i];
            if (z >= 0 && z < l && x >= 0 && x < r && y >= 0 && y < c)
            {
                if (g[z][x][y] == 'E')
                {
                    printf("Escaped in %d minute(s).\n", tmp.len + 1);
                    return;
                }
                if (!vis[z][x][y] && g[z][x][y] == '.')
                {
                    vis[z][x][y] = true;
                    q.push({z, x, y, tmp.len + 1});
                }
            }
        }
    }
    cout << "Trapped!" << endl;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    while (cin >> l >> r >> c, l || r || c)
    {
        for (int k = 0; k < l; k++)
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                {
                    cin >> g[k][i][j];
                    if (g[k][i][j] == 'S')
                        s.z = k, s.x = i, s.y = j, s.len = 0;
                }
        memset(vis, false, sizeof vis);
        work();
    }
}
