#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n, m, k;
struct stu
{
    int id;
    int ge, gi;
    int final;
    int rank;
    int apply[6];
};
struct sch
{
    int quota;
    int cnt;
    vector<int> stu;
};
vector<sch> s;
vector<stu> v;
void inp()
{
    cin >> n >> m >> k;
    s.resize(m);
    v.resize(n);
    for (int i = 0; i < m; i++)
        cin >> s[i].quota;
    int ge, gi, a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> ge >> gi;
        v[i].id = i;
        v[i].ge = ge, v[i].gi = gi, v[i].final = (ge + gi) / 2;
        for (int j = 0; j < k; j++)
            cin >> v[i].apply[j];
    }
}
bool cmp1(stu &a, stu &b)
{
    if (a.final != b.final)
        return a.final > b.final;
    return a.ge > b.ge;
}
void work()
{
    sort(v.begin(), v.end(), cmp1);
    v[0].rank = 1;
    for (int i = 1; i < n; i++)
    {
        v[i].rank = i + 1;
        if (v[i].final == v[i - 1].final && v[i].ge == v[i - 1].ge)
            v[i].rank = v[i - 1].rank;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int target = v[i].apply[j];
            if (!s[target].stu.empty())
            {
                if (v[i].rank == v[s[target].stu[s[target].stu.size() - 1]].rank)
                {
                    s[target].stu.push_back(i);
                    s[target].cnt++;
                    break;
                }
            }
            if (s[target].cnt < s[target].quota)
            {
                s[target].stu.push_back(i);
                s[target].cnt++;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (s[i].stu.empty())
            cout << endl;
        else
        {
            vector<int> res;
            for (int j = 0; j < s[i].stu.size(); j++)
                res.push_back(v[s[i].stu[j]].id);
            sort(res.begin(), res.end());
            for (int j = 0; j < res.size(); j++)
            {
                if (j != 0)
                    cout << " ";
                cout << res[j];
            }
            cout << endl;
        }
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
