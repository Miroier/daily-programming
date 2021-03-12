#include "iostream"
#include "map"
using namespace std;
int m, n;
map<int, int> mp;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> m >> n;
    int x;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            if (mp[x])
                mp[x]++;
            else
                mp[x] = 1;
        }
    int mx = 0, ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
        if (mx < it->second)
            mx = it->second, ans = it->first;
    cout << ans;
}
