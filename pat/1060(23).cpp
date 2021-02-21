#include "cmath"
#include "iostream"
using namespace std;
int n;
double a, b;
string x, y;
int stand(double &x)
{
    int cnt = 0;
    if (fabs(x) < 1e-6)
        return cnt;
    while (x >= 1)
    {
        x /= 10, cnt++;
    }
    while (x < 0.1)
    {
        x *= 10, cnt--;
    }
    return cnt;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    //位数过多时，double会无法区分，比如1和0.9999999999999，不能用数字逻辑做
    cin >> n >> a >> b;
    int num1 = stand(a);
    string x = to_string(a), r1 = "";
    for (int i = 0; i < 2 + n; i++)
        r1 += x[i];
    int num2 = stand(b);
    string y = to_string(b), r2 = "";
    for (int i = 0; i < 2 + n; i++)
        r2 += y[i];
    if (r1 == r2 && num1 == num2)
    {
        cout << "YES";
        printf(" %s*10^%d", r1.c_str(), num1);
    }
    else
    {
        cout << "NO";
        printf(" %s*10^%d", r1.c_str(), num1);
        printf(" %s*10^%d", r2.c_str(), num2);
    }
}
