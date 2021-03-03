#include "iostream"
#include "queue"
#include "vector"
using namespace std;
struct node
{
    int up = -1;
    int left = -1, right = -1;
};
int n;
vector<node> v;
vector<int> in;
vector<int> level;
void inp()
{
    cin >> n;
    getchar();
    v.resize(n);
    string c1, c2;
    for (int i = 0; i < n; i++)
    {
        cin >> c1 >> c2;
        if (c1 != "-")
        {
            //翻转
            v[i].right = stoi(c1);
            v[stoi(c1)].up = i;
        }
        if (c2 != "-")
        {
            v[i].left = stoi(c2);
            v[stoi(c2)].up = i;
        }
    }
}
void level_order(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        level.push_back(q.front());
        if (v[q.front()].left != -1)
            q.push(v[q.front()].left);
        if (v[q.front()].right != -1)
            q.push(v[q.front()].right);
        q.pop();
    }
}
void in_order(int root)
{
    if (v[root].left != -1)
        in_order(v[root].left);
    in.push_back(root);
    if (v[root].right != -1)
        in_order(v[root].right);
}
void work()
{
    int root;
    for (root = 0; v[root].up != -1; root = v[root].up)
        ;
    level_order(root);
    for (int i = 0; i < level.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << level[i];
    }
    cout << endl;
    in_order(root);
    for (int i = 0; i < in.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << in[i];
    }
    cout << endl;
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
