#include "iostream"
using namespace std;
int n, m;
int a[100005];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1];
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
}
