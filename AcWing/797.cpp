#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int n, m;
int l, r, c;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        b[i] = a[i] - a[i - 1];
    while (m--)
    {
        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++)
        a[i] = b[i], a[i] += a[i - 1];
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}
