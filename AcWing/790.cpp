#include "cmath"
#include "iostream"
using namespace std;
const double eps = 1e-8;
double n;
bool check(double x)
{
    return x * x * x > n;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    double left = -10000, right = 10000;
    while (right - left > eps)
    {
        double mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid;
    }
    printf("%.6lf", left);
}
