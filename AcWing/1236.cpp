#include "iostream"
using namespace std;
typedef long long LL;
const int N = 100005;
int n;
int a[N], b[N], c[N];
int cnta[N], cntc[N];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    // 值从0开始 所以可以让每个数+1，变成从1开始，这样前缀和的0位就空出来了
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i]++, cnta[a[i]]++;
    for (int i = 1; i <= n; i++)
        cin >> b[i], b[i]++;
    for (int i = 1; i <= n; i++)
        cin >> c[i], c[i]++, cntc[c[i]]++;
    for (int i = 1; i < N; i++)
        cnta[i] += cnta[i - 1], cntc[i] += cntc[i - 1];

    LL sum = 0;
    for (int i = 1; i <= n; i++)
        sum += (LL)cnta[b[i] - 1] * (cntc[N - 1] - cntc[b[i]]);
    cout << sum;
}
