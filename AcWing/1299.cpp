/*
    假设飞了b次，实际上是求x+bd同余y(mod n)，假设是y+an
    x+bd=y+an -> -an+bd=y-x
    如果gcd(n,d)可以整除y-x
        相当于求-a和b，由于要求b最小，所以可以从由公式b=b0+k*n/gcd(n,d)推出bmin = b0 mod n/gcd(n,d)
    否则无解
 */
#include "iostream"
using namespace std;
typedef long long LL;
int t;
LL Exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    LL d = Exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> t;
    while (t--)
    {
        LL n, d, x, y, a, b;
        cin >> n >> d >> x >> y;
        int gcd = Exgcd(n, d, a, b);
        if ((y - x) % gcd)
            cout << "Impossible" << endl;
        else
        {
            b *= (y - x) / gcd;
            n /= gcd;
            cout << (b % n + n) % n << endl;
        }
    }
}
