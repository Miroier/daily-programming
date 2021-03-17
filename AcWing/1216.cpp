#include "iostream"
using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    int sum = n;
    while (n >= 3)
    {
        sum += n / 3;
        n = n % 3 + n / 3;
    }
    cout << sum;
}
