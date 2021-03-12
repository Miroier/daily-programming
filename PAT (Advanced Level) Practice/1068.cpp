#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n, m;
int w[10010];
int dp[10010];
bool choice[10010][110];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    sort(w + 1, w + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= w[i]; j--)
            if (dp[j] <= dp[j - w[i]] + w[i])
            {
                choice[i][j] = true;
                dp[j] = dp[j - w[i]] + w[i];
            }
    if (dp[m] != m)
        cout << "No Solution";
    else
    {
        vector<int> arr;
        int v = m, index = n;
        while (v > 0)
        {
            if (choice[index][v])
            {
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (i != 0)
                cout << " ";
            cout << arr[i];
        }
    }
}
