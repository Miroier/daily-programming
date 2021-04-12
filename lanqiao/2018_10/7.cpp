#include "cstring"
#include <iostream>
using namespace std;
const int N = 2e6;
int g[N];
int diff[N], bp[N];
int sum[N];
int a, b, c, m;
struct op
{
    int lat, rat, lbt, rbt, lct, rct, h;
    void input()
    {
        cin >> lat >> rat >> lbt >> rbt >> lct >> rct >> h;
    }
} op[N];
int conv(int i, int j, int k)
{
    return ((i - 0) * b + (j - 0)) * c + (k - 0) + 1;
}
bool check(int t)
{
    memcpy(diff, bp, sizeof bp);
    memset(sum, 0, sizeof sum);
    for (int i = 1; i <= t; i++)
    {
        int x1, x2, y1, y2, z1, z2, h;
        x1 = op[i].lat;
        x2 = op[i].rat;
        y1 = op[i].lbt;
        y2 = op[i].rbt;
        z1 = op[i].lct;
        z2 = op[i].rct;
        h = op[i].h;
        diff[conv(x1, y1, z1)] -= h;
        diff[conv(x2 + 1, y1, z1)] += h;
        diff[conv(x1, y2 + 1, z1)] += h;
        diff[conv(x1, y1, z2 + 1)] += h;
        diff[conv(x2 + 1, y2 + 1, z1)] -= h;
        diff[conv(x2 + 1, y1, z2 + 1)] -= h;
        diff[conv(x1, y2 + 1, z2 + 1)] -= h;
        diff[conv(x2 + 1, y2 + 1, z2 + 1)] += h;
    }
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= c; k++)
            {
                sum[conv(i, j, k)] = diff[conv(i, j, k)] + sum[conv(i - 1, j, k)] + sum[conv(i, j - 1, k)] + sum[conv(i, j, k - 1)] - sum[conv(i - 1, j - 1, k)] - sum[conv(i - 1, j, k - 1)] - sum[conv(i, j - 1, k - 1)] + sum[conv(i - 1, j - 1, k - 1)];
                if (sum[conv(i, j, k)] < 0)
                    return true;
            }
    return false;
}
int main()
{
    cin >> a >> b >> c >> m;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= c; k++)
                cin >> g[conv(i, j, k)];
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= c; k++)
            {
                diff[conv(i, j, k)] = g[conv(i, j, k)] - g[conv(i - 1, j, k)] - g[conv(i, j - 1, k)] - g[conv(i, j, k - 1)] + g[conv(i - 1, j - 1, k)] + g[conv(i - 1, j, k - 1)] + g[conv(i, j - 1, k - 1)] - g[conv(i - 1, j - 1, k - 1)];
            }
    for (int i = 1; i <= m; i++)
        op[i].input();
    memcpy(bp, diff, sizeof diff);
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
    return 0;
}
