/* 密码脱落 */
#include <iostream>
using namespace std;
string s;
int cnt;
int f[1005][1005];
int main()
{
    cin >> s;
    int n = s.size();
    for (int len = 1; len <= n; len++)
        for (int L = 0; L + len - 1 < n; L++)
        {
            int R = L + len - 1;
            if (len == 1)
                f[L][R] = 1;
            else
            {
                if (s[L] == s[R])
                    f[L][R] = f[L + 1][R - 1] + 2;
                f[L][R] = max(f[L][R], f[L + 1][R]);
                f[L][R] = max(f[L][R], f[L][R - 1]);
            }
        }
    cout << n - f[0][n - 1];
    return 0;
}
