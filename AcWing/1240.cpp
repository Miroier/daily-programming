#include "iostream"
using namespace std;
const int N = 100005;
typedef long long LL;
int n;
int a[N];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int layer = 0;
    LL mx = -0x3fffffff;
    int mxlayer;
    int ind = 0;
    while (ind <= n)
    {
        LL sum = 0;
        for (ind = 1 << layer; ind <= n && ind <= (1 << layer + 1) - 1; ind++)
            sum += a[ind];
        if (mx < sum)
        {
            mx = sum;
            mxlayer = layer + 1;
        }
        layer++;
    }
    cout << mxlayer;
}
