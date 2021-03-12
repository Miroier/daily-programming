#include "cmath"
#include "iostream"
#include "map"
#include "vector"
using namespace std;
struct node
{
    int add, val, next;
};
node v[100010];
vector<node> res, del;
map<int, int> mp;
int start, n;
void inp()
{
    int add, val, next;
    cin >> start >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> add >> val >> next;
        v[add].add = add;
        v[add].val = val;
        v[add].next = next;
    }
}
void work()
{
    for (int i = start; i != -1; i = v[i].next)
    {
        if (mp[v[i].val] == 0)
        {
            res.push_back(v[i]);
            mp[v[i].val] = 1, mp[-v[i].val] = 1;
        }
        else
        {
            del.push_back(v[i]);
        }
    }
    for (int i = 0; i < res.size() - 1; i++)
        printf("%05d %d %05d\n", res[i].add, res[i].val, res[i + 1].add);
    printf("%05d %d -1\n", res[res.size() - 1].add, res[res.size() - 1].val);
    if (!del.size())
        return;
    for (int i = 0; i < del.size() - 1; i++)
        printf("%05d %d %05d\n", del[i].add, del[i].val, del[i + 1].add);
    printf("%05d %d -1\n", del[del.size() - 1].add, del[del.size() - 1].val);
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
