#include "algorithm"
#include "iostream"
using namespace std;
const int N = 10005;
int a[N];
bool st[N];
int n;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            cnt++;
            for (int j = i; !st[j]; j = a[j])
                st[j] = true;
        }
    }
    cout << n - cnt;
}
