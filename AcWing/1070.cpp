/*
    状态表示
        集合：f[i,j]表示所有将[i,j]变成合法括号序列的方案的集合
        属性：最小值
    状态计算，分为两部分：
        (A)或[A]
            f[i+1,j-1]
            f[i,j-1]+1
            f[i+1,j]+1
            f[i+1,j-1]+2 （已经被上面那种情况包含）
        AB 按最左边GBE的范围划分
            f[i,i]+f[i+1,j]
            f[i,i+1]
            ...
            f[i,j-1]

 */
#include "iostream"
using namespace std;
const int N = 105, INF = 1e8;
string s;
int n;
int f[N][N];
bool match(char c1, char c2)
{
    if (c1 == '(' && c2 == ')')
        return 1;
    if (c1 == '[' && c2 == ']')
        return 1;
    return 0;
}
int main()
{
    cin >> s;
    n = s.size();
    for (int len = 1; len <= n; len++)
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            f[i][j] = INF;
            if (match(s[i], s[j]))
                f[i][j] = f[i + 1][j - 1];
            f[i][j] = min(f[i][j], f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i + 1][j] + 1);
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
        }
    cout << f[0][n - 1];
}
