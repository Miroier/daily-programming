#include "cmath"
#include "iostream"
#include "vector"
using namespace std;
int n, p, k;
vector<int> v, ans, tmpAns;
int maxFacSum = -1;
void dfs(int ind, int tmpSum, int tmpK, int facSum)
{
    if (tmpK == k)
    {
        if (tmpSum == n && facSum > maxFacSum)
        {
            maxFacSum = facSum;
            ans = tmpAns;
        }
        return;
    }
    for (int i = ind; i >= 1; i--)
    {
        if (tmpSum + v[i] <= n)
        {
            tmpAns[tmpK] = i;
            dfs(i, tmpSum + v[i], tmpK + 1, facSum + i);
        }
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k >> p;
    tmpAns.resize(k);
    for (int i = 0; pow(i, p) <= n; i++)
        v.push_back(pow(i, p));
    dfs(v.size() - 1, 0, 0, 0);
    if (maxFacSum == -1)
        cout << "Impossible";
    else
    {
        cout << n << " = ";
        for (int i = 0; i < ans.size(); i++)
        {
            if (i != 0)
                cout << " + ";
            cout << ans[i] << "^" << p;
        }
    }
}
