#include "iostream"
#include "queue"
#include "stack"
using namespace std;
int m, n, k;
stack<int> s;
queue<int> q;
void sol()
{
    int x;
    for (int i = 1; i <= n; i++)
        cin >> x, q.push(x);
    for (int i = 1; i <= n; i++)
    {
        s.push(i);
        if (s.size() > m)
        {
            cout << "NO" << endl;
            return;
        }
        while (!s.empty() && s.top() == q.front())
        {
            s.pop();
            q.pop();
        }
    }
    if (q.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        sol();
        while (!q.empty())
            q.pop();
        while (!s.empty())
            s.pop();
    }
}
