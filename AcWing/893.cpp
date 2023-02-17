#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;
const int N = 105, M = 10005;
int n, m;
int s[N], f[M]; // f[i]：SG(石子数量i)
int sg(int x)
{
    if (f[x] != -1) // 记忆化搜索
        return f[x];
    unordered_set<int> S; // 存所有x可以到达的局面
    for (int i = 0; i < m; i++)
    {
        int sum = s[i];
        if (x >= sum)
            S.insert(sg(x - sum));
    }
    // 求mex
    for (int i = 0;; i++)
        if (!S.count(i))
            return f[x] = i;
}
int main()
{
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> s[i];
    cin >> n;
    memset(f, -1, sizeof(f));
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }
    if (res)
        puts("Yes");
    else
        puts("No");
}
