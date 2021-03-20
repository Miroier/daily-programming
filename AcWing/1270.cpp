#include "iostream"
using namespace std;

const int N = 100005;

int n, m;
int w[N];
struct node
{
    int left, right;
    int mx;
} tr[4 * N];
void pushup(int u)
{
    tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}
void build(int root, int left, int right)
{
    if (left == right)
        tr[root] = {left, right, w[left]};
    else
    {
        tr[root] = {left, right};
        int mid = left + right >> 1;
        build(root << 1, left, mid);
        build(root << 1 | 1, mid + 1, right);
        pushup(root);
    }
}
int query(int root, int left, int right)
{
    if (tr[root].left >= left && tr[root].right <= right)
        return tr[root].mx;
    int mid = tr[root].left + tr[root].right >> 1;
    int mx = 0;
    if (left <= mid)
        mx = query(root << 1, left, right);
    if (right > mid)
        mx = max(mx, query(root << 1 | 1, left, right));
    return mx;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    build(1, 1, n);
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", query(1, a, b));
    }
}
