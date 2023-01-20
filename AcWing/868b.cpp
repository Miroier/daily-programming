#include <iostream>
using namespace std;
const int N = 1e6 + 5;
int n;
bool is_prime[N];
int prime[N];
int cnt;
// 欧筛
void get_primes(int x)
{
    for (int i = 2; i <= x; i++)
        is_prime[i] = true;
    for (int i = 2; i <= x; i++)
    {
        if (is_prime[i])
            prime[cnt++] = i;
        for (int j = 0; prime[j] <= n / i; j++)
        {
            is_prime[prime[j] * i] = false;
            if (i % prime[j] == 0) // prime[j]一定是i的最小质因子
                break;
        }
    }
}
int main()
{
    cin >> n;
    get_primes(n);
    cout << cnt << endl;
}
