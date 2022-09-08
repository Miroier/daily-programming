#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int a[N];
int n, m;
int l, r;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1];
    while (m--)
    {
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
}
