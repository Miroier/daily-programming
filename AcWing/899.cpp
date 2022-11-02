#include <iostream>
using namespace std;
const int N = 1005, M = 15;
int n, m;
string a[N];
int f[M][M];
int solve(const string &s1, const string &s2)
{
    fill(f[0], f[0] + M * M, 0);
    int len1 = s1.size() - 1, len2 = s2.size() - 1;
    for (int i = 1; i <= len2; i++)
        f[0][i] = i;
    for (int i = 1; i <= len1; i++)
        f[i][0] = i;
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
        {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if (s1[i] == s2[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    return f[len1][len2];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] = " " + a[i];
    for (int i = 1; i <= m; i++)
    {
        int t, cnt = 0;
        string b;
        cin >> b >> t;
        b = " " + b;
        for (int j = 1; j <= n; j++)
            if (solve(a[j], b) <= t)
                cnt++;
        cout << cnt << endl;
    }
}
