/*
    dp[i,j]表示从前i个物品中选，且总和除以k的余数是j的所有方案的最大值
    dp[i,j]=max(dp[i-1,j],dp[i-1,((j-wi)%k+k)%k+wi])
 */
#include "cstring"
#include "iostream"
using namespace std;
const int N = 105;
int dp[N][N];
int w[N];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    memset(dp, -0x3f, sizeof dp); //没有物品被选中时，dp[0][1..n]无意义
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][((j - w[i]) % k + k) % k] + w[i]);
    cout << dp[n][0] << endl;
}
