#include "iostream"
using namespace std;
/*
    由于y是递增的，所以只需要考虑之前有多少个星星的x比当前星星的x小，后续的星星由于至少在x或y上比当前星星大，所以不用考虑。
    如何知道之前有多少个星星的x比当前星星的x小呢？
    x的最大值是32000，可以用树状数组来维护
    如果x的范围很大，数组放不下的话，可以用离散化来处理（要求n不大）
 */
#define lowbit(x) ((x) & (-x))
const int N = 32005;
int n;
int s[N];
int cnt[15005];
void update(int x, int v)
{
    for (int i = x; i < N; i += lowbit(i))
        s[i] += v;
}
int getSum(int x)
{
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        sum += s[i];
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
    {
        int x, y;
        cin >> x >> y;
        x++;
        cnt[getSum(x)]++;
        update(x, 1);
    }
    for (int i = 0; i < n; i++)
        cout << cnt[i] << endl;
}
