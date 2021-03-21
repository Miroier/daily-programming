#include "algorithm"
#include "iostream"
using namespace std;
/*
    如果有奇数个商店，应该建在中位数上
    如果有偶数个商店，应该建在中间两个商店中间
    证明：
    假设建在位置c
    dis = |A1-c| + |A2-c| + ··· + |An-1-c| + |An-c|
    dis = (|A1-c|+|An-c|) + (|A2-c|+|An-1-c|) + ...
    对于括号1 c在A1~An之间值最小（可以从几何意义上去想）
    剩下的类似，所以c在最中间的的位置距离最短
 */
typedef long long LL;
const int N = 100005;
int a[N];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    LL sum = 0;
    int x = a[n / 2 + 1]; //中位数
    for (int i = 1; i <= n; i++)
        sum += abs(a[i] - x);
    cout << sum;
}
