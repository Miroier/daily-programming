#include "algorithm"
#include "cmath"
#include "iostream"
#include "vector"
using namespace std;
struct mouse
{
    int ind0;
    int weight;
    int ind;
    int rank;
};
int np, ng;
vector<mouse> v;
void inp()
{
    cin >> np >> ng;
    int x;
    for (int i = 0; i < np; i++)
    {
        cin >> x;
        v.push_back({i, x});
    }
    for (int i = 0; i < np; i++)
        cin >> x, v[x].ind = i;
}
bool cmp1(mouse &a, mouse &b)
{
    return a.ind < b.ind;
}
bool cmp2(mouse &a, mouse &b)
{
    return a.ind0 < b.ind0;
}
bool cmp3(mouse &a, mouse &b)
{
    return a.weight > b.weight;
}
void work()
{
    sort(v.begin(), v.end(), cmp1);
    vector<mouse> ans;
    while (!v.empty())
    {
        vector<mouse> tmp;
        vector<mouse> next;
        int cnt;
        if (v.size() % ng != 0)
            cnt = v.size() / ng + 1;
        else
            cnt = v.size() / ng;
        while (!v.empty())
        {
            for (int j = 0; j < min(ng, (int)v.size()); j++)
                tmp.push_back(v[j]);
            if (v.size() >= ng)
                v.erase(v.begin(), v.begin() + ng);
            else
                v.erase(v.begin(), v.end());
            sort(tmp.begin(), tmp.end(), cmp3);
            if (tmp.size() >= 1 && cnt >= 1 && !(tmp.size() == 1 && cnt == 1))
            {
                next.push_back(tmp[0]);
                tmp.erase(tmp.begin());
                for (int j = 0; j < tmp.size(); j++)
                {
                    tmp[j].rank = cnt + 1;
                    ans.push_back(tmp[j]);
                }
            }
            else // tmp.size() == 1 && cnt == 1
            {
                tmp[0].rank = 1;
                ans.push_back(tmp[0]);
            }
            // if (tmp.size() > 1 && cnt > 1)
            // {
            //     next.push_back(tmp[0]);
            //     tmp.erase(tmp.begin());
            //     for (int j = 0; j < tmp.size(); j++)
            //     {
            //         tmp[j].rank = cnt + 1;
            //         ans.push_back(tmp[j]);
            //     }
            // }
            // else if (tmp.size() == 1 && cnt > 1)
            // {
            //     next.push_back(tmp[0]);
            //     tmp.erase(tmp.begin());
            // }
            // else if (tmp.size() > 1 && cnt == 1)
            // {
            //     next.push_back(tmp[0]);
            //     tmp.erase(tmp.begin());
            //     for (int j = 0; j < tmp.size(); j++)
            //     {
            //         tmp[j].rank = cnt + 1;
            //         ans.push_back(tmp[j]);
            //     }
            // }
            // else // tmp.size() == 1 && cnt == 1
            // {
            //     tmp[0].rank = 1;
            //     ans.push_back(tmp[0]);
            // }
            tmp.clear();
        }
        v = next;
    }
    sort(ans.begin(), ans.end(), cmp2);
    cout << ans[0].rank;
    for (int i = 1; i < ans.size(); i++)
        cout << " " << ans[i].rank;
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
