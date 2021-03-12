#include "iostream"
using namespace std;
int n;
int a[100010];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    a[0] = 0, a[1] = 1;
    int i;
    for (i = 1; a[i] < n; i++)
    {
        a[i + 1] = a[i] + a[i - 1];
    }
    if (abs(a[i] - n) < abs(a[i - 1] - n))
        cout << a[i];
    else
        cout << a[i - 1];
}
