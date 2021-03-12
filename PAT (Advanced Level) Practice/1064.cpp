#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n;
vector<int> v;
int level[1010];
int cnt = 0;
void inp()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
}
void inOrder(int root)
{
    if (root >= n)
        return;
    inOrder(2 * root + 1);
    level[root] = v[cnt++];
    inOrder(2 * root + 2);
}
void work()
{
    sort(v.begin(), v.end()); //排序后是二叉搜索树的中序遍历，BST的性质
    inOrder(0);               //进行一遍中序遍历，并且把根结点存储起来
    printf("%d", level[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", level[i]);
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
