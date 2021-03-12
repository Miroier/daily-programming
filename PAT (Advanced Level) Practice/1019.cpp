#include "iostream"
using namespace std;
int n, b;
int a[1000];
int cnt;
void dec2any()
{
    while (n)
    {
        a[cnt++] = n % b;
        n /= b;
    }
}
bool check()
{
    for (int i = 0, j = cnt - 1; i <= j; i++, j--)
        if (a[i] != a[j])
            return false;
    return true;
}
int main()
{
    cin >> n >> b;
    dec2any();
    if (check())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << a[cnt - 1];
    for (int i = cnt - 2; i >= 0; i--)
        cout << " " << a[i];
}
