#include "iostream"
#include "unordered_map"
#include <algorithm>
#include <vector>
using namespace std;
unordered_map<int, bool> arr;
struct node
{
    int a, b;
    friend bool operator<(node a, node b)
    {
        return a.a != b.a ? a.a < b.a : a.b < b.b;
    }
};
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n, m, k;
    cin >> n >> m;
    vector<int> v[10000];
    while (m--)
    {
        string x, y;
        cin >> x >> y;
        if (x.length() == y.length()) //性别相同
        {
            v[abs(stoi(x))].push_back(abs(stoi(y)));
            v[abs(stoi(y))].push_back(abs(stoi(x)));
        }
        // friend
        arr[abs(stoi(x)) * 10000 + abs(stoi(y))] = arr[abs(stoi(y)) * 10000 + abs(stoi(x))] = 1;
    }
    cin >> k;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        x = abs(x);
        y = abs(y);
        vector<node> ans;
        for (int i = 0; i < v[x].size(); i++)
            for (int j = 0; j < v[y].size(); j++)
                if (v[x][i] != y && v[y][j] != x && arr[v[x][i] * 10000 + v[y][j]])
                    ans.push_back({v[x][i], v[y][j]});
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            printf("%04d %04d\n", ans[i].a, ans[i].b);
    }
}
