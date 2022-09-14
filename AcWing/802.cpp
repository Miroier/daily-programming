#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 3e5 + 5;

int n, m;
int a[N], s[N];

vector<int> alls; //存所有要离散化的值，既包括输入的值的坐标，也包括查询的两端点的坐标，n+2m
vector<PII> add, query;

//求离散化后的值对应的下标
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l + 1; //前缀和下标要从1开始
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});

        alls.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }

    //去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    //插入操作
    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }

    //预处理前缀和
    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];

    //查询操作
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
}
