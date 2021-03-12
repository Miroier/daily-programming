#include "algorithm"
#include "iostream"
using namespace std;
int a[100005];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    int x;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x > 0)
            a[cnt++] = x;
    }
    sort(a, a + cnt);
    for (int i = 1; i < cnt; i++)
        if (a[i] != a[i - 1] && a[i] != a[i - 1] + 1)
        {
            cout << a[i - 1] + 1;
            return 0;
        }
    cout << a[cnt - 1] + 1;
}
