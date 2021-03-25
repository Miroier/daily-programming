#include "algorithm"
#include "cstring"
#include "iostream"
#include "set"
#include "unordered_map"
#include "vector"
using namespace std;
#define x first
#define y second
typedef pair<int, int> PII;
const int N = 55;
int m, n;
set<PII> g[N];
unordered_map<int, int> f[N];
int sum[N], cnt[N];
set<PII>::reverse_iterator it[N];
vector<int> ans[N];
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int id, score;
        cin >> id >> score;
        for (int j = 0; j < m; j++)
        {
            f[j][id] = score;
            g[j].insert({score, -id}); //先按分数从小到大，再按id从大到小
        }
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int type, id, score;
            cin >> type >> id >> score;
            f[type][id] = score;
            g[type].insert({score, -id});
        }
        else if (t == 2)
        {
            int type, id;
            cin >> type >> id;
            g[type].erase({f[type][id], -id});
            f[type].erase(id);
        }
        else
        {
            int tot;
            cin >> tot;
            for (int i = 0; i < m; i++)
            {
                cin >> sum[i];
                it[i] = g[i].rbegin(); //反向迭代，因为从大到小来求
                cnt[i] = 0;
                ans[i].clear();
            }
            while (tot--)
            {
                int k = -1;
                for (int i = 0; i < m; i++)
                    if (it[i] != g[i].rend() && cnt[i] < sum[i])
                        if (k == -1 || it[i]->x > it[k]->x)
                            k = i;
                if (k == -1)
                    break;
                ans[k].push_back(-it[k]->y);
                cnt[k]++;
                it[k]++;
            }
            for (int i = 0; i < m; i++)
                if (ans[i].empty())
                    puts("-1");
                else
                {
                    for (auto x : ans[i])
                        printf("%d ", x);
                    puts("");
                }
        }
    }
}
