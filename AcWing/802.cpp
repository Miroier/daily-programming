#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
const int N = 3e5 + 5;
vector<PII> add, req;
vector<int> alls;
int a[N], s[N];

int n, m;

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l + 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        req.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto x : add)
        a[find(x.first)] += x.second;

    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];

    for (auto x : req)
        cout << s[find(x.second)] - s[find(x.first) - 1] << endl;
}
