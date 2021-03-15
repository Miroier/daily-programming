#include "iostream"
using namespace std;
int a[10];
int n;
bool vis[10];
int cnt = 0;
void dfs(int x)
{
    if (x == 10)
    {
        for (int i = 1; i <= 6; i++)
            // for (int j = i + 1; j <= 8; j++)
            for (int j = (9 - i + 1) / 2 + i; j <= 8; j++)
            {
                int sum = 0, up = 0, low = 0;
                for (int k = 1; k <= i; k++)
                    sum = 10 * sum + a[k];
                for (int k = i + 1; k <= j; k++)
                    up = 10 * up + a[k];
                for (int k = j + 1; k <= 9; k++)
                    low = 10 * low + a[k];
                if (up % low != 0)
                    continue;
                if (sum + up / low == n)
                {
                    cnt++;
                    // printf("%d %d %d\n", sum, up, low);
                }
            }
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            a[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    cout << cnt;
}
