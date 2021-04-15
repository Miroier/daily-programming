#include "algorithm"
#include <iostream>
using namespace std;
const int N = 1e4 + 5;
int n;
struct seg
{
    int x, y1, y2;
    int type;
    bool friend operator<(seg a, seg b)
    {
        return a.x < b.x;
    }
} seg[N * 2];
struct node
{
    int left, right;
    int cnt; //被覆盖次数
    int len;
} tr[N * 4];
void build(int u, int left, int right)
{
    tr[u] = {left, right};
    if (left == right)
        return;
    int mid = left + right >> 1;
    build(u << 1, left, mid);
    build(u << 1 | 1, mid + 1, right);
}
void pushup(int u)
{
    if (tr[u].cnt > 0)
        tr[u].len = tr[u].right - tr[u].left + 1;
    else if (tr[u].left == tr[u].right)
        tr[u].len = 0;
    else
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
}
void modify(int u, int left, int right, int v)
{
    if (tr[u].left >= left && tr[u].right <= right)
    {
        tr[u].cnt += v;
        pushup(u);
    }
    else
    {
        int mid = tr[u].left + tr[u].right >> 1;
        if (left <= mid)
            modify(u << 1, left, right, v);
        if (right > mid)
            modify(u << 1 | 1, left, right, v);
        pushup(u);
    }
}
int main()
{
    cin >> n;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        seg[m++] = {x1, y1, y2, 1};
        seg[m++] = {x2, y1, y2, -1};
    }
    sort(seg, seg + m);
    build(1, 0, 10000);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (i > 0)
            ans += tr[1].len * (seg[i].x - seg[i - 1].x);
        modify(1, seg[i].y1, seg[i].y2 - 1, seg[i].type);
    }
    cout << ans;
    return 0;
}
