#include <iostream>
#include <vector>
using namespace std;
const int N = 5005;
int primes[N], cnt;
bool is_prime[N];
int sum[N];
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
        is_prime[i] = true;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            primes[cnt++] = i;
        for (int j = 0; i * primes[j] <= n; j++)
        {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0)
                break;
        }
    }
}
// 求n的质因子分解后，包含多少个质数p
int get(int n, int p)
{
    int res = 0;
    while (n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}
vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}
int main()
{
    int a, b;
    cin >> a >> b;
    // 预处理出1~N中所有质数
    get_primes(a);
    // 枚举每个质数出现的次数
    for (int i = 0; i < cnt; i++)
    {
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p); // C_a^b的质因子分解后，包含多少个质数p
    }
    // 高精度乘法将所有的质数乘起来
    vector<int> res;
    res.push_back(1);
    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < sum[i]; j++)
            res = mul(res, primes[i]);
    for (int i = res.size() - 1; i >= 0; i--)
        printf("%d", res[i]);
}
