#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
struct item
{
    int ind;
    int cnt;
};
int n, k;
vector<item> v;
bool cmp(item &a, item &b)
{
    if (a.cnt != b.cnt)
        return a.cnt > b.cnt;
    return a.ind < b.ind;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;
    int x;
    cin >> x;
    v.push_back({x, 1});
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        printf("%d:", x);
        sort(v.begin(), v.end(), cmp);
        for (int j = 0; j < min(k, (int)v.size()); j++)
            printf(" %d", v[j].ind);
        puts("");
        int j = 0;
        while (j < v.size() && v[j].ind != x)
            j++;
        if (j == v.size())
            v.push_back({x, 1});
        else
            v[j].cnt++;
    }
}
