#include "algorithm"
#include "iostream"
#include "map"
#include "vector"
using namespace std;
bool cmp(pair<double, double> &a, pair<double, double> &b)
{
    return a.second * b.first > b.second * a.first;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n, d;
    double ans;
    vector<pair<double, double>> v;
    cin >> n >> d;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first;
    for (int i = 0; i < n; i++)
        cin >> v[i].second;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n && d; i++)
    {
        if (d >= v[i].first)
            ans += v[i].second, d -= v[i].first;
        else
            ans += v[i].second * d / v[i].first, d = 0;
    }
    printf("%.2lf", ans);
}
