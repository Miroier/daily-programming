#include "iostream"
#include "map"
#include "vector"
using namespace std;
int n, k;
vector<pair<int, int>> v;
bool check(int x)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum += (v[i].first / x) * (v[i].second / x);
    return sum >= k;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    int left = 0, right = 100000;
    while (left < right)
    {
        int mid = (left + right + 1) >> 1;
        if (check(mid))
            left = mid;
        else
            right = mid - 1;
    }
    cout << left;
}
