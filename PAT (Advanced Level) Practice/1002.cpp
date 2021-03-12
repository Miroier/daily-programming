#include "iostream"
using namespace std;
double res[1005];
int k;
int a;
double b;
int mxa;
int cnt;
int main()
{
    cin >> k;
    while (k--)
    {
        cin >> a >> b;
        res[a] += b;
        if (mxa < a)
            mxa = a;
    }
    cin >> k;
    while (k--)
    {
        cin >> a >> b;
        res[a] += b;
        if (mxa < a)
            mxa = a;
    }
    for (int i = mxa; i >= 0; i--)
        if (res[i])
            cnt++;
    cout << cnt;
    for (int i = mxa; i >= 0; i--)
        if (res[i])
            printf(" %d %.1lf", i, res[i]);
}
