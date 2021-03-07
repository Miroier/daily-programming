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
    vector<int> v;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int res = v[0];
    for (int i = 1; i < n; i++)
        res = (res + v[i]) / 2;
    cout << res;
}
