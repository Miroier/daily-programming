#include "iostream"
#include "vector"
using namespace std;
struct node
{
    int add;
    int data;
    int next;
} a[100010];
vector<node> v, b1, b2, b3;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int head, n, K;
    cin >> head >> n >> K;
    int add, data, next;
    for (int i = 0; i < n; i++)
    {
        cin >> add >> data >> next;
        a[add].add = add;
        a[add].data = data;
        a[add].next = next;
    }
    for (int i = head; i != -1; i = a[i].next)
        v.push_back(a[i]);
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].data < 0)
            b1.push_back(v[i]);
        else if (v[i].data <= K)
            b2.push_back(v[i]);
        else
            b3.push_back(v[i]);
    }
    v.clear();
    for (int i = 0; i < b1.size(); i++)
        v.push_back(b1[i]);
    for (int i = 0; i < b2.size(); i++)
        v.push_back(b2[i]);
    for (int i = 0; i < b3.size(); i++)
        v.push_back(b3[i]);
    for (int i = 0; i < v.size() - 1; i++)
        printf("%05d %d %05d\n", v[i].add, v[i].data, v[i + 1].add);
    printf("%05d %d -1\n", v[v.size() - 1].add, v[v.size() - 1].data);
}
