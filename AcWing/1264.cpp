#include "iostream"
using namespace std;
#define lowbit(x) ((x) & (-x))
const int N = 100000;
int n, m;
int a[N], c[N];
void update(int x, int val)
{
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += val;
}
int getSum(int x)
{
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], update(i, a[i]);
    while (m--)
    {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 0)
            cout << getSum(b) - getSum(a - 1) << endl;
        ;
        if (k == 1)
            update(a, b);
    }
}
