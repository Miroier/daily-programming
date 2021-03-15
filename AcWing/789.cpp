#include "iostream"
using namespace std;
int n, q;
int a[100005];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x;
    while (q--)
    {
        cin >> x;
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (a[mid] >= x)
                right = mid;
            else
                left = mid + 1;
        }
        if (a[left] == x)
            cout << left << " ";
        else
            cout << -1 << " ";
        left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            if (a[mid] <= x)
                left = mid;
            else
                right = mid - 1;
        }
        if (a[left] == x)
            cout << left << endl;
        else
            cout << -1 << endl;
    }
}
