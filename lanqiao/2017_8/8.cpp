/* 包子凑数 */
#include "queue"
#include <iostream>
using namespace std;
const int N = 105;
int a[N];
int n;
priority_queue<int> pq;
bool vis[10000];
bool st[10000];
int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pq.push(a[i]);
        st[a[i]] = 1;
    }
    int d = a[0];
    for (int i = 1; i < n; i++)
        d = gcd(d, a[i]);
    if (d != 1)
    {
        cout << "INF";
    }
    else
    {
        int cnt = 0;
        while (pq.size())
        {
            int t = pq.top();
            pq.pop();
            vis[t] = true;
            for (int i = 0; i < n; i++)
            {
                if (t + a[i] > 10000)
                    break;
                if (!st[t + a[i]])
                    pq.push(t + a[i]);
                st[t + a[i]] = true;
            }
        }
        for (int i = 1; i < 10000; i++)
            if (!vis[i])
                cnt++;
        cout << cnt;
    }
    return 0;
}
