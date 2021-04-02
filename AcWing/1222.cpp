/*
    相当于求总长度-最大回文子序列长度
    因为找出最大回文子序列后，只需要给剩下的每个字符配对即可

    DP
    状态表示：f[L,R]
        集合：所有s[L,R]之间的回文子序列的集合
        属性：长度最大值
    状态计算：
        四个子状态
            f[L + 1][R - 1] + 2
            f[L][R - 1]
            f[L + 1][R]
            f[L + 1][R - 1]
        第四个状态被第二、三状态覆盖，所以可以不计算
 */
#include "iostream"
using namespace std;
const int N = 1005;
string s;
int f[N][N];
int n;
int main()
{
    cin >> s;
    n = s.size();
    for (int len = 1; len <= n; len++) //这里不能遍历左右端点，因为可能子状态没计算过
        for (int L = 0; L + len - 1 < n; L++)
        {
            int R = L + len - 1;
            if (len == 1)
                f[L][R] = 1;
            else
            {
                if (s[L] == s[R])
                    f[L][R] = f[L + 1][R - 1] + 2;
                f[L][R] = max(f[L][R], f[L][R - 1]);
                f[L][R] = max(f[L][R], f[L + 1][R]);
            }
        }
    cout << n - f[0][n - 1];
}
