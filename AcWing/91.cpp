#include "cstring"
#include "iostream"
using namespace std;
/*
    状态表示f[i,j]
        集合：所有从0走到j，中间走过的所有点是i的所有路径（i是二进制数）
        属性：Min
    状态计算
        f[i,j]=min(f[i,j],f[i-{j},k]+a[k,j]);k是倒数第二个点
 */
const int N = 20, M = 1 << 20;
int n;
int a[N][N];
int f[M][N];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0; //只走过0点
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i & 1 << j) //状态i要包含点j
                for (int k = 0; k < n; k++)
                    if (i - (1 << j) & 1 << k) //如果i除去点j之后包含k
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + a[k][j]);
    cout << f[(1 << n) - 1][n - 1];
}
