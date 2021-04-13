/* 付账问题 */
#include "algorithm"
#include "cmath"
#include <iostream>
using namespace std;
const int N = 5e5 + 5;
double a[N];
int n;
double sum;
double b[N];
int main()
{
    cin >> n >> sum;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    double avg = sum / n;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > sum / (n - i + 1))
        {
            b[i] = sum / (n - i + 1);
        }
        else
        {
            b[i] = a[i];
        }
        sum -= b[i];
    }
    // for(int i=1;i<=n;i++)
    //   cout<<b[i]<<" ";
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (b[i] - avg) * (b[i] - avg);
    }
    printf("%.4lf", sqrt(ans / n));
    return 0;
}
