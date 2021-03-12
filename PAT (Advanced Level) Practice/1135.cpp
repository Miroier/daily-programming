#include "iostream"
using namespace std;
struct node
{
    int val;
    node *left = NULL, *right = NULL;
    bool type; //0:red 1:black
    node(int x)
    {
        val = abs(x);
        if (x > 0)
            type = 1;
        else
            type = 0;
    }
};
node *insert(node *root, int val)
{
    if (root == NULL)
    {
        root = new node(val);
        return root;
    }
    if (abs(val) < root->val)
        root->left = insert(root->left, val);
    else if (abs(val) > root->val)
        root->right = insert(root->right, val);
    return root;
}
bool judge1(node *root)
{
    if (root == NULL)
        return true;
    if (root->type == 0)
    {
        if (root->left != NULL && root->left->type != 1)
            return false;
        if (root->right != NULL && root->right->type != 1)
            return false;
    }
    return judge1(root->left) && judge1(root->right);
}
int getSum(node *root)
{
    if (root == NULL)
        return 0;
    int l = getSum(root->left);
    int r = getSum(root->right);
    // return (root->type == 1 ? max(l, r) + 1 : max(l, r));
    return (root->type == 1 ? l + 1 : l);
}
bool judge2(node *root)
{
    if (root == NULL)
        return true;
    int l = getSum(root->left);
    int r = getSum(root->right);
    if (l != r)
        return false;
    return judge2(root->left) && judge2(root->right);
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int k, n;
    cin >> k;
    while (k--)
    {
        cin >> n;
        node *root = NULL;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            root = insert(root, x);
        }
        bool flag = 1;
        flag &= (root->type == 1);
        flag &= judge1(root);
        flag &= judge2(root);
        if (flag)
            puts("Yes");
        else
            puts("No");
    }
}
