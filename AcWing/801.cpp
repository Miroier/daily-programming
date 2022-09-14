#include <iostream>
#define lowbit(x) ((x) & (-x))
using namespace std;
int n;
int main()
{
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int res = 0;
        while (x)
            x -= lowbit(x), res++;
        cout << res << " ";
    }
}
