#include "iostream"
#include "queue"
#include "vector"
using namespace std;
struct node
{
    int val;
    node *left = NULL, *right = NULL;
    node(int val)
    {
        this->val = val;
    }
} * root;
int n;
node *LeftRotate(node *root)
{
    node *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}
node *RightRotate(node *root)
{
    node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    return tmp;
}
node *LR(node *root)
{
    root->left = LeftRotate(root->left);
    return RightRotate(root);
}
node *RL(node *root)
{
    root->right = RightRotate(root->right);
    return LeftRotate(root);
}
int getHeight(node *p)
{
    if (p == NULL)
        return 1;
    return max(getHeight(p->left), getHeight(p->right)) + 1;
}
node *insert(node *root, int x)
{
    if (root == NULL)
    {
        node *tmp = new node(x);
        return tmp;
    }
    if (x < root->val)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    if (getHeight(root->left) - getHeight(root->right) == 2)
    {
        if (getHeight(root->left->left) - getHeight(root->left->right) == 1)
            root = RightRotate(root);
        else
            root = LR(root);
    }
    if (getHeight(root->right) - getHeight(root->left) == 2)
    {
        if (getHeight(root->right->right) - getHeight(root->right->left) == 1)
            root = LeftRotate(root);
        else
            root = RL(root);
    }
    return root;
}
int maxInd;
void bfs()
{
    vector<int> ans;
    queue<node *> q;
    queue<int> ind;
    q.push(root);
    ind.push(1);
    while (!q.empty())
    {
        if (maxInd < ind.front())
            maxInd = ind.front();
        ans.push_back(q.front()->val);
        if (q.front()->left)
        {
            q.push(q.front()->left);
            ind.push(ind.front() * 2);
        }
        if (q.front()->right)
        {
            q.push(q.front()->right);
            ind.push(ind.front() * 2 + 1);
        }
        q.pop();
        ind.pop();
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << (i < ans.size() - 1 ? " " : "\n");
    cout << (maxInd == n ? "YES" : "NO");
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
    }
    bfs();
}
