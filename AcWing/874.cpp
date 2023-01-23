#include <iostream>
using namespace std;
using LL = long long;
const int N = 1e6 + 5;
int n;
int primes[N], cnt;
bool is_prime[N];
int phi[N]; // 欧拉函数
LL get_eulers(int x)
{
    for (int i = 2; i <= n; i++)
        is_prime[i] = true;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= x / i; j++)
        {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0)
            {
                // primes[j]是i的质因子，由于phi[i]的值已经考虑了primes[j]，所以phi[i * primes[j]]的值要在phi[i]的基础上多乘一个primes[j]。
                phi[i * primes[j]] = primes[j] * phi[i];
                break;
            }
            // primes[j]不是i的质因子，由于phi[i]的值没有考虑primes[j]，所以phi[i * primes[j]]的值要在phi[i]的基础上多乘一个primes[j]和(1-1/primes[j])。
            phi[i * primes[j]] = (primes[j] - 1) * phi[i];
        }
    }
    LL res = 0;
    for (int i = 1; i <= x; i++)
        res += phi[i];
    return res;
}
int main()
{
    cin >> n;
    cout << get_eulers(n) << endl;
}
