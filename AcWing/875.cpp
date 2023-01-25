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
        int a, b, p;
        cin >> a >> b >> p;
        cout << qmi(a, b, p) << endl;
    }
}
