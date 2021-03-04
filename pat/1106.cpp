#include "cmath"
#include "iostream"
#include "vector"
using namespace std;
int n;
double p, r;
vector<int> v[100010];
void inp()
{
    cin >> n >> p >> r;
    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        int x;
        while (k--)
        {
            cin >> x;
            v[i].push_back(x);
        }
    }
}
int mindepth = 100010;
int cnt;
void dfs(int x, int depth)
{
    if (v[x].size() == 0)
    {
        if (mindepth > depth)
        {
            mindepth = depth;
            cnt = 1;
        }
        else if (mindepth == depth)
        {
            cnt++;
        }
        return;
    }
    for (int i = 0; i < v[x].size(); i++)
        dfs(v[x][i], depth + 1);
}
void work()
{
    dfs(0, 0);
    printf("%.4lf %d", p * pow(1 + r / 100, mindepth), cnt);
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
