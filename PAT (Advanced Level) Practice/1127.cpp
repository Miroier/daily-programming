#include "iostream"
#include "queue"
#include "vector"
using namespace std;
/*
    1 建树
    2 层序遍历，保存结果
    3 根据层数的奇偶进行输出
 */
struct node
{
    int val;
    node *left = NULL, *right = NULL;
    int depth;
} * root;
int n;
vector<int> pre, in, post, res[35];
node *create(int inL, int inR, int postL, int postR)
{
    if (inL > inR)
        return NULL;
    node *tmp = new node;
    tmp->val = post[postR];
    int i = inL;
    while (i < inR && in[i] != post[postR])
        i++;
    tmp->left = create(inL, i - 1, postL, postR - (inR - i) - 1);
    tmp->right = create(i + 1, inR, postR - (inR - 1), postR - 1);
    return tmp;
}
void bfs()
{
    queue<node *> q;
    root->depth = 0;
    q.push(root);
    while (!q.empty())
    {
        node *tmp = q.front();
        if (tmp->left)
        {
            tmp->left->depth = tmp->depth + 1;
            q.push(tmp->left);
        }
        if (tmp->right)
        {
            tmp->right->depth = tmp->depth + 1;
            q.push(tmp->right);
        }
        q.pop();
        res[tmp->depth].push_back(tmp->val);
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    in.resize(n + 1);
    post.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> in[i];
    for (int i = 1; i <= n; i++)
        cin >> post[i];
    root = create(1, n, 1, n);
    bfs();
    cout << res[0][0];
    for (int i = 1; i < 35; i++)
    {
        if (i % 2 == 1)
            for (int j = 0; j < res[i].size(); j++)
                cout << " " << res[i][j];
        else
            for (int j = res[i].size() - 1; j >= 0; j--)
                cout << " " << res[i][j];
    }
}
