#include "cstring"
#include "iostream"
using namespace std;
typedef long long LL;
const int N = 3;
int n, m;
LL base[N][N] = {{1, 1, 1}, {1, 0, 0}, {0, 0, 1}}, ans[N][N] = {{1, 1, 1}, {0, 0, 0}, {0, 0, 0}};
void mul(LL c[][N], LL a[][N], LL b[][N])
{
    LL tmp[N][N];
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                tmp[i][j] = (tmp[i][j] + (LL)a[i][k] * b[k][j]) % m;
    memcpy(c, tmp, sizeof tmp);
}
void qpow(int b)
{
    while (b)
    {
        if (b & 1)
            mul(ans, ans, base);
        b >>= 1;
        mul(base, base, base);
    }
}
int main()
{
    cin >> n >> m;
    qpow(n - 1);
    cout << ans[0][N - 1];
}
