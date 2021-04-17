#include "cstring"
#include "map"
#include <iostream>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
map<int, int> mp;
int n, m;
LL mat[6][6];
LL ans[6][6];
void mul(LL c[][6], LL a[][6], LL b[][6])
{
    LL tmp[6][6];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < 6; k++)
                tmp[i][j] = (tmp[i][j] + (LL)a[i][k] * b[k][j]) % MOD;
    memcpy(c, tmp, sizeof(tmp));
}
void qpow(int b)
{
    while (b)
    {
        if (b & 1)
            mul(ans, ans, mat);
        b >>= 1;
        mul(mat, mat, mat);
    }
}
int main()
{
    cin >> n >> m;
    mp[0] = 3, mp[1] = 4, mp[2] = 5, mp[3] = 0, mp[4] = 1, mp[5] = 2;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            mat[i][j] = 4;
    for (int i = 0; i < 6; i++)
        ans[0][i] = 4;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        mat[x][mp[y]] = 0, mat[y][mp[x]] = 0;
    }
    qpow(n - 1);
    LL res = 0;
    for (int i = 0; i < 6; i++)
        res += ans[0][i];
    cout << res % MOD;
    return 0;
}
