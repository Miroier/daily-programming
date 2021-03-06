#include "iostream"
#include "queue"
using namespace std;
struct node
{
    int val;
    node *left = NULL, *right = NULL;
    int depth;
    node(int val, int depth)
    {
        this->val = val;
        this->depth = depth;
    }
};
node *root;
int n1, n2;
int maxdepth;
node *insert(node *root, int x, int depth)
{
    if (root == NULL)
    {
        if (maxdepth < depth)
            maxdepth = depth;
        node *tmp = new node(x, depth);
        return tmp;
    }
    if (x <= root->val)
        root->left = insert(root->left, x, depth + 1);
    else
        root->right = insert(root->right, x, depth + 1);
    return root;
}
void dfs(node *p)
{
    if (p->depth == maxdepth)
        n1++;
    else if (p->depth == maxdepth - 1)
        n2++;
    if (p->left != NULL)
        dfs(p->left);
    if (p->right != NULL)
        dfs(p->right);
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x, 1);
    }
    // dfs
    dfs(root);
    cout << n1 << " + " << n2 << " = " << n1 + n2;
}
