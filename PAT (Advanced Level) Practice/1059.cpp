#include "iostream"
#include "map"
#include "vector"
using namespace std;
vector<bool> prime(50000, 1);
int n;
pair<int, int> fac[10];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    for (int i = 2; i * i < 50000; i++)
        for (int j = i * i; j < 5000; j += i)
            prime[j] = 0;
    cin >> n;
    printf("%d=", n);
    int num = 0;
    if (n == 1)
        cout << "1";
    for (int i = 2; i < 50000; i++)
    {
        if (prime[i] == 1 && n % i == 0)
        {
            fac[num].first = i;
            fac[num].second = 0;
            while (n % i == 0)
            {
                fac[num].second++;
                n /= i;
            }
            num++;
        }
        if (n == 1)
            break;
    }
    for (int i = 0; i < num; i++)
    {
        if (i > 0)
            cout << "*";
        cout << fac[i].first;
        if (fac[i].second > 1)
            cout << "^" << fac[i].second;
    }
}
