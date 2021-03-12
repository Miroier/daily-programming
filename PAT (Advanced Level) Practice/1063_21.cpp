#include "iostream"
#include "set"
#include "vector"
using namespace std;
vector<set<int>> v;
int n, k;
void inp()
{
    cin >> n;
    v.resize(n + 1);
    int t;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        int x;
        while (t--)
            cin >> x, v[i].insert(x);
    }
}
void work()
{
    cin >> k;
    int x, y;
    while (k--)
    {
        cin >> x >> y;
        set<int> tmp;
        for (auto it = v[x].begin(); it != v[x].end(); it++)
            tmp.insert(*it);
        for (auto it = v[y].begin(); it != v[y].end(); it++)
            tmp.insert(*it);
        printf("%.1lf\%\n", (v[x].size() + v[y].size() - tmp.size()) * 100.0 / tmp.size());
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
