#include "iostream"
using namespace std;
int n;
int a[16];
void dfs(int x)
{
    if (x == n + 1)
    {
        for (int i = 1; i <= x; i++)
            if (a[i] == 1)
                cout << i << " ";
        puts("");
        return;
    }
    a[x] = 1;
    dfs(x + 1);
    a[x] = 0;
    a[x] = 2;
    dfs(x + 1);
    a[x] = 0;
}
int main()
{
    cin >> n;
    dfs(1);
}
