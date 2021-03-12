#include "cmath"
#include "iostream"
#include "vector"
using namespace std;
int n;
int root;
double p, r;
vector<int> v[100010];
int maxdep;
int cnt = 0;
void dfs(int x, int dep)
{
    if (maxdep < dep)
    {
        maxdep = dep;
        cnt = 1;
    }
    else if (maxdep == dep)
    {
        cnt++;
    }
    for (int i = 0; i < v[x].size(); i++)
        dfs(v[x][i], dep + 1);
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> p >> r;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == -1)
            root = i;
        else
            v[x].push_back(i);
    }
    dfs(root, 0);
    printf("%.2lf %d", p * pow(1 + r / 100, maxdep), cnt);
}
