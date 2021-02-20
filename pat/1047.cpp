#include "algorithm"
#include "cstdio"
#include "iostream"
#include "map"
#include "vector"
using namespace std;
int n, k;
map<int, vector<string>> mp; //用set最后一个点超时 尽量printf
void inp()
{
    scanf("%d %d", &n, &k);
    string name;
    int id, c;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        scanf("%d", &c);
        while (c--)
        {
            scanf("%d", &id);
            mp[id].push_back(name);
        }
    }
}
void work()
{
    for (int i = 1; i <= k; i++)
    {
        printf("%d %d\n", i, mp[i].size());
        sort(mp[i].begin(), mp[i].end());
        for (auto it = mp[i].begin(); it != mp[i].end(); it++)
            printf("%s\n", (*it).c_str());
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
