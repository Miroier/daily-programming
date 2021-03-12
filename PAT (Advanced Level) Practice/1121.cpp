#include "algorithm"
#include "iostream"
#include "set"
#include "vector"
using namespace std;
int other[100000];
int n, m;
void inp()
{
    fill(other, other + 100000, -1);
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        other[x] = y;
        other[y] = x;
    }
}
vector<int> ans;
set<int> input;
void work()
{
    cin >> m;
    int x;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        input.insert(x);
    }
    for (auto x : input)
        if (other[x] == -1 || (input.find(other[x]) == input.end()))
            ans.push_back(x);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        printf("%05d%s", ans[i], (i < ans.size() - 1 ? " " : "\n"));
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
