#include "cstring"
#include "iostream"
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
const LL MOD = 1e18;
int n;
LL v[N]; //总价值
int fa[N], w[N], f[N];
LL ans[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(ans, 0, sizeof(ans));
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> fa[i] >> w[i] >> v[i] >> f[i];
        for (int i = n; i; i--)
        {
            int k = fa[i], d = w[i];
            while (k) //向上遍历到根节点
            {
                ans[k] = max(ans[k], v[k] - (LL)(f[k] - d) * (f[k] - d) + ans[i]);
                d += w[k];
                k = fa[k];
            }
        }
        LL res = 0;
        for (int i = 1; i <= n; i++)
            res = (res + ans[i]) % MOD;
        cout << res << endl;
    }
}
