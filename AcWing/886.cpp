#include <iostream>
using namespace std;
using LL = long long;
const int N = 1e5 + 5, MOD = 1e9 + 7;
int fact[N], infact[N];
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
void init()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (LL)fact[i - 1] * i % MOD;
        infact[i] = qmi(fact[i], MOD - 2, MOD) % MOD;
    }
}
int main()
{
    int n;
    cin >> n;
    init();
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << (LL)fact[a] * infact[a - b] % MOD * infact[b] % MOD << endl;
    }
}
