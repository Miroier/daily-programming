#include "algorithm"
#include "cmath"
#include "iostream"
#include "map"
#include "vector"
using namespace std;
int p, m, n;
struct stu
{
    string name;
    int Gp, Gmid = -1, Gfin = -1;
    int G;
    friend bool operator<(stu a, stu b)
    {
        if (a.G != b.G)
            return a.G > b.G;
        return a.name < b.name;
    }
};
map<string, stu> mp;
vector<stu> v;
void inp()
{
    cin >> p >> m >> n;
    string name;
    int score;
    for (int i = 0; i < p; i++)
    {
        cin >> name >> score;
        mp[name].name = name;
        mp[name].Gp = score;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> name >> score;
        mp[name].Gmid = score;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> name >> score;
        mp[name].Gfin = score;
    }
}
void work()
{
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        it->second.G = round(it->second.Gfin >= it->second.Gmid ? it->second.Gfin : 0.6 * max(0, it->second.Gfin) + 0.4 * it->second.Gmid);
    }
    for (auto x : mp)
    {
        if (x.second.Gp >= 200 && x.second.G >= 60)
            v.push_back(x.second);
    }
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x.name << " ";
        printf("%d %d %d %d\n", x.Gp, x.Gmid, x.Gfin, x.G);
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
