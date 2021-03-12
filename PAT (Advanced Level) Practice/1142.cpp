#include "iostream"
#include "vector"
using namespace std;
int n, m, k;
bool g[210][210];
bool check(vector<int> v)
{
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = i + 1; j < v.size(); j++)
            if (!g[v[i]][v[j]])
                return 0;
    return 1;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
    }
    cin >> k;
    while (k--)
    {
        int x, y;
        cin >> x;
        vector<int> v;
        while (x--)
        {
            cin >> y;
            v.push_back(y);
        }
        bool flag1 = 1, flag2 = 1; //flag1:是否是clique，1：是；flag2:是否maximal，1：是
        if (v.size() != 1)
        {
            flag1 = check(v);
        }
        if (!flag1)
            cout << "Not a Clique" << endl;
        else
        {
            for (int i = 1; i <= n; i++)
            {
                bool find = 0;
                for (int j = 0; j < v.size(); j++)
                    if (v[j] == i)
                        find = 1;
                if (find)
                    continue;
                v.push_back(i);
                if (check(v))
                {
                    cout << "Not Maximal" << endl;
                    flag2 = 0;
                    break;
                }
                v.pop_back();
            }
            if (flag2)
                cout << "Yes" << endl;
        }
    }
}
