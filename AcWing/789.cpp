#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int n, q;

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (q--)
    {
        int x;
        cin >> x;
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = left + right >> 1;
            if (a[mid] < x)
                left = mid + 1;
            else
                right = mid;
        }
        if (a[left] == x)
            cout << left << " ";
        else
            cout << "-1 ";
        left = 0, right = n - 1;
        while (left < right)
        {
            int mid = left + right + 1 >> 1;
            if (a[mid] > x)
                right = mid - 1;
            else
                left = mid;
        }
        if (a[left] == x)
            cout << left << endl;
        else
            cout << "-1" << endl;
    }
}
