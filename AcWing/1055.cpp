#include "iostream"
using namespace std;
const int N = 100005;
int a[N];
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
    int sum = 0;
    for (int i = 1; i <= n;)
    {
        int ind = i;
        while (a[ind + 1] > a[ind])
            ind++;
        sum += a[ind] - a[i];
        i = ind + 1;
    }
    cout << sum;
}
