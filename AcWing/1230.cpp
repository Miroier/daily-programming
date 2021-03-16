#include "iostream"
using namespace std;
typedef long long LL;
/*
    首先求一遍前缀和
    枚举右端点r，判断从最左边到r-1的数中，和a[r]模k相同的数有多少
 */
int n, k;
LL a[100005];
LL cnt[100005]; //余数为x的数有多少个
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1];
    LL ans = 0;
    cnt[0]++;
    for (int i = 1; i <= n; i++)
        ans += cnt[a[i] % k], cnt[a[i] % k]++;
    // for (int i = 0; i < n; i++)
    //     for (int j = i + 1; j <= n; j++)
    //         if ((a[j] - a[i]) % k == 0)
    //             cnt++;
    cout << ans;
}
