#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
using namespace std;
const int K = 1e3 + 5;
vector<int> v[K];
int n, k;
int f[4][K];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[x % k].push_back(x);
    }
    memset(f, -0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 0; i < k; i++)
    {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
        for (int u = 0; u < min(3, (int)v[i].size()); u++)
        {
            int x = v[i][u]; //前三大
            for (int j = 3; j >= 1; j--)
                for (int kk = 0; kk < k; kk++)
                    f[j][kk] = max(f[j][kk], f[j - 1][(kk - x % k + k) % k] + x);
        }
    }
    cout << f[3][0];
    return 0;
}
