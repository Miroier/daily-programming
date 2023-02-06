#include <iostream>
using namespace std;
using LL = long long;
const int M = 20;
int n, m;
int p[M];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> p[i];
    int ans = 0;
    for (int i = 1; i < 1 << m; i++)
    {
        int t = 1, cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (i >> j & 1)
            {
                cnt++; // 计算选择了cnt个集合
                if ((LL)t * p[j] > n)
                {
                    t = -1;
                    break;
                }
                t *= p[j];
            }
        }
        if (t != -1)
        {
            if (cnt % 2) // 如果选择了奇数个集合，加，否则，减
                ans += n / t;
            else
                ans -= n / t;
        }
    }
    cout << ans << endl;
}
