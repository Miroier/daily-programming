#include <iostream>
using namespace std;
using LL = long long;
int n;
int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main()
{
    cin >> n;
    while (n--)
    {
        int a, b, m;
        scanf("%d%d%d", &a, &b, &m);
        int x, y;
        int d = exgcd(a, m, x, y);
        if (b % d == 0)
            printf("%d\n", (LL)x * (b / d) % m);
        else
            puts("impossible");
    }
}
