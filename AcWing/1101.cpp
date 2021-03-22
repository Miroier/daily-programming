#include "algorithm"
#include "iostream"
#include "map"
#include "queue"
using namespace std;
struct node
{
    int x, y;
    int len;
};
int t;
int r, c;
char g[205][205];
bool vis[205][205];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
node s;
void work()
{
    queue<node> q;
    q.push(s);
    vis[s.x][s.y] = true;
    while (q.size())
    {
        node tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = tmp.x + dx[i];
            int b = tmp.y + dy[i];
            if (a >= 0 && a < r && b >= 0 && b < c)
            {
                if (g[a][b] == 'E')
                {
                    cout << tmp.len + 1 << endl;
                    return;
                }
                if (!vis[a][b] && g[a][b] == '.')
                {
                    vis[a][b] = true;
                    q.push({a, b, tmp.len + 1});
                }
            }
        }
    }
    cout << "oop!" << endl;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> t;
    while (t--)
    {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                cin >> g[i][j];
                if (g[i][j] == 'S')
                    s.x = i, s.y = j, s.len = 0;
            }
        fill(vis[0], vis[0] + 205 * 205, false);
        work();
    }
}
