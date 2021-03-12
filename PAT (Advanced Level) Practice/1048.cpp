#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n, m;
vector<int> v;
int find(int i)
{
    int low = i + 1, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (v[mid] + v[i] >= m)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++)
    {
        int j = find(i);
        if (v[i] + v[j] == m)
        {
            cout << v[i] << " " << v[j];
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}
