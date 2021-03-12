#include "iostream"
using namespace std;
struct node
{
    int top = -1;
    string s;
    int left, right;
} a[30];
void inorder(int root, int cnt)
{
    if (cnt != 0 && (a[root].left != -1 || a[root].right != -1))
        cout << "(";
    if (a[root].left != -1)
        inorder(a[root].left, cnt + 1);
    cout << a[root].s;
    if (a[root].right != -1)
        inorder(a[root].right, cnt + 1);
    if (cnt != 0 && (a[root].left != -1 || a[root].right != -1))
        cout << ")";
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].s >> a[i].left >> a[i].right;
        if (a[i].left != -1)
            a[a[i].left].top = i;
        if (a[i].right != -1)
            a[a[i].right].top = i;
    }
    int root = 1;
    while (a[root].top != -1)
        root = a[root].top;
    inorder(root, 0);
}
