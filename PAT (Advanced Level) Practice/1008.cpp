#include "iostream"
using namespace std;
int a[100010];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i >= 1; i--)
        a[i] -= a[i - 1];
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + (a[i] > 0 ? 6 * a[i] : 4 * (-a[i])) + 5;
    cout << sum;
}
