#include "iostream"
#include "map"
#include "string"
using namespace std;
int n, k;
map<string, int> s2i;
map<int, string> i2s;
map<string, int> ans;
int idNumber = 1;
int weight[2010];
int g[2010][2010];
int s2ifunc(string s)
{
    if (s2i[s] == 0)
    {
        s2i[s] = idNumber;
        i2s[idNumber] = s;
        return idNumber++;
    }
    else
        return s2i[s];
}
void inp()
{
    cin >> n >> k;
    string s1, s2;
    int w;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2 >> w;
        int id1 = s2ifunc(s1);
        int id2 = s2ifunc(s2);
        weight[id1] += w;
        weight[id2] += w;
        g[id1][id2] += w;
        g[id2][id1] += w;
    }
}
bool vis[2010];
void dfs(int x, int &head, int &num, int &totalweight)
{
    vis[x] = true;
    num++;
    if (weight[x] > weight[head])
        head = x;
    for (int i = 1; i < idNumber; i++)
    {
        if (g[x][i] > 0)
        {
            totalweight += g[x][i];
            g[x][i] = g[i][x] = 0;
            if (!vis[i])
                dfs(i, head, num, totalweight);
        }
    }
}
void work()
{
    for (int i = 1; i < idNumber; i++)
    {
        if (!vis[i])
        {
            int head = i, num = 0, totalweight = 0;
            dfs(i, head, num, totalweight);
            if (num > 2 && totalweight > k)
                ans[i2s[head]] = num;
        }
    }
    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << it->first << " " << it->second << endl;
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
