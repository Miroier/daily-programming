#include "iostream"
using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int p, q;
    cin >> p >> q;
    cout << (p - 1) * (q - 1) - 1;
}
