#include "iostream"
#include "queue"
#include "vector"
using namespace std;
int n, m;
vector<int> a[110];
queue<int> b, c;
int cnt[110]; //每层叶子结点个数
int depth = 0;
void inp()
{
    cin >> n >> m;
    int s, k, t;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> t;
            a[s].push_back(t);
        }
    }
}
void traverse(queue<int> &b, queue<int> &c)
{
    while (!b.empty())
    {
        if (!a[b.front()].size())
            cnt[depth]++;
        else
            for (int k = 0; k < a[b.front()].size(); k++)
                c.push(a[b.front()][k]);
        b.pop();
    }
}
void work()
{
    b.push(1);
    while (!b.empty() || !c.empty())
    {
        if (!b.empty())
        {
            traverse(b, c);
            depth++;
        }
        else
        {
            traverse(c, b);
            depth++;
        }
    }
    for (int i = 0; i < depth; i++)
        cout << cnt[i] << (i < depth - 1 ? " " : "");
}
int main()
{
    inp();
    work();
}
