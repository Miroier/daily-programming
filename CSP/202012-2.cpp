#include "algorithm"
#include "cstdio"
#include "iostream"
#include "vector"
using namespace std;
int m;

struct stu
{
    int y;
    bool result;
    void inp()
    {
        cin >> y >> result;
    }
};
stu s[100005];

bool cmp(stu a, stu b)
{
    if (a.y != b.y)
        return a.y < b.y;
    else
        return a.result < b.result;
}
int ind;
int res;
bool index[100005];

struct sum
{
    int y;
    int sum0;
    int sum1;
};
vector<sum> v;

int main()
{
    s[0].y = -1;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        s[i].inp();
    }
    sort(s + 1, s + 1 + m, cmp);
    int count = -1;
    for (int i = 1; i <= m; i++)
    {
        if (s[i].y != s[i - 1].y)
            v.push_back(sum{s[i].y, 0}), count++;
        v[count].sum0 += 1 - s[i].result;
        v[count].sum1 += s[i].result;
    }
    for (int i = 1; i < v.size(); i++)
    {
        v[i].sum0 += v[i - 1].sum0;
        v[i].sum1 += v[i - 1].sum1;
    }
    for (int i = 0; i < v.size(); i++)
    {
        int cnt = 0;
        if (i > 0)
            cnt += v[i - 1].sum0;
        cnt += v[v.size() - 1].sum1 - v[i].sum1;
        if (res <= cnt)
        {
            res = cnt;
            ind = v[i].y;
        }
    }
    cout << ind;
}
