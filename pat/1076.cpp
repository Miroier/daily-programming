#include "iostream"
#include "queue"
#include "vector"
using namespace std;
int n, L, k;
vector<int> v[1010];
void inp()
{
    cin >> n >> L;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        int y;
        for (int j = 0; j < x; j++)
        {
            cin >> y;
            v[y].push_back(i);
        }
    }
}
bool vis[1010];
int level[1010];
int bfs(int x)
{
    queue<int> q;
    int num = 0;
    q.push(x);
    vis[x] = true;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (auto i : v[x])
        {
            if (!vis[i] && level[x] < L)
            {
                ++num;
                vis[i] = true;
                level[i] = level[x] + 1;
                q.push(i);
            }
        }
    }
    return num;
}
void work()
{
    cin >> k;
    int x;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        fill(level, level + 1010, 0);
        fill(vis, vis + 1010, false);
        cout << bfs(x) << endl;
    }
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
