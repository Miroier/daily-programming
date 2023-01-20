#include <iostream>
using namespace std;
const int N = 1e6 + 5;
int n;
bool is_prime[N];
int prime[N];
int cnt;
// 埃筛
void get_primes(int x)
{
    for (int i = 2; i <= x; i++)
        is_prime[i] = true;
    for (int i = 2; i <= x; i++)
    {
        if (is_prime[i])
        {
            prime[cnt++] = i;
            for (int j = i + i; j <= x; j += i)
                is_prime[j] = false;
        }
    }
}
int main()
{
    cin >> n;
    get_primes(n);
    cout << cnt << endl;
}
