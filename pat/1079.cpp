#include "cmath"
#include "iostream"
#include "map"
#include "vector"
using namespace std;
int n;
double p, r;
vector<int> v[100010];
vector<int> level;
vector<pair<int, int>> ans;
void inp()
{
    cin >> n >> p >> r;
    level.resize(n);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int y;
        if (x)
            while (x--)
            {
                cin >> y;
                v[i].push_back(y);
            }
        else
        {
            cin >> y;
            ans.push_back(make_pair(i, y));
        }
    }
}
bool vis[100010];
void dfs(int x, int L)
{
    if (vis[x])
        return;
    vis[x] = true;
    level[x] = L;
    for (auto i : v[x])
        dfs(i, L + 1);
}
void work()
{
    dfs(0, 0);
    double res = 0;
    for (int i = 0; i < ans.size(); i++)
        res += p * ans[i].second * pow(1 + r / 100, level[ans[i].first]);
    printf("%.1lf", res);
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
