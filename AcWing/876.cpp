#include <iostream>
using namespace std;
using LL = long long;
int n;
LL qmi(LL a, LL b, LL p)
{
    a %= p;
    LL res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}
int main()
{
    cin >> n;
    while (n--)
    {
        int a, p;
        cin >> a >> p;
        int res = qmi(a, p - 2, p);
        if (a % p) // a是p的倍数，不互质
            cout << res << endl;
        else
            cout << "impossible" << endl;
    }
}
