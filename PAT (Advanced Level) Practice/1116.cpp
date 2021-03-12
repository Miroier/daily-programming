#include "iostream"
using namespace std;
bool isprime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n, k;
    int a[10010];
    bool checked[10010];
    fill(checked, checked + 10010, false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int x;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        int j;
        for (j = 1; j <= n; j++)
        {
            if (a[j] == x)
                break;
        }
        if (j == n + 1)
            printf("%04d: Are you kidding?\n", x);
        else if (checked[x])
            printf("%04d: Checked\n", x);
        else if (j == 1)
            printf("%04d: Mystery Award\n", x);
        else if (isprime(j))
            printf("%04d: Minion\n", x);
        else
            printf("%04d: Chocolate\n", x);
        checked[x] = true;
    }
}
