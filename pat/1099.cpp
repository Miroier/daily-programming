#include "algorithm"
#include "iostream"
#include "queue"
using namespace std;
struct node
{
    int data;
    int left, right;
} a[105];
int n;
int b[105];
void inp()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].left >> a[i].right;
    for (int i = 0; i < n; i++)
        cin >> b[i];
}
int cnt = 0;
void dfs(int root, int level)
{
    if (a[root].left != -1)
        dfs(a[root].left, level + 1);
    a[root].data = b[cnt++];
    if (a[root].right != -1)
        dfs(a[root].right, level + 1);
}
queue<node> q;
void work()
{
    sort(b, b + n);
    dfs(0, 0);
    q.push(a[0]);
    while (!q.empty())
    {
        if (q.front().data != a[0].data)
            cout << " ";
        cout << q.front().data;
        if (q.front().left != -1)
            q.push(a[q.front().left]);
        if (q.front().right != -1)
            q.push(a[q.front().right]);
        q.pop();
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    inp();
    work();
}
