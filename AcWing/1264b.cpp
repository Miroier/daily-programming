#include "iostream"
using namespace std;

const int N = 100005;
int n, m;
int w[N];
struct node
{
    int left, right;
    int sum;
} tr[4 * N];
void pushup(int root)
{
    tr[root].sum = tr[root << 1].sum + tr[root << 1 | 1].sum;
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
    // 如果区间被完全包含，直接返回值
    if (tr[root].left >= left && tr[root].right <= right)
        return tr[root].sum;
    // 否则递归算
    int mid = tr[root].left + tr[root].right >> 1;
    int sum = 0;
    if (left <= mid)
        sum = query(root << 1, left, right);
    if (right > mid)
        sum += query(root << 1 | 1, left, right);
    return sum;
}
void modify(int root, int loc, int val)
{
    if (tr[root].left == tr[root].right)
        tr[root].sum += val;
    else
    {
        int mid = tr[root].left + tr[root].right >> 1;
        if (loc <= mid)
            modify(root << 1, loc, val);
        else
            modify(root << 1 | 1, loc, val);
        pushup(root);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    build(1, 1, n);

    while (m--)
    {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 0)
            cout << query(1, a, b) << endl;
        else
            modify(1, a, b);
    }
}
