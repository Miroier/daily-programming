#include "iostream"
#include "vector"
using namespace std;
int n, m;
vector<int> sum;
vector<pair<int, int>> res;
void inp()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    sum.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> sum[i], sum[i] += sum[i - 1];
}
int find(int i)
{
    int low = i + 1, high = n;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (sum[mid] - sum[i] >= m)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
void work()
{
    int mnsum = sum[n];
    // 二分，枚举左端点，找第一个让能让和大于等于m的右端点
    for (int i = 0; i < n; i++)
    {
        int j = find(i);
        if (mnsum > sum[j] - sum[i] && sum[j] - sum[i] >= m)
            mnsum = sum[j] - sum[i];
    }
    for (int i = 0; i < n; i++)
    {
        int j = find(i);
        if (mnsum == sum[j] - sum[i])
            res.push_back(make_pair(i + 1, j));
    }
    for (int i = 0; i < res.size(); i++)
        printf("%d-%d\n", res[i].first, res[i].second);
}
int main()
{
    inp();
    work();
}
