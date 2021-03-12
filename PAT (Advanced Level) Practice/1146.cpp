#include "iostream"
#include "set"
#include "vector"
using namespace std;
int n, m, k;
vector<int> v[1005];
vector<int> in(1005);
bool istopo(vector<int> &points)
{
    vector<int> tmp = in;
    for (auto point : points)
    {
        if (tmp[point])
            return false;
        for (int post : v[point])
            tmp[post]--;
    }
    return true;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        in[y]++;
    }
    cin >> k;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        vector<int> points(n);
        for (int j = 0; j < n; j++)
            cin >> points[j];
        if (!istopo(points))
            ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << (i < ans.size() - 1 ? " " : "\n");
}
