#include <iostream>
using namespace std;

const int N = 1005;

int n, m;
int v[N], w[N];
int f[N]; // f[i]只用到了f[i-1]，可以用滚动数组，又因为f[j]用到的f[j-v[i]]是第i-1层的，不是第i层的，所以应该倒序遍历

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m];
}
