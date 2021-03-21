/*
    维护一个动态的平均数
    将原数组升序排列
    如果某个人拥有的钱数小于平均数，那么它一定要出完所有钱，同时更新平均数
 */
#include "algorithm"
#include "cmath"
#include "iostream"
using namespace std;
const int N = 500005;
int n;
double S;
int a[N];
double b[N];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> S;
    double avgb = S / n, ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= S / (n - i + 1))
            b[i] = a[i];
        else
            b[i] = S / (n - i + 1);
        S -= b[i];
    }
    for (int i = 1; i <= n; i++)
        ans += (b[i] - avgb) * (b[i] - avgb);
    printf("%.4lf", sqrt(ans / n));
}
