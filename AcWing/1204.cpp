#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n;
vector<int> v;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    int x;
    while (cin >> x)
        v.push_back(x);
    int m, n;
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - v[i - 1] == 2)
            m = v[i] - 1;
        if (v[i] - v[i - 1] == 0)
            n = v[i];
    }
    cout << m << " " << n;
}
