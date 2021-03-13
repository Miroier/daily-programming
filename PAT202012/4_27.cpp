#include "algorithm"
#include "iostream"
#include "set"
#include "vector"
using namespace std;
int n, m, k;
vector<set<int>> v[100];
set<int> reac;
vector<int> ques;
bool cmp(set<int> a, set<int> b)
{
    string s1 = "", s2 = "";
    for (auto x : a)
        s1 += to_string(x);
    for (auto x : b)
        s2 += to_string(x);
    return s1 < s2;
}
void inp()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        reac.insert(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        ques.push_back(x);
        set<int> tmp;
        tmp.insert(x);
        v[x].push_back(tmp);
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x;
        set<int> tmp;
        string s;
        cin >> x;
        tmp.insert(x);
        while (cin >> s, s == "+")
        {
            cin >> x;
            tmp.insert(x);
        }
        cin >> x;
        v[x].push_back(tmp);
    }
    for (int i = 0; i < ques.size(); i++)
        sort(v[ques[i]].begin(), v[ques[i]].end(), cmp);
}
bool check(set<int> st)
{
    for (auto x : st)
        if (reac.find(x) == reac.end())
            return false;
    return true;
}
vector<vector<int>> res;
bool flag = 0;
void dfs(int cnt)
{
    if (cnt == ques.size())
    {
        flag = 1;
        for (int j = 0; j < res.size(); j++)
        {
            vector<int> ans = res[j];
            for (int i = 0; i < res[j].size(); i++)
                printf("%02d%s", ans[i], (i < ans.size() - 1 ? " + " : ""));
            printf(" -> %02d\n", ques[j]);
        }
        return;
    }
    int des = ques[cnt];
    vector<int> ans;
    for (int j = 0; j < v[des].size(); j++)
    {
        if (check(v[des][j]))
        {
            for (auto x : v[des][j])
            {
                ans.push_back(x);
                reac.erase(reac.find(x));
            }
            res.push_back(ans);
            dfs(cnt + 1);
            res.pop_back();
            ans.clear();
            for (auto x : v[des][j])
                reac.insert(x);
        }
        if (flag)
            return;
    }
}
void work()
{
    dfs(0);
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
