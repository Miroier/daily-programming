#include "iostream"
#include "set"
#include "unordered_map"
#include "vector"
using namespace std;
typedef long long LL;
int n, m;
unordered_map<LL, bool> mp;
set<int> st;
bool a[100000];
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
        a[x] = 1, a[y] = 1;
        mp[x * 100000 + y] = mp[y * 100000 + x] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        vector<int> t(x);
        for (int i = 0; i < x; i++)
            cin >> t[i];
        bool flag = 1;
        // 复杂度 m*x^2，只过了前两个测试点；
        // 某些点没有在上面的列表中出现过，遍历这些点就浪费了，加个数组标记一下，过了测试点2，但仍然不是满分
        for (int i = 0; i < x - 1; i++)
            if (a[t[i]])
                for (int j = i + 1; j < x; j++)
                    if (mp[t[i] * 100000 + t[j]])
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
