#include "iostream"
#define lowbit(x) ((x) & (-x))
using namespace std;
/*
    交换的次数至少是逆序对的数量
    在冒泡排序中，每次交换必然使逆序对数量减少1，且已知冒泡排序的正确性
    所以逆序对的数量就是交换的总次数
    对于每一个数，它前面比它大的一定会交换，它后面比它小的也一定会交换
 */
typedef long long LL;
const int N = 1000005;
int n;
int a[100005];
int c[N];
LL cnt[100005];
void update(int x, int v)
{
    for (int i = x; i < N; i += lowbit(i))
        c[i] += v;
}
int getSum(int x)
{
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = getSum(N - 1) - getSum(a[i]); //比当前值大的
        update(a[i], 1);
    }
    fill(c, c + N, 0);
    for (int i = n; i >= 1; i--)
    {
        cnt[i] += getSum(a[i] - 1); //比当前值小的
        update(a[i], 1);
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++)
        ans += cnt[i] * (cnt[i] + 1) / 2;
    cout << ans;
}
