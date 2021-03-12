#include "algorithm"
#include "iostream"
using namespace std;
int n, m;
int a[400010];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = n; i < n + m; i++)
        cin >> a[i];
    sort(a, a + n + m);
    int target = (n + m - 1) >> 1;
    cout << a[target] << endl;
}
