#include <iostream>
using namespace std;
using LL = long long;
const int MOD = 1e9 + 7;
int qmi(int a, int b, int p)
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
        res = (LL)res * j % MOD;
        res = (LL)res * qmi(i, MOD - 2, MOD) % MOD;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    int res = (LL)C(2 * n, n) * qmi(n + 1, MOD - 2, MOD) % MOD;
    cout << res << endl;
}
