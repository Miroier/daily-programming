#include "iostream"
#include "vector"
using namespace std;
/*
    当一个节点只有左子树或右子树时，树的形态不唯一。
    体现在序列中就是，先序遍历根节点的下一节点在后序遍历中的位置正好等于right-1
 */
vector<int> pre, post, in;
int n;
bool unique = true;
void inp()
{
    cin >> n;
    pre.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> post[i];
}
void getIn(int preleft, int preright, int postleft, int postright)
{
    if (preleft == preright)
    {
        in.push_back(pre[preleft]);
        return;
    }
    if (pre[preleft] == post[postright])
    {
        int i = preleft + 1;
        while (i <= preright && pre[i] != post[postright - 1])
            i++;
        if (i > preleft + 1)
            getIn(preleft + 1, i - 1, postleft, postleft + (i - preleft - 1) - 1);
        else
            unique = false;
        in.push_back(post[postright]);
        getIn(i, preright, postleft + (i - preleft - 1), postright - 1);
    }
}
void work()
{
    getIn(0, n - 1, 0, n - 1);
    if (unique)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for (int i = 0; i < n; i++)
        cout << in[i] << (i < n - 1 ? " " : "\n");
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
