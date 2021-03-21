#include "algorithm"
#include "cmath"
#include "iostream"
using namespace std;
const int N = 1005;
struct segment
{
    double left, right;
    bool friend operator<(segment a, segment b)
    {
        return a.right < b.right;
    }
} a[N];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].left = x - sqrt(d * d - y * y);
        a[i].right = x + sqrt(d * d - y * y);
        if (y > d)
        {
            cout << -1;
            return 0;
        }
    }
    sort(a, a + n);
    double pre = a[0].right;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i].left > pre)
            cnt++, pre = a[i].right;
    }
    cout << cnt;
}
