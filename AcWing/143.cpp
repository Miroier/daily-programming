/*
    用Trie来存所有数的31位二进制数形式
    如果一个数是10100 （这里用5位二进制数作示意），找和它异或更大的数
    假设末尾是0
    第4位是1，那么和第4位数是0的数异或的结果一定比第4位是1的数异或的结果更大
 */
#include "algorithm"
#include "iostream"
#include "string"
using namespace std;
const int N = 100005, M = 31 * N;
int n, ans;
int son[M][2];
int idx;
void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
}
int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (son[p][!u])
            p = son[p][!u], res = res * 2 + !u;
        else
            p = son[p][u], res = res * 2 + u;
    }
    return res;
}
int main()
{
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        insert(x);
        ans = max(ans, x ^ query(x));
    }
    cout << ans;
}
