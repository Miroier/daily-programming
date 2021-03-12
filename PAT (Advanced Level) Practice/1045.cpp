#include "iostream"
#include "vector"
using namespace std;
int n, m, L;
int dp[10010], book[210];
vector<int> v;
// 去掉多余的元素后，把原序列中的颜色换成下标，然后按最长不下降子序列来做
void inp()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    int x;
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        book[x] = i;
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> x;
        if (book[x])
            v.push_back(book[x]);
    }
}
void work()
{
    int maxn = 0;
    for (int i = 0; i < v.size(); i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (v[i] >= v[j])
                dp[i] = max(dp[i], dp[j] + 1);
        maxn = max(maxn, dp[i]);
    }
    cout << maxn;
}
int main()
{
    inp();
    work();
}
