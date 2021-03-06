#include "iostream"
#include "set"
using namespace std;
int n, m, k;
bool g[210][210];
void inp()
{
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
    }
}
void work()
{
    int a[2010]; //这里的n没说上限，反正210不行
    cin >> k;
    int num;
    for (int i = 0; i < k; i++)
    {
        cin >> num;
        for (int j = 0; j < num; j++)
            cin >> a[j];
        if (num != n + 1)
            cout << "NO\n";
        else
        {
            set<int> st;
            bool flag = 0;
            for (int j = 0; j < num - 1; j++)
                if (!g[a[j]][a[j + 1]])
                    flag = 1;
            for (int j = 0; j < num; j++)
                st.insert(a[j]);
            if (st.size() != n)
                flag = 1;
            if (a[0] != a[num - 1])
                flag = 1;
            if (flag)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    inp();
    work();
}
