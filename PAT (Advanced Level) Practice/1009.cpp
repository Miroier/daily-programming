#include "cstdio"
#include "iostream"
using namespace std;
double a[1010], b[1010];
double c[2010];
int mxa, mxb;
void inp()
{
    int k, x;
    double y;
    cin >> k;
    while (k--)
    {
        cin >> x >> y;
        a[x] = y;
        if (mxa < x)
            mxa = x;
    }
    cin >> k;
    while (k--)
    {
        cin >> x >> y;
        b[x] = y;
        if (mxb < x)
            mxb = x;
    }
}
void work()
{
    for (int i = 0; i <= mxa; i++)
        for (int j = 0; j <= mxb; j++)
        {
            if (a[i] && b[j])
                c[i + j] += a[i] * b[j];
        }
    int cnt = 0;
    for (int i = 0; i <= mxa + mxb; i++)
        if (c[i])
            cnt++;
    cout << cnt;
    for (int i = mxa + mxb; i >= 0; i--)
        if (c[i])
            printf(" %d %.1lf", i, c[i]);
}
int main()
{
    inp();
    work();
}
