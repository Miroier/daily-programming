/*
    f[i,j]:i个骰子垒在一起，最上面数字是j的所有合法方案
    六种情况，不考虑限制的情况下
        f[i-1, 1] * 4
        f[i-1, 2] * 4
        f[i-1, 3] * 4
        f[i-1, 4] * 4
        f[i-1, 5] * 4
        f[i-1, 6] * 4
    如果有限制，比如1-2，那么前一个骰子的j是1，后一个骰子的j就不能是5
    f[i]只和f[i-1]有关，所以可以压成一维
    f[i]=f[i-1] * A，A是一个矩阵，默认值都是4
 */
#include "cstring"
#include "iostream"
#include "map"
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
int n, m;
LL g[7][7];
LL f[7][7];
map<int, int> mp;
void mul(LL c[][7], LL a[][7], LL b[][7])
{
    LL tmp[7][7];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
            for (int k = 1; k <= 6; k++)
                tmp[i][j] = (tmp[i][j] + (LL)a[i][k] * b[k][j]) % MOD;
    memcpy(c, tmp, sizeof(tmp));
}
void qmi(int b)
{
    while (b)
    {
        if (b & 1)
            mul(f, f, g);
        b >>= 1;
        mul(g, g, g);
    }
}
int main()
{
    cin >> n >> m;
    fill(g[0], g[0] + 49, 4);
    mp[1] = 4, mp[2] = 5, mp[3] = 6, mp[4] = 1, mp[5] = 2, mp[6] = 3;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        g[x][mp[y]] = g[y][mp[x]] = 0;
    }
    //第一个骰子，6个面都有4种情况
    for (int i = 1; i <= 6; i++)
        f[1][i] = 4;
    //剩下的n-1个骰子
    qmi(n - 1);
    LL ans = 0;
    for (int i = 1; i <= 6; i++)
        ans += f[1][i];
    cout << ans % MOD;
}
