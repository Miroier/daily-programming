#include "algorithm"
#include "iostream"
#include "set"
#include "vector"
using namespace std;
/*
    可以考虑用并查集
    对于每个输入，把i对应的k个数都做一边合并
 */
int n;
vector<int> people[1010];
int dad[1010];
set<int> cnt[1010];
bool isRoot[1010];
int anc(int x)
{
    while (dad[x])
        x = anc(dad[x]);
    return x;
}
void uni(int x, int y)
{
    x = anc(x);
    y = anc(y);
    if (x != y)
    {
        dad[x] = y;
        isRoot[x] = false; //根节点变成y，x不再是根节点
        set<int> tmp;
        for (auto i : cnt[x])
            tmp.insert(i);
        for (auto i : cnt[y])
            tmp.insert(i);
        cnt[y] = tmp; //更新集合
    }
}
void inp()
{
    cin >> n;
    int k;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        getchar();
        int x;
        while (k--)
        {
            cin >> x;
            cnt[x].insert(i);       //x集合中包含i，用来计数
            people[i].push_back(x); //i属于集合x
            isRoot[x] = true;       //最开始时，每个点都是根节点
        }
    }
}
vector<int> ans;
bool cmp(int a, int b)
{
    return a > b;
}
void work()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < people[i].size(); j++)
            uni(people[i][j], people[i][j - 1]); //i在集合j和j-1中，合并两个集合
    for (int i = 1; i <= 1000; i++)
        if (isRoot[i])
            ans.push_back(cnt[i].size());
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << ans[i];
    }
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
