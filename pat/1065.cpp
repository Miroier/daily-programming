#include "cstdio"
#include "iostream"
using namespace std;
typedef long long LL;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    LL n;
    LL a, b, c, sum;
    bool flag;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld %lld %lld", &a, &b, &c); //这里用cin过不了最后一个点
        sum = a + b;
        if (a > 0 && b > 0 && sum < 0) //正溢出
            flag = true;
        else if (a < 0 && b < 0 && sum >= 0) //负溢出
            flag = false;
        else if (sum > c)
            flag = true;
        else
            flag = false;
        if (flag)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
}
