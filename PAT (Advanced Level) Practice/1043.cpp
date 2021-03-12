#include "iostream"
#include "vector"
using namespace std;
int n;
vector<int> pre, post;
bool isMirror;
/*
    关于getpost的作用
    以非镜像和测试数据为例：
            8
        6       10
      5   7   8   11
    i寻找的是大于等于root的第一个数，也就是10
    j寻找的是小于root的第一个数，也就是7
    这样j之前的是root的左子树，i之后的是root的右子树
    递归即可，后序遍历所以最后把root放进post中
 */
void getpost(int root, int tail)
{
    if (root > tail)
        return;
    int i = root + 1, j = tail;
    if (!isMirror)
    {
        while (i <= tail && pre[root] > pre[i])
            i++;
        while (j > root && pre[root] <= pre[j])
            j--;
    }
    else
    {
        while (i <= tail && pre[root] <= pre[i])
            i++;
        while (j > root && pre[root] > pre[j])
            j--;
    }
    if (i - j != 1)
        return;
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);
}
void inp()
{
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++)
        cin >> pre[i];
}
void work()
{
    getpost(0, n - 1);
    if (post.size() != n)
    {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if (post.size() == n)
    {
        cout << "YES" << endl
             << post[0];
        for (int i = 1; i < post.size(); i++)
            cout << " " << post[i];
    }
    else
        cout << "NO";
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
