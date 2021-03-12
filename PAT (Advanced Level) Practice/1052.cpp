#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
struct node
{
    int add;
    int val;
    int next;
};
int n;
vector<node> v;
node link[100010];
bool cmp(node &a, node &b)
{
    return a.val < b.val;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int start;
    cin >> n >> start;
    int add, val, next;
    for (int i = 0; i < n; i++)
    {
        cin >> add >> val >> next;
        link[add].add = add;
        link[add].val = val;
        link[add].next = next;
    }
    //有可能一些结点不在链表中，这里需要从头结点开始依次放进vector中
    for (int i = start; i != -1; i = link[i].next)
        v.push_back(link[i]);
    if (!v.empty())
    {
        sort(v.begin(), v.end(), cmp);
        printf("%d %05d\n", v.size(), v[0].add);
        for (int i = 0; i < v.size() - 1; i++)
            printf("%05d %d %05d\n", v[i].add, v[i].val, v[i + 1].add);
        printf("%05d %d -1\n", v[v.size() - 1].add, v[v.size() - 1].val);
    }
    else
        cout << "0 -1" << endl;
}
