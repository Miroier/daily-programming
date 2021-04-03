#include "iostream"
using namespace std;
const int INF = 1e8;
int t;
int a[3][3];
bool check(int x)
{
    for (int i = 0; i < 3; i++)
    {
        int s = 0;
        for (int j = 0; j < 3; j++)
            if (a[i][j] == x)
                s++;
        if (s == 3)
            return true;
        s = 0;
        for (int j = 0; j < 3; j++)
            if (a[j][i] == x)
                s++;
        if (s == 3)
            return true;
    }
    if (a[0][0] == x && a[1][1] == x && a[2][2] == x)
        return true;
    if (a[2][0] == x && a[1][1] == x && a[0][2] == x)
        return true;
    return false;
}
int eval()
{
    int s = 0; //空格数量
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (a[i][j] == 0)
                s++;
    if (check(1))
        return s + 1;
    if (check(2))
        return -(s + 1);
    if (s == 0)
        return 0;
    return INF;
}
int dfs(int u)
{
    int t = eval();
    if (t != INF)
        return t;
    if (!u) //0代表Alice 1代表Bob
    {
        int res = -INF;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (!a[i][j])
                {
                    a[i][j] = 1;
                    res = max(res, dfs(1)); //Alice选最大值
                    a[i][j] = 0;
                }
        return res;
    }
    else
    {
        int res = INF;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (!a[i][j])
                {
                    a[i][j] = 2;
                    res = min(res, dfs(0)); //Bob选最小值
                    a[i][j] = 0;
                }
        return res;
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> a[i][j];
        cout << dfs(0) << endl;
    }
}
