#include <iostream>
using namespace std;
const int N = 105;
int n;
int a[N][N];
int gauss()
{
    int r, c;
    for (r = c = 0; c < n; c++)
    {
        int t = r;
        // 找本列中系数不为0的行数
        for (int i = r; i < n; i++)
            if (a[i][c])
            {
                t = i;
                break;
            }
        if (!a[t][c])
            continue;
        // 交换两行
        for (int i = c; i <= n; i++)
            swap(a[t][i], a[r][i]);
        // 通过异或的方式消元
        for (int i = r + 1; i < n; i++)
            if (a[i][c])
                for (int j = c; j <= n; j++)
                    a[i][j] ^= a[r][j];
        r++;
    }
    if (r < n)
    {
        for (int i = r; i < n; i++)
            if (a[i][n])
                return 2;
        return 1;
    }
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n + 1; j++)
            a[i][n] ^= a[i][j] & a[j][n]; // * 和 & 都可以
    return 0;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            cin >> a[i][j];
    int res = gauss();
    if (res == 0)
        for (int i = 0; i < n; i++)
            cout << a[i][n] << endl;
    else if (res == 1)
        puts("Multiple sets of solutions");
    else
        puts("No solution");
}
