#include <iostream>
using namespace std;
const int N = 1005;
int n;
int a[N];
int f[N];
int main()
{
    fill(f, f + N, 1);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i]);
    cout << res << endl;
}
