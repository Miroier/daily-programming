#include "iostream"
using namespace std;
typedef long long LL;
/*
测试数据，观察是否递增
-1 0
-1 1
0 1
1 1
1 0
1 -1
0 -1
-1 -1
-2 -1
-2 0
-2 1
-2 2
-1 2
0 2
1 2
2 2
2 1
2 0
2 -1
2 -2
1 -2
0 -2
-1 -2
-2 -2
-3 -2
-3 -1
-3 0
-3 1
-3 2
-3 3
-2 3
-1 3
0 3
1 3
2 3
3 3
3 2
3 1
3 0
3 -1
3 -2
3 -3
2 -3
1 -3
0 -3
-1 -3
-2 -3
-3 -3
 */
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    LL x, y;
    while (cin >> x >> y)
    {
        LL layer = max(abs(x), abs(y));
        LL sum = 0;
        sum = (LL)(layer - 1) * layer / 2 * 8;
        if (x < 0 && y <= 0)
        {
            if (abs(y) == layer)
                sum += -x + 7 * layer;
            else
                sum += (y + layer);
        }
        else if (x < 0 && y > 0)
        {
            sum += (y + layer + x) + layer;
        }
        else if (x >= 0 && y >= 0)
        {
            sum += (x + layer - y) + 3 * layer;
        }
        else if (x >= 0 && y < 0)
        {
            sum += (layer - x - y) + 5 * layer;
        }
        cout << sum << endl;
    }
}
