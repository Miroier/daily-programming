#include "iostream"
#include "set"
using namespace std;
const int N = 100005;
#define lowbit(x) ((x) & (-x))
typedef long long LL;
int n, m;
LL c[N];
int a[N];
set<int> pos[N];
void update(int x, LL v)
{
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += v;
}
LL getSum(int x)
{
    LL sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        update(i, a[i]);
    }
    while (m--)
    {
        int op;
        scanf("%d", &op);
        if (op == 2)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", getSum(r) - getSum(l - 1));
        }
        else
        {
            int l, r, v;
            scanf("%d%d%d", &l, &r, &v);
            if (v != 1)
                for (int i = l; i <= r; i++)
                    if (a[i] >= v && a[i] % v == 0)
                    {
                        update(i, -a[i] + a[i] / v);
                        a[i] /= v;
                    }
        }
    }
}
