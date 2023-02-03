#include <iostream>
using namespace std;
using LL = long long;
int p;
int qmi(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}
int C(int a, int b)
{
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--)
    {
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p - 2) % p; // 逆元
    }
    return res;
}
int lucas(LL a, LL b)
{
    if (a < p && b < p)
        return C(a, b);
    return (LL)C(a % p, b % p) * lucas(a / p, b / p) % p;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        LL a, b;
        cin >> a >> b >> p;
        cout << lucas(a, b) << endl;
    }
}
