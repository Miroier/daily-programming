#include "algorithm"
#include "iostream"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int a[100010];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    bool flag = 1;
    for (int i = 1; i <= n; i++)
        if (a[i] <= i)
        {
            flag = 0;
            cout << i - 1;
            break;
        }
    if (flag)
        cout << n;
}
