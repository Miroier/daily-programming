#include "cstring"
#include "iostream"
#include "map"
#include "vector"
using namespace std;
char g[5][5], backup[5][5];
void turn(int x, int y)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (i == x || j == y)
            {
                g[i][j] = (g[i][j] == '-' ? '+' : '-');
            }
        }
}
bool check()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (g[i][j] == '+')
                return false;
    return true;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    for (int i = 0; i < 4; i++)
        cin >> g[i];
    memcpy(backup, g, sizeof g);
    vector<pair<int, int>> ans;
    for (int op = 0; op < 1 << 16; op++)
    {
        ans.clear();
        int cnt = __builtin_popcount(op);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (op & 1 << (i * 4 + j))
                {
                    turn(i, j);
                    ans.push_back(make_pair(i + 1, j + 1));
                }
        if (check())
        {
            cout << cnt << endl;
            for (int i = 0; i < cnt; i++)
                cout << ans[i].first << " " << ans[i].second << endl;
            break;
        }
        memcpy(g, backup, sizeof g);
    }
}
