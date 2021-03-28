//假设原数列为 a,a*(p/q)^1,a*(p/q)^2,...,a*(p/q)^(n-1)
//假设抽取的数列  b0,b1,...,b(N-1)  (从小到大排好序了)
//  b1/b0,b2/b0,...,b(N-1)/b0-->  (p/q)^x1,(p/q)^x2,...,(p/q)^x(N-1)
//  我们要求的是：  （p/q）^k  (p/q)>1,所以使k最大，即求（p/q）^x1~(p/q)^x(N-1)的最大公约数，其实就是求x1~x(N-1)的最大公约数
//这里我们使用更相减损术，因为我们没有得到确切的x1~x(N-1)是多少，我们只有(p/q)^x1,(p/q)^x2,...,(p/q)^x(N-1)这些的值

/*更相减损术：第一步：任意给定两个正整数；判断它们是否都是偶数。若是，则用2约简；若不是则执行第二步。
第二步：以较大的数减较小的数，接着把所得的差与较小的数比较，并以大数减小数。继续这个操作，直到所得的减数和差相等为止。
则第一步中约掉的若干个2的积与第二步中等数的乘积就是所求的最大公约数。*/

//更相减损术总用较大的减去较小的
/*例子：
    98-63=35
    63-35=28
    35-28=7
    28-7=21
    21-7=14
    14-7=7
所以，98和63的最大公约数等于7。*/

//我们这里要用更相减损术的是指数，所以要让(p/q)^x1,(p/q)^x2,...,(p/q)^x(N-1)，两两计算，互除，除到结果为1,即x1=x2,此时幂次为0，结果为1，这其实就是y总的思路，再次感叹y总的才华
//把分子分母分别去算，结果是相同的因为，分子分母的幂次是相同的
#include "iostream"
using namespace std;
typedef long long LL;
const int N = 105;
int n;
LL x[N], a[N], b[N];
LL gcd(LL x, LL y)
{
    return y == 0 ? x : gcd(y, x % y);
}
LL gcd_sub(LL x, LL y)
{
    if (x < y)
        swap(x, y);
    if (y == 1)
        return x;
    return gcd_sub(y, x / y);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0;
    for (int i = 1; i < n; i++)
        if (x[i] != x[i - 1])
        {
            LL d = gcd(x[i], x[0]);
            a[cnt] = x[i] / d;
            b[cnt] = x[0] / d;
            cnt++;
        }
    LL up = a[0], down = b[0];
    for (int i = 1; i < cnt; i++)
    {
        up = gcd_sub(up, a[i]);
        down = gcd_sub(down, b[i]);
    }
    cout << up << "/" << down;
}
