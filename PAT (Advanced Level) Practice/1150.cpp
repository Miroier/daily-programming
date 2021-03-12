#include "iostream"
#include "vector"
using namespace std;
int n, m, k;
int g[205][205];
const int INF = 0x3fffffff;
void inp()
{
    cin >> n >> m;
    int x, y, dis;
    fill(g[0], g[0] + 205 * 205, INF);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> dis;
        g[x][y] = g[y][x] = dis;
    }
}
void work()
{
    cin >> k;
    int minind;
    int mindis = INF;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        vector<int> tmpPath(x + 1);
        vector<bool> ex(x + 1);
        int dis = 0;
        for (int j = 1; j <= x; j++)
        {
            cin >> tmpPath[j];
            ex[tmpPath[j]] = 1;
        }
        bool flag1 = 1, flag2 = 1; //flag1：是否是TS，flag2：是否simple
        for (int j = 2; j <= x; j++)
        {
            dis += g[tmpPath[j]][tmpPath[j - 1]];
            dis = min(dis, INF);
        }
        for (int j = 1; j <= n; j++)
            if (ex[j] == 0)
                flag1 = 0;
        if (dis == INF)
            flag1 = 0;
        if (tmpPath[1] != tmpPath[x])
            flag1 = 0;
        if (!flag1)
            printf("Path %d: %s (Not a TS cycle)\n", i, dis == INF ? "NA" : to_string(dis).c_str());
        else
        {
            if (x - 1 != n)
                flag2 = 0;
            if (!flag2)
                printf("Path %d: %d (TS cycle)\n", i, dis);
            else
                printf("Path %d: %d (TS simple cycle)\n", i, dis);
            if (mindis > dis)
                mindis = dis, minind = i;
        }
    }
    printf("Shortest Dist(%d) = %d\n", minind, mindis);
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
