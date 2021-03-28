#include "iostream"
using namespace std;
const int N = 105, M = 1 << 20;
const int INF = 0x3fffffff;
int n, m, k;
int state[N];
int f[M];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            state[i] |= 1 << x - 1;
        }
    fill(f, f + M, INF);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 1 << m; j++)
            f[j | state[i]] = min(f[j | state[i]], f[j] + 1);
    if (f[(1 << m) - 1] == INF)
        cout << "-1" << endl;
    else
        cout << f[(1 << m) - 1] << endl;
}
