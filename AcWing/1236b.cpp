#include "algorithm"
#include "iostream"
using namespace std;
typedef long long LL;
const int N = 100005;
int n;
int a[N], b[N], c[N];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    sort(c + 1, c + 1 + n);
    LL sum = 0;
    int ap = 1, cp = 1;
    for (int i = 1; i <= n; i++)
    {
        //a[ap]<b[i] ap尽可能大
        while (a[ap] < b[i] && ap <= n)
            ap++;
        // c[cp]>b[i] cp尽可能小 由于cp之后会变大，所以正向找
        while (c[cp] <= b[i] && cp <= n)
            cp++;
        sum += (LL)(ap - 1) * (n - cp + 1);
    }
    cout << sum;
}
