#include "iostream"
#include "vector"
using namespace std;
struct node
{
    int top = -1;
    int left = -1, right = -1;
};
int n;
vector<node> v;
void inp()
{
    string s;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s != "-")
        {
            v[i].left = stoi(s);
            v[stoi(s)].top = i;
        }
        cin >> s;
        if (s != "-")
        {
            v[i].right = stoi(s);
            v[stoi(s)].top = i;
        }
    }
}
int ind, ans;
void dfs(int x, int index)
{
    if (ind < index)
        ind = index, ans = x;
    if (v[x].left != -1)
        dfs(v[x].left, 2 * index + 1);
    if (v[x].right != -1)
        dfs(v[x].right, 2 * index + 2);
}
void work()
{
    int root = 0;
    while (v[root].top != -1)
        root = v[root].top;
    dfs(root, 0);
    if (ind == n - 1)
        cout << "YES " << ans;
    else
        cout << "NO " << root;
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
