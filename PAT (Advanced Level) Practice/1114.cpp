#include "algorithm"
#include "iostream"
using namespace std;
struct data
{
    int id, fid, mid, num, area;
    int cid[10];
} data[1010];
struct node
{
    int id, people;
    double num, area;
    bool flag = false;
} ans[10000];
int dad[10000];
bool vis[10000];
int anc(int x)
{
    if (x != dad[x])
        x = anc(dad[x]);
    return x;
}
void uni(int x, int y)
{
    x = anc(x);
    y = anc(y);
    if (x > y)
        dad[x] = y;
    if (x < y)
        dad[y] = x;
}
bool cmp(node &a, node &b)
{
    if (a.area != b.area)
        return a.area > b.area;
    return a.id < b.id;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n, k, cnt = 0;
    cin >> n;
    for (int i = 0; i < 10000; i++)
        dad[i] = i;
    for (int i = 0; i < n; i++)
    {
        cin >> data[i].id >> data[i].fid >> data[i].mid >> k;
        vis[data[i].id] = true;
        if (data[i].fid != -1)
        {
            vis[data[i].fid] = true;
            uni(data[i].fid, data[i].id);
        }
        if (data[i].mid != -1)
        {
            vis[data[i].mid] = true;
            uni(data[i].mid, data[i].id);
        }
        for (int j = 0; j < k; j++)
        {
            cin >> data[i].cid[j];
            vis[data[i].cid[j]] = true;
            uni(data[i].cid[j], data[i].id);
        }
        cin >> data[i].num >> data[i].area;
    }
    for (int i = 0; i < n; i++)
    {
        int id = anc(data[i].id);
        ans[id].id = id;
        ans[id].num += data[i].num;
        ans[id].area += data[i].area;
        ans[id].flag = true; //把所有的根节点标记为true
    }
    for (int i = 0; i < 10000; i++)
    {
        if (vis[i])
            ans[anc(i)].people++;
        if (ans[i].flag)
            cnt++;
    }
    for (int i = 0; i < 10000; i++)
    {
        if (ans[i].flag)
        {
            ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
        }
    }
    sort(ans, ans + 10000, cmp);
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
        printf("%04d %d %.3lf %.3lf\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
}
