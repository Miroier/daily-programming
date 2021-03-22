#include "algorithm"
#include "iostream"
using namespace std;
#define x first
#define y second
typedef pair<int, int> PII;
int w, h;
int cnt;
char g[25][25];
PII s;
bool vis[25][25];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
void dfs(PII s)
{
    vis[s.x][s.y] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int a = s.x + dx[i];
        int b = s.y + dy[i];
        if (a >= 0 && a < w && b >= 0 && b < h)
            if (!vis[a][b] && g[a][b] == '.')
                dfs(make_pair(a, b));
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    while (cin >> h >> w, w || h)
    {
        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++)
            {
                cin >> g[i][j];
                if (g[i][j] == '@')
                    s.x = i, s.y = j;
            }
        fill(vis[0], vis[0] + 25 * 25, false);
        cnt = 0;
        dfs(s);
        cout << cnt << endl;
    }
}
