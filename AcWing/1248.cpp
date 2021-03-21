/*
    需要用前缀和
    对原序列做一次操作，例如
    a_{i−1}+=ai,a_{i+1}+=ai,ai−=2ai
    相关的前缀和数组会从
    s_{i-1} si s_{i+1}
    变成
    s_i s_{i-1} s_{i+1}
    效果是交换了s_{i-1}和si
    因为要计算第一个武士的灵能需要s[0]，所以在计算中s[0]也需要包含进去
    下标从1开始，只有s[0]和s[n]不能被交换
    题目要求每个数的绝对值尽可能小，也就是让前缀和序列两两之间的差的绝对值的最大值尽可能小。可以用排序来解决，这样两两之差最小，但是s[0]和s[n]不能动，所以需要额外处理
    ![](https://firebasestorage.googleapis.com/v0/b/firescript-577a2.appspot.com/o/imgs%2Fapp%2FMiroier%2FakGlKl3Q3y.png?alt=media&token=3d96f5a0-7be2-45e6-8a4d-45bc2e7f122d)
 */
#include "algorithm"
#include "iostream"
using namespace std;
typedef long long LL;
const int N = 300005;
int n, t;
LL a[N];
LL sum[N];
bool st[N];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> t;
    while (t--)
    {
        cin >> n;
        fill(a, a + N, 0);
        fill(sum, sum + N, 0);
        for (int i = 1; i <= n; i++)
            cin >> a[i], sum[i] = a[i] + sum[i - 1];
        LL s0 = sum[0], sn = sum[n];
        if (s0 > sn)
            swap(s0, sn);
        sort(sum, sum + n + 1);

        for (int i = 0; i <= n; i++)
            if (sum[i] == s0)
            {
                s0 = i;
                break;
            }
        //如果s0和sn相等，s0取前一个，sn取后一个
        for (int i = n; i >= 0; i--)
            if (sum[i] == sn)
            {
                sn = i;
                break;
            }
        fill(st, st + N, false);
        int left = 0, right = n;
        //用a来记录值
        for (int i = s0; i >= 0; i -= 2)
        {
            a[left++] = sum[i];
            st[i] = true;
        }
        for (int i = sn; i <= n; i += 2)
        {
            a[right--] = sum[i];
            st[i] = true;
        }
        for (int i = 0; i <= n; i++)
            if (!st[i])
                a[left++] = sum[i];

        LL res = 0;
        for (int i = 1; i <= n; i++)
            res = max(res, abs(a[i] - a[i - 1]));
        cout << res << endl;
    }
}
