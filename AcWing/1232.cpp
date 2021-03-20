#include "cstring"
#include "iostream"
using namespace std;
/*
    这题的范围是A*B*C<=1e6
    不能开三维数组，因为三维数组的话每一维至少开1e6，会爆内存
    可以映射到一维数组
 */
typedef long long LL;
const int N = 2000005;
int A, B, C, m;
LL a[N], diff[N], bp[N]; //bp是差分数组备份
int d[8][4] = {
    {0, 0, 0, 1},
    {1, 0, 0, -1},
    {0, 1, 0, -1},
    {0, 0, 1, -1},
    {1, 1, 0, 1},
    {1, 0, 1, 1},
    {0, 1, 1, 1},
    {1, 1, 1, -1},
};
int op[N / 2][7];
int get(int i, int j, int k)
{
    //映射
    return (i * B + j) * C + k;
}
bool check(int mid)
{
    memcpy(diff, bp, sizeof bp);
    for (int i = 1; i <= mid; i++)
    {
        int x1 = op[i][0], x2 = op[i][1], y1 = op[i][2], y2 = op[i][3], z1 = op[i][4], z2 = op[i][5], c = op[i][6];
        diff[get(x1, y1, z1)] -= c;
        diff[get(x2 + 1, y1, z1)] += c;
        diff[get(x1, y2 + 1, z1)] += c;
        diff[get(x1, y1, z2 + 1)] += c;
        diff[get(x2 + 1, y2 + 1, z1)] -= c;
        diff[get(x2 + 1, y1, z2 + 1)] -= c;
        diff[get(x1, y2 + 1, z2 + 1)] -= c;
        diff[get(x2 + 1, y2 + 1, z2 + 1)] += c;
    }
    memset(a, 0, sizeof a);
    // 求差分数组的前缀和
    for (int i = 1; i <= A; i++)
        for (int j = 1; j <= B; j++)
            for (int k = 1; k <= C; k++)
            {
                a[get(i, j, k)] = diff[get(i, j, k)];
                for (int u = 1; u < 8; u++)
                {
                    int x = i - d[u][0];
                    int y = j - d[u][1];
                    int z = k - d[u][2];
                    int t = d[u][3];
                    a[get(i, j, k)] -= a[get(x, y, z)] * t;
                }
                if (a[get(i, j, k)] < 0)
                    return true;
            }
    return false;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> A >> B >> C >> m;
    for (int i = 1; i <= A; i++)
        for (int j = 1; j <= B; j++)
            for (int k = 1; k <= C; k++)
                scanf("%d", &a[get(i, j, k)]);
    //求差分数组
    for (int i = 1; i <= A; i++)
        for (int j = 1; j <= B; j++)
            for (int k = 1; k <= C; k++)
                for (int u = 0; u < 8; u++)
                {
                    int x = i - d[u][0];
                    int y = j - d[u][1];
                    int z = k - d[u][2];
                    int t = d[u][3];
                    bp[get(i, j, k)] += a[get(x, y, z)] * t;
                }
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 7; j++)
            scanf("%d", &op[i][j]);
    int left = 1, right = m;
    while (left < right)
    {
        int mid = left + right >> 1;
        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }
    cout << left;
}
