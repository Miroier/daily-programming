#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int a = 0, b = 0;
    for (int i = 0; i < n / 2; i++)
        a += v[i], b += v[n - 1 - i];
    if (n % 2)
    {
        b += v[n / 2];
        cout << "1 " << b - a;
    }
    else
        cout << "0 " << b - a;
}
