/*
    将原数组排序
    1 k==n 全选
    2 k<n
        2.1 如果k是偶数，结果必然非负
            2.1.1 如果负数有偶数个，可以一对一对选
            2.1.2 如果负数有奇数个，可以少选一个负数。剩下的负数成对选
        2.2 如果k是奇数个
            2.2.1 所有都是负数，必然小于0
            2.2.2 否则至少存在一个非负数，那么就选择这个非负数，然后变成2.1.2的情况
 */
#include "algorithm"
#include "iostream"
using namespace std;
typedef long long LL;
const int MOD = 1000000009;
const int N = 100005;
int n, k;
LL a[N];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int left = 1, right = n;
    sort(a + 1, a + 1 + n);
    LL ans = 1;
    if (k == n)
    {
        for (int i = 1; i <= n; i++)
            ans = (ans * a[i]) % MOD;
    }
    else
    {
        if (k % 2)
        {
            if (a[n] < 0)
                for (int i = n; i >= n - k + 1; i--)
                    ans = (ans * a[i]) % MOD;
            else
            {
                ans = (ans * a[n]) % MOD;
                n--, k--;
            }
        }
        if (k % 2 == 0)
        {
            int left = 1, right = n;
            int cnt = 0;
            while (cnt < k)
            {
                if (a[left] * a[left + 1] > a[right] * a[right - 1] && cnt + 2 <= k)
                {
                    ans = ((a[left] * a[left + 1]) % MOD * ans) % MOD;
                    left += 2;
                    cnt += 2;
                }
                else
                {
                    ans = (ans * a[right]) % MOD;
                    right--;
                    cnt++;
                }
            }
        }
    }
    cout << ans;
}
