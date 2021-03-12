#include "iostream"
#include "map"
#include "vector"
using namespace std;
vector<int> post, in;
map<int, int> level; //由于map自动按index排序，所以可以将结点下标存进去
int n;
void inp()
{
    int x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x, post.push_back(x);
    for (int i = 0; i < n; i++)
        cin >> x, in.push_back(x);
}
void pre(int root, int start, int end, int index)
{
    if (start > end)
        return;
    int i = start;
    while (i < end && in[i] != post[root]) //找根节点
        i++;
    level[index] = post[root];
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
    pre(root - 1, i + 1, end, 2 * index + 2);
}
void work()
{
    pre(n - 1, 0, n - 1, 0);
    auto it = level.begin();
    cout << it->second;
    while (++it != level.end())
        cout << " " << it->second;
}
int main()
{
    inp();
    work();
}
