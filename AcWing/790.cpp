#include <iostream>
using namespace std;

const double eps = 1e-8;
double n;

bool check(double x)
{
    return x * x * x < n;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    double l = -100, r = 100;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.6lf", l);
}
