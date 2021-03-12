#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n, m;
vector<int> dis;
int total;
void inp()
{
    cin >> n;
    dis.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> dis[i], total += dis[i], dis[i] += dis[i - 1];
}
void work()
{
    cin >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        int ans = 0;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        ans = dis[b - 1] - dis[a - 1];
        ans = min(ans, total - ans);
        cout << ans << endl;
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
