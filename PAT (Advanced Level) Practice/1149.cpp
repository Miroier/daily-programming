#include "iostream"
#include "unordered_map"
#include "vector"
using namespace std;
typedef long long LL;
int n, m;
unordered_map<int, vector<int>> mp;
bool a[100005];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        LL x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        fill(a, a + 100005, false);
        vector<LL> t(x);
        for (int i = 0; i < x; i++)
        {
            cin >> t[i];
            a[t[i]] = 1;
        }
        bool flag = 1;
        for (int i = 0; i < x; i++)
            for (int j = 0; j < mp[t[i]].size(); j++)
                if (a[mp[t[i]][j]])
                {
                    flag = 0;
                    break;
                }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
