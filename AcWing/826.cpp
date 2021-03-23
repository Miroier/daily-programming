#include "iostream"
using namespace std;
const int N = 100005;
int h, e[N], ne[N], idx = 0;
void add(int x)
{
    e[idx] = x;
    ne[idx] = h;
    h = idx++;
}
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}
void del(int k)
{
    ne[k] = ne[ne[k]];
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    h = -1;
    int n;
    char c;
    int k, x;
    cin >> n;
    while (n--)
    {
        cin >> c;
        if (c == 'H')
        {
            scanf("%d", &x);
            add(x);
        }
        if (c == 'I')
        {
            scanf("%d%d", &k, &x);
            add(k - 1, x);
        }
        if (c == 'D')
        {
            scanf("%d", &k);
            if (k == 0)
                h = ne[h];
            else
                del(k - 1);
        }
    }
    for (int i = h; ~i; i = ne[i])
        cout << e[i] << " ";
}
