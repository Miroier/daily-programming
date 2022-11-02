#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N];
int q[N]; //所有长度为i的上升子序列的结尾的最小值
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int len = 0;
    q[0] = -2e9;
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = len;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }
    cout << len;
}
