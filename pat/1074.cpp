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
node link[100010];
int n, k;
int head;
vector<node> v;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> head >> n >> k;
    int add, val, next;
    for (int i = 0; i < n; i++)
    {
        cin >> add >> val >> next;
        link[add].add = add;
        link[add].val = val;
        link[add].next = next;
    }
    for (int i = head; i != -1; i = link[i].next)
        v.push_back(link[i]);
    for (int i = 0; i + k <= v.size(); i += k)
        reverse(v.begin() + i, v.begin() + i + k);
    for (int i = 0; i < v.size() - 1; i++)
        printf("%05d %d %05d\n", v[i].add, v[i].val, v[i + 1].add);
    printf("%05d %d -1\n", v[v.size() - 1].add, v[v.size() - 1].val);
}
