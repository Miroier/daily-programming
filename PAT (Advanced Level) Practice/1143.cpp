#include "iostream"
#include "unordered_map"
using namespace std;
/*
    更改了建树方法，现在是前序遍历建树，
    如果还是之前那种建树方法，依然会超时，这说明之前的问题不是出在lca上
 */
struct node
{
    int val;
    node *left = NULL, *right = NULL;
    node(int x)
    {
        val = x;
    }
} * root;
int m, n;
int preorder[10000];
unordered_map<int, node *> mp;
node *create(int left, int right)
{
    if (left > right)
        return NULL;
    node *p = new node(preorder[left]);
    mp[preorder[left]] = p;
    int i;
    for (i = left + 1; i <= right; i++)
        if (preorder[i] > preorder[left])
            break; // 右子树的根节点
    p->left = create(left + 1, i - 1);
    p->right = create(i, right);
    return p;
}
void inp()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    root = create(0, n - 1);
}
void work()
{
    int x, y;
    while (m--)
    {
        cin >> x >> y;
        if (!mp.count(x) && !mp.count(y))
            printf("ERROR: %d and %d are not found.\n", x, y);
        else if (!mp.count(x))
            printf("ERROR: %d is not found.\n", x);
        else if (!mp.count(y))
            printf("ERROR: %d is not found.\n", y);
        else
        {
            node *cur = root;
            while ((x < cur->val && y < cur->val) || (x > cur->val && y > cur->val))
            {
                if (x < cur->val && y < cur->val)
                    cur = cur->left;
                if (x > cur->val && y > cur->val)
                    cur = cur->right;
            }
            if ((x < cur->val && y > cur->val) || (x > cur->val && y < cur->val))
                printf("LCA of %d and %d is %d.\n", x, y, cur->val);
            else if (x == cur->val)
                printf("%d is an ancestor of %d.\n", x, y);
            else if (y == cur->val)
                printf("%d is an ancestor of %d.\n", y, x);
        }
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
