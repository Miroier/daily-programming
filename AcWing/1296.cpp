/*
    满足S等于所有约数之和的形式非常少
    所以可以尝试用爆搜来做
    枚举p和alpha
 */
#include "algorithm"
#include "iostream"
using namespace std;
const int N = 50000; //sqrt(2e9)
int prime[N], cnt;
bool st[N];      //是否被筛过
int ans[N], len; //len：答案个数
void Prime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            prime[cnt++] = i;
        for (int j = 0; prime[j] * i <= n; j++)
        {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}
//last表示上一个用的质数的下标是什么,prod当前最高次项的结果,S表示每次处理后剩余多少
bool is_prime(int x)
{
    if (x < N)
        return !st[x]; //没有被筛过说明就是质数，返回true
    for (int i = 0; prime[i] <= x / prime[i]; i++)
        if (x % prime[i] == 0)
            return false;
    return true;
}
void dfs(int last, int prod, int s)
{
    if (s == 1)
    {
        ans[len++] = prod;
        return;
    }
    // 特判是否s==1+p
    if (s - 1 > (last < 0 ? 0 : prime[last]) && is_prime(s - 1))
    {
        ans[len++] = prod * (s - 1);
    }
    for (int i = last + 1; prime[i] <= s / prime[i]; i++)
    {
        int p = prime[i];
        // j=1+p+p^2+...
        // t=p^k
        for (int j = 1 + p, t = p; j <= s; t *= p, j += t)
            if (s % j == 0)
                dfs(i, prod * t, s / j);
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    Prime(N - 1);
    int S;
    while (cin >> S)
    {
        len = 0;
        dfs(-1, 1, S);
        cout << len << endl;
        if (len)
        {
            sort(ans, ans + len);
            for (int i = 0; i < len; i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }
}
