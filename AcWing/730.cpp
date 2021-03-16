#include "iostream"
using namespace std;
typedef long long LL;
int n;
int a[100005];
bool check(LL x)
{
    for (int i = 1; i <= n; i++)
    {
        if (x > 100005)
            return true;
        if (a[i] > x)
            x -= (a[i] - x);
        else
            x += (x - a[i]);
        if (x < 0)
            return false;
    }
    return true;
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
    int left = 0, right = 100005;
    while (left < right)
    {
        int mid = (left + right) >> 1;
        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }
    cout << left;
}
