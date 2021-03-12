#include "iostream"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int k, n, y;
    int b1[2010], b2[2010], b3[2010]; //y x+y x-y+1000
    cin >> k;
    while (k--)
    {
        bool flag = 0;
        fill(b1, b1 + 2010, 0);
        fill(b2, b2 + 2010, 0);
        fill(b3, b3 + 2010, 0);
        cin >> n;
        for (int x = 1; x <= n; x++)
        {
            cin >> y;
            b1[y]++;
            b2[x + y]++;
            b3[x - y + 1000]++;
            if (b1[y] > 1 || b2[x + y] > 1 || b3[x - y + 1000] > 1)
                flag = 1;
        }
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
