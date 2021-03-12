#include "iostream"
#include "set"
#include "vector"
using namespace std;
vector<int> v[10010];
int n;
void inp()
{
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}
set<int> s;
int maxdepth;
bool vis[10010];
vector<int> tmp;
void dfs(int x, int depth)
{
    if (vis[x])
        return;
    if (maxdepth < depth)
    {
        tmp.clear();
        tmp.push_back(x);
        maxdepth = depth;
    }
    else if (maxdepth == depth)
    {
        tmp.push_back(x);
    }
    vis[x] = true;
    for (int i = 0; i < v[x].size(); i++)
        dfs(v[x][i], depth + 1);
}
void work()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        dfs(i, 0);
        cnt++;
    }
    if (cnt > 1)
        printf("Error: %d components", cnt);
    else
    {
        int t = tmp[0]; //随便选一个点进行第二次dfs
        for (int i = 0; i < tmp.size(); i++)
            s.insert(tmp[i]);
        tmp.clear();
        maxdepth = 0;
        fill(vis, vis + 10010, false);
        dfs(t, 0);
        for (int i = 0; i < tmp.size(); i++)
            s.insert(tmp[i]);
        //两次dfs结果的并集就是答案
        for (auto it = s.begin(); it != s.end(); it++)
            cout << *it << endl;
    }
}
int main()
{
    inp();
    work();
}
