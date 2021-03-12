#include "iostream"
using namespace std;
int n, d;
bool isprime[100010];
int prime[100010];
void Prime(int n)
{
    int cnt = 0;
    for (int i = 0; i <= n; i++)
        isprime[i] = true;
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (isprime[i])
        {
            prime[cnt++] = i;
            for (int j = i * i; j <= n; j += i)
                isprime[j] = false;
        }
}
int main()
{
    while (cin >> n, n >= 0)
    {
        cin >> d;
        Prime(n);
        if (!isprime[n])
        {
            cout << "No" << endl;
            continue;
        }
        int len = 0, arr[100];
        while (n)
        {
            arr[len++] = n % d;
            n /= d;
        }
        for (int i = 0; i < len; i++)
            n = n * d + arr[i];
        Prime(n);
        cout << (isprime[n] ? "Yes" : "No") << endl;
    }
}
