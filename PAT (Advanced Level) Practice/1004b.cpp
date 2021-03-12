#include "iostream"
#include "vector"
using namespace std;
int n, m;
vector<int> a[110];
int cnt[110];
int maxdepth = -1;
void inp()
{
    cin >> n >> m;
    int s, k, t;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> t;
            a[s].push_back(t);
        }
    }
}
void dfs(int x, int depth)
{
    if (!a[x].size())
    {
        cnt[depth]++;
        maxdepth = max(maxdepth, depth);
        return;
    }
    for (int i = 0; i < a[x].size(); i++)
    {
        dfs(a[x][i], depth + 1);
    }
}
void work()
{
    dfs(1, 0);
    for (int i = 0; i <= maxdepth; i++)
        cout << cnt[i] << (i < maxdepth ? " " : "");
}
int main()
{
    inp();
    work();
}
