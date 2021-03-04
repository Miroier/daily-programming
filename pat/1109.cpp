#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
struct peo
{
    string name;
    int height;
};
int n, k, c;
vector<peo> v, tmp;
bool cmp(peo &a, peo &b)
{
    if (a.height != b.height)
        return a.height > b.height;
    else
        return a.name < b.name;
}
void inp()
{
    cin >> n >> k;
    c = n / k;
    string name;
    int height;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> height;
        v.push_back({name, height});
    }
    sort(v.begin(), v.end(), cmp);
}
int cnt1;
void work(int st, int ed)
{
    if (st + 3 * c <= v.size()) // -> st st+c st+2c st+3c v.size() ->
        work(st + c, st + 2 * c);
    else if (st + 2 * c <= v.size()) // -> st st+c st+2c v.size() st+2c ->
        work(st + c, v.size());
    // else -> st v.size() st+2c ->
    tmp.clear();
    for (int i = st; i < ed; i++)
        tmp.push_back(v[cnt1++]);
    int m = ed - st;
    int cen = m / 2;
    peo a[m];
    int cnt = 0, layer = 1;
    a[cen] = tmp[cnt++];
    while (cnt < m)
    {
        a[cen - layer] = tmp[cnt++];
        if (cnt < m)
            a[cen + layer] = tmp[cnt++];
        layer++;
    }
    for (int i = 0; i < m; i++)
    {
        if (i != 0)
            cout << " ";
        cout << a[i].name;
    }
    puts("");
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    inp();
    work(0, c);
}
