#include "iostream"
using namespace std;
int k;
int a[10010];
int main()
{
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    int sum = 0;
    int low = 0, high = 0;
    int maxsum = -1, maxlow = 0, maxhigh = k - 1;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
        if (sum >= 0)
        {
            high = i;
            if (maxsum < sum)
                maxsum = sum, maxlow = low, maxhigh = high;
        }
        else
            sum = 0, low = high = i + 1;
    }
    if (maxsum >= 0)
        cout << maxsum << ' ' << a[maxlow] << ' ' << a[maxhigh];
    else
        cout << 0 << ' ' << a[0] << ' ' << a[k - 1];
}
