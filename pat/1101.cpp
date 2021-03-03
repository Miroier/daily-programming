#include "iostream"
#include "vector"
using namespace std;
vector<int> v, res;
int mxa[100010], mna[100010];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mxa[i] = mx;
        if (v[i] > mx)
            mx = v[i];
    }
    int mn = 0x3fffffff;
    for (int i = n - 1; i >= 0; i--)
    {
        mna[i] = mn;
        if (v[i] < mn)
            mn = v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= mxa[i] && v[i] <= mna[i])
            res.push_back(v[i]);
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << res[i];
    }
    cout << endl; //必须有这句，否则格式错误
}
