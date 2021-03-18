#include "iostream"
using namespace std;
int n;
bool check(int x)
{
    while (x)
    {
        int t = x % 10;
        if (t == 2 || t == 0 || t == 1 || t == 9)
            return true;
        x /= 10;
    }
    return false;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (check(i))
            sum += i;
    cout << sum;
}
