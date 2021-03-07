#include "iostream"
#include <unordered_map>
#include <vector>
using namespace std;
vector<vector<int>> v(10000);
int vis[10000], minCnt, minTransfer, start, end1;
unordered_map<int, int> line;
vector<int> path, tmpPath;
int n, m, k, pre, tmp;
void inp()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m >> pre;
        for (int j = 1; j < m; j++)
        {
            cin >> tmp;
            v[pre].push_back(tmp);
            v[tmp].push_back(pre);
            line[pre * 10000 + tmp] = line[tmp * 10000 + pre] = i;
            pre = tmp;
        }
    }
}
int transferCnt(vector<int> a)
{
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (line[a[i - 1] * 10000 + a[i]] != preLine)
            cnt++;
        preLine = line[a[i - 1] * 10000 + a[i]];
    }
    return cnt;
}
void dfs(int x, int cnt)
{
    if (x == end1)
    {
        if (cnt < minCnt || (cnt == minCnt && transferCnt(tmpPath) < minTransfer))
        {
            minCnt = cnt;
            minTransfer = transferCnt(tmpPath);
            path = tmpPath;
        }
        return;
    }
    for (int i = 0; i < v[x].size(); i++)
    {
        if (!vis[v[x][i]])
        {
            vis[v[x][i]] = 1;
            tmpPath.push_back(v[x][i]);
            dfs(v[x][i], cnt + 1);
            vis[v[x][i]] = 0;
            tmpPath.pop_back();
        }
    }
}
void work()
{
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> start >> end1;
        minCnt = 99999, minTransfer = 99999;
        tmpPath.clear();
        tmpPath.push_back(start);
        vis[start] = 1;
        dfs(start, 0);
        vis[start] = 0;
        cout << minCnt << endl;
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); j++)
        {
            if (line[path[j - 1] * 10000 + path[j]] != preLine)
            {
                if (preLine != 0)
                    printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j - 1]);
                preLine = line[path[j - 1] * 10000 + path[j]];
                preTransfer = path[j - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
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
