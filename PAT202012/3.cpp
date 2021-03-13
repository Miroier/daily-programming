#include "iostream"
#include "unordered_map"
#include "vector"
using namespace std;
int n;
vector<int> v[10000];
unordered_map<int, bool> mp;
void inp()
{
    scanf("%d\n", &n);
    vector<int> predep;
    predep.push_back(0);
    vector<int> prenum;
    prenum.push_back(0);
    mp[0] = true;
    int st;
    scanf("%d", &st);
    getchar();
    for (int i = 1; i < n; i++)
    {
        string s;
        getline(cin, s);
        int dep = s.size() - 4;
        int x = stoi(s);
        mp[x] = true;
        if (dep == predep.back() + 1)
        {
            v[prenum.back()].push_back(x);
        }
        else if (dep <= predep.back())
        {
            int ind = predep.size() - 1;
            while (dep <= predep[ind])
                ind--;
            v[prenum[ind]].push_back(x);
        }
        predep.push_back(dep);
        prenum.push_back(x);
        // cout << x << " " << dep << endl;
    }
}
vector<int> path;
void dfs(int x, int des)
{
    if (x == des)
    {
        path.push_back(x);
        for (int i = 0; i < path.size(); i++)
            printf("%04d%s", path[i], (i < path.size() - 1 ? "->" : "\n"));
        path.pop_back();
        return;
    }
    path.push_back(x);
    for (int i = 0; i < v[x].size(); i++)
        dfs(v[x][i], des);
    path.pop_back();
}
void work()
{
    int k;
    cin >> k;
    while (k--)
    {
        int x;
        cin >> x;
        if (mp[x])
            dfs(0, x);
        else
            printf("Error: %04d is not found.\n", x);
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
