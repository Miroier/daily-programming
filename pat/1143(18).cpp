#include "algorithm"
#include "iostream"
#include "set"
using namespace std;
/*
    后三个点超时
    好家伙，原来是建树超时了，必须用前序遍历来建树
 */
const int maxn = 20005;
struct node
{
    int val;
    int id;
    node *left = NULL, *right = NULL;
    node *pre = NULL;
    int dep;
    node(int x, node *pre, int dep, int cnt)
    {
        val = x;
        this->pre = pre;
        this->dep = dep;
        id = cnt;
    }
} * root;
int m, n;
set<int> st;
int cnt = 0;
node *insert(node *root, int x, node *father, int depth)
{
    if (root == NULL)
        root = new node(x, father, depth, ++cnt);
    else if (x <= root->val)
        root->left = insert(root->left, x, root, depth + 1);
    else
        root->right = insert(root->right, x, root, depth + 1);
    return root;
}
void inp()
{
    cin >> m >> n;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        root = insert(root, x, NULL, 1);
        st.insert(x);
    }
}
int lca[10005][10005];
int LCA(node *u, node *v)
{
    node *x = u, *y = v;
    if (lca[x->id][y->id])
        return lca[x->id][y->id];
    if (x->val == y->val)
        return x->val;
    if (x->dep > y->dep)
        return lca[x->id][y->id] = LCA(x->pre, y);
    else if (x->dep < y->dep)
        return lca[x->id][y->id] = LCA(x, y->pre);
    else
        return lca[x->id][y->id] = LCA(x->pre, y->pre);
    // while (x->val != y->val)
    // {
    //     if (lca[x->id][y->id])
    //         return lca[x->id][y->id];
    //     if (x->dep < y->dep)
    //         y = y->pre;
    //     else if (x->dep > y->dep)
    //         x = x->pre;
    //     else
    //         x = x->pre, y = y->pre;
    // }
    // return x->val;
}
node *to_find(node *root, int x)
{
    if (x == root->val)
        return root;
    else if (x < root->val)
        return to_find(root->left, x);
    else
        return to_find(root->right, x);
}
void work()
{
    int x, y;
    while (m--)
    {
        cin >> x >> y;
        if (st.find(x) == st.end() || st.find(y) == st.end())
        {
            if (st.find(x) == st.end() && st.find(y) == st.end())
                printf("ERROR: %d and %d are not found.\n", x, y);
            else if (st.find(x) == st.end())
                printf("ERROR: %d is not found.\n", x);
            else if (st.find(y) == st.end())
                printf("ERROR: %d is not found.\n", y);
            continue;
        }
        node *u = to_find(root, x), *v = to_find(root, y);
        int ans = LCA(u, v);
        if (ans == x)
            printf("%d is an ancestor of %d.\n", x, y);
        else if (ans == y)
            printf("%d is an ancestor of %d.\n", y, x);
        else
            printf("LCA of %d and %d is %d.\n", x, y, ans);
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
