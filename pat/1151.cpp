#include "iostream"
#include "unordered_map"
#include "vector"
using namespace std;
/*
    和1143不同，本题的树不是BST，因此无法根据值的大小下沉
    不过由于先序遍历是左根右，因此可以把先序遍历的编号作为BST
 */
int m, n;
vector<int> pre, in, post;
int cnt = 0;
unordered_map<int, int> mp;
unordered_map<int, bool> ex;
struct node
{
    int val;
    int newval;
    node *left = NULL, *right = NULL;
    node(int x)
    {
        val = x;
    }
} * root;
node *create(int preL, int preR, int inL, int inR)
{
    if (preL > preR)
        return NULL;
    int i;
    for (i = inL; i <= inR; i++)
        if (in[i] == pre[preL])
            break;
    node *p = new node(in[i]);
    p->newval = mp[in[i]];
    p->left = create(preL + 1, preL + i - inL, inL, i - 1);
    p->right = create(preL + i - inL + 1, preR, i + 1, inR);
    return p;
}
void getPre(node *root)
{
    if (root == NULL)
        return;
    getPre(root->left);
    cout << root->val << " ";
    getPre(root->right);
}
void inp()
{
    cin >> m >> n;
    pre.resize(n + 1);
    in.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> in[i], mp[in[i]] = i, ex[in[i]] = true;
    for (int i = 1; i <= n; i++)
        cin >> pre[i];
    root = create(1, n, 1, n);
}
void work()
{
    int x, y;
    while (m--)
    {
        cin >> x >> y;
        node *tmp = root;
        int newx = mp[x];
        int newy = mp[y];
        if (!ex[x] || !ex[y])
        {
            if (!ex[x] && !ex[y])
                printf("ERROR: %d and %d are not found.\n", x, y);
            else if (!ex[x])
                printf("ERROR: %d is not found.\n", x);
            else
                printf("ERROR: %d is not found.\n", y);
            continue;
        }
        while ((newx < tmp->newval && newy < tmp->newval) || (newx > tmp->newval && newy > tmp->newval))
        {
            if (newx < tmp->newval && newy < tmp->newval)
                tmp = tmp->left;
            if (newx > tmp->newval && newy > tmp->newval)
                tmp = tmp->right;
        }
        if (tmp->val == x)
            printf("%d is an ancestor of %d.\n", x, y);
        else if (tmp->val == y)
            printf("%d is an ancestor of %d.\n", y, x);
        else
            printf("LCA of %d and %d is %d.\n", x, y, tmp->val);
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
