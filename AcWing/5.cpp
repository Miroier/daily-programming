#include <iostream>
using namespace std;
const int N = 2e5 + 5; // N*log(S)=1000*log(2000)<2e5
const int M = 2005;
int n, m;
int v[N], w[N];
int f[N];
int main()
{
    cin >> n >> m;
    int cnt = 0; //打包后的物品数量
    for (int i = 1; i <= n; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while (k <= s)
        {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if (s > 0)
        {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    n = cnt;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m];
}
