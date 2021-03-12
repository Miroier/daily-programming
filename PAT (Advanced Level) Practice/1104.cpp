#include "iostream"
#include "vector"
using namespace std;
typedef long long LL;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    LL tmp;
    cin >> n;
    LL sum = 0;
    double x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        tmp = x * 1000;
        sum += tmp * i * (n - i + 1); //次数是i*(n-i+1)
    }
    // 前缀和
    // for (int i = 1; i <= n; i++)
    //     cin >> v[i], v[i] += v[i - 1];
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = i; j <= n; j++)
    //     {
    //         sum += v[j] - v[i - 1];
    //     }
    // }
    printf("%.2lf", sum / 1000.0);
}
