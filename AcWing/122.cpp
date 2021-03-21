#include "algorithm"
#include "iostream"
using namespace std;
typedef long long LL;
const int N = 1000005;
int n;
LL a[N];
LL c[N];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    LL avg = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], avg += a[i];
    avg /= n;
    for (int i = n; i > 1; i--)
        c[i] = c[i + 1] + avg - a[i];
    c[1] = 0;
    sort(c + 1, c + 1 + n);
    LL ans = 0;
    for (int i = 1; i <= n; i++)
        ans += abs(c[i] - c[n / 2 + 1]);
    cout << ans;
}
