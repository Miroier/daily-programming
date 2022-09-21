#include <iostream>
using namespace std;

const int N = 1005;
int n, m;
int v[N], w[N];
int f[N]; // f[i]只用到了f[i-1]，可以用滚动数组，和01背包不同的是，因为f[j]用到的f[j-v[i]]是第i层的，所以正序遍历j

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m];
}
