#include "algorithm"
#include "iostream"
using namespace std;
const int N = 100005;
int n;
int a[N];
int diff[N];
int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++)
        diff[i] = a[i] - a[i - 1];
    int pre = diff[2];
    for (int i = 3; i <= n; i++)
        pre = gcd(pre, diff[i]);
    if (pre != 0)
        cout << (a[n] - a[1]) / pre + 1;
    else
        cout << n;
}
