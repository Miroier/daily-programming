#include "iostream"
using namespace std;
int n;
int cnt;
int count(int x)
{
    int c = 0;
    while (x)
    {
        if (x % 10 == 1)
            c++;
        x /= 10;
    }
    return c;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cnt += count(i);
    }
    cout << cnt;
}
