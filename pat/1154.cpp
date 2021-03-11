#include "iostream"
#include "set"
#include "unordered_map"
#include "vector"
using namespace std;
int n, m;
int color[10005];
unordered_map<int, bool> mp;
void inp()
{
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        mp[x * 10000 + y] = mp[y * 10000 + x] = 1;
    }
}
bool vis[10005];
bool check()
{
    for (auto x : mp)
        if (color[x.first / 10000] == color[x.first % 10000])
            return 0;
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
        if (check())
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
