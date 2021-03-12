#include "algorithm"
#include "iostream"
#include "map"
#include "unordered_map"
#include "vector"
using namespace std;
struct sch
{
    string name;
    double score; //过程中用浮点数计算
    int final;    //最终整数成绩
    int cnt;
    int rank;
};
vector<sch> v;
int n;
map<string, sch> mp;
void inp()
{
    cin >> n;
    string id, name;
    double score;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> score >> name;
        for (int i = 0; i < name.size(); i++)
            name[i] |= 0x20;
        mp[name].name = name;
        if (id[0] == 'B')
            mp[name].score += score / 1.5;
        if (id[0] == 'A')
            mp[name].score += score;
        if (id[0] == 'T')
            mp[name].score += score * 1.5;
        mp[name].cnt++;
    }
}
bool cmp(sch a, sch b)
{
    if (a.final != b.final)
        return a.final > b.final;
    if (a.cnt != b.cnt)
        return a.cnt < b.cnt;
    return a.name < b.name;
}
void work()
{
    for (auto x : mp)
    {
        x.second.final = x.second.score;
        v.push_back(x.second);
    }
    sort(v.begin(), v.end(), cmp);
    v[0].rank = 1;
    for (int i = 1; i < v.size(); i++)
    {
        v[i].rank = i + 1;
        if (v[i].final == v[i - 1].final)
            v[i].rank = v[i - 1].rank;
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
        printf("%d %s %d %d\n", v[i].rank, v[i].name.c_str(), v[i].final, v[i].cnt);
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
