#include "iostream"
using namespace std;
string s;
int dp[1010][1010];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    getline(cin, s);
    int len = s.size();
    int ans = 1;
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if (i < len - 1 && s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            ans = 2;
        }
    }
    for (int L = 3; L <= len; L++)
    {
        for (int i = 0; i + L - 1 < len; i++)
        {
            int j = i + L - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    cout << ans;
}
