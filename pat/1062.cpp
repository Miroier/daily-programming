#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n, l, h;
struct peo
{
    int id, vir, tal;
    int sum;
};

/*
    分为4组单独排序
    virtue talent都>=h，是sages，按总分排序
    virtue >=h talent<h 是noblemen，按总分排序
    virtue talent 都<h，virtue>=talent 是fool men
    剩下的都是small men
 */
vector<peo> sages;
vector<peo> noblemen;
vector<peo> fool;
vector<peo> small;
void inp()
{
    cin >> n >> l >> h;
    int id, vir, tal;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> vir >> tal;
        if (vir < l || tal < l)
            continue;
        if (vir >= h && tal >= h)
            sages.push_back({id, vir, tal, vir + tal});
        else if (vir >= h && tal < h)
            noblemen.push_back({id, vir, tal, vir + tal});
        else if (vir < h && tal < h && vir >= tal)
            fool.push_back({id, vir, tal, vir + tal});
        else
            small.push_back({id, vir, tal, vir + tal});
    }
}
bool cmp(peo &a, peo &b)
{
    if (a.sum != b.sum)
        return a.sum > b.sum;
    else if (a.vir != b.vir)
        return a.vir > b.vir;
    else
        return a.id < b.id;
}
void work()
{
    sort(sages.begin(), sages.end(), cmp);
    sort(noblemen.begin(), noblemen.end(), cmp);
    sort(fool.begin(), fool.end(), cmp);
    sort(small.begin(), small.end(), cmp);
    cout << sages.size() + noblemen.size() + fool.size() + small.size() << endl;
    for (int i = 0; i < sages.size(); i++)
        printf("%d %d %d\n", sages[i].id, sages[i].vir, sages[i].tal);
    for (int i = 0; i < noblemen.size(); i++)
        printf("%d %d %d\n", noblemen[i].id, noblemen[i].vir, noblemen[i].tal);
    for (int i = 0; i < fool.size(); i++)
        printf("%d %d %d\n", fool[i].id, fool[i].vir, fool[i].tal);
    for (int i = 0; i < small.size(); i++)
        printf("%d %d %d\n", small[i].id, small[i].vir, small[i].tal);
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
