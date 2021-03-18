#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
typedef long long LL;
const int N = 100005;
int n, m, t;
LL score[N];
vector<int> v[N];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m >> t;
    int ts, id;
    while (m--)
    {
        cin >> ts >> id;
        v[id].push_back(ts);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        int pre = 0;
        sort(v[i].begin(), v[i].end());
        for (auto now : v[i])
        {
            if (score[i] <= now - pre - 1)
                score[i] = 0;
            else
                score[i] -= max(0, now - pre - 1);
            if (score[i] <= 3)
                flag = 0;
            // 先判断移除再加2
            score[i] += 2;
            // printf("i:%d pre:%d now:%d score[i]:%d\n", i, pre, now, score[i]);
            if (score[i] > 5)
                flag = 1;
            pre = now;
        }
        if (t > pre)
        {
            score[i] -= max(0, t - pre);
            if (score[i] <= 3)
                flag = 0;
            // printf("i:%d pre:%d now:%d score[i]:%d\n", i, pre, t, score[i]);
        }
        cnt += flag;
    }
    cout << cnt;
}
