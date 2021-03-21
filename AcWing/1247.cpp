/*
    如果M=0 全部加
    M>0 可以通过 -(x1-x2-x3) 的方式将负号变成正号 所以1到M个负号均可
    考虑到也可以将+放进括号里变成-，所以负号的个数实际上是1到N+M的负号
    至少减1个数，加一个数（因为第一个数前没有符号），所以可以减最小值，加最大值，中间的数加绝对值
 */
#include "algorithm"
#include "iostream"
using namespace std;
int n, m;
int a[200005];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    int k = n + m + 1;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    long long sum = 0;
    if (m == 0)
        for (int i = 0; i < k; i++)
            sum += a[i];
    else
    {
        sort(a, a + k, cmp);
        sum += a[0];
        sum -= a[k - 1];
        for (int i = 1; i < k - 1; i++)
            sum += abs(a[i]);
    }
    cout << sum;
}
