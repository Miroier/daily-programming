#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
typedef long long LL;
LL n, p;
vector<LL> v;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> p;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int mxlen = 0;
    for (int i = 0; i < n; i++)
    {
        int low = i, high = n - 1;
        while (low < high)
        {
            int mid = (low + high + 1) >> 1;
            if (v[mid] <= v[i] * p)
                low = mid;
            else
                high = mid - 1;
        }
        if (mxlen < low - i + 1)
            mxlen = low - i + 1;
    }
    cout << mxlen;
}
