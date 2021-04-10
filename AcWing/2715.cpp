#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1000005;
int n, m;
char s[N];
int x[N], y[N], c[N], sa[N], rk[N];
void SA()
{
    for (int i = 1; i <= n; i++)
    {
        x[i] = s[i];
        ++c[x[i]];
    }
    for (int i = 2; i <= m; i++)
        c[i] += c[i - 1];
    for (int i = n; i >= 1; i--)
        sa[c[x[i]]--] = i;
    for (int k = 1; k <= n; k = k << 1)
    {
        int num = 0;
        for (int i = n - k + 1; i <= n; ++i)
            y[++num] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > k)
                y[++num] = sa[i] - k;
        for (int i = 1; i <= m; i++)
            c[i] = 0;
        for (int i = 1; i <= n; i++)
            c[x[i]]++;
        for (int i = 2; i <= m; i++)
            c[i] += c[i - 1];
        for (int i = n; i >= 1; i--)
        {
            sa[c[x[y[i]]]--] = y[i];
            y[i] = 0;
        }
        swap(x, y);
        num = 1;
        x[sa[1]] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k])
                x[sa[i]] = num;
            else
                x[sa[i]] = ++num;
        }
        if (num == n)
            break;
        m = num;
    }
}
int height[N];
void LCP()
{
    int k = 0; //用k代表h[i]
    for (int i = 1; i <= n; i++)
        rk[sa[i]] = i;           //初始化rk[i]
    for (int i = 1; i <= n; i++) //这里其实是枚举rk[i]
    {
        if (rk[i] == 1)
            continue; //height[1]=0
        if (k)
            k--;               //h[i]>=h[i-1]-1,更新k然后一位位枚举
        int j = sa[rk[i] - 1]; //前一位字符串
        while (i + k <= n && j + k <= n && s[i + k] == s[j + k])
            k++;           //一位位枚举
        height[rk[i]] = k; //h[i]=height[rk[i]]
    }
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    m = 122; //ascii('z')=122
    SA();
    for (int i = 1; i <= n; i++)
        printf("%d ", sa[i]);
    puts("");
    LCP();
    for (int i = 1; i <= n; i++)
        printf("%d ", height[i]);
}
