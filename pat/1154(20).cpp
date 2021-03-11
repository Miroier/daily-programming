#include "iostream"
#include "set"
#include "vector"
using namespace std;
int n, m;
vector<int> v[10005];
int color[10005];
void inp()
{
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
bool vis[10005];
bool check(int x)
{
    for (int i = 0; i < v[x].size(); i++)
        if (color[x] == color[v[x][i]])
            return 0;
    vis[x] = true;
    for (int i = 0; i < v[x].size(); i++)
        if (!vis[v[x][i]])
            if (check(v[x][i]) == 0)
            {
                vis[x] = false;
                return 0;
            }
    vis[x] = false;
    return 1;
}
void work()
{
    int k;
    cin >> k;
    while (k--)
    {
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> color[i];
            st.insert(color[i]);
        }
        if (check(0))
            printf("%d-coloring\n", st.size());
        else
            printf("No\n");
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
