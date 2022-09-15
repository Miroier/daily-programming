#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 5;

int n;
vector<PII> segs;

void merge(vector<PII> &segs)
{
    vector<PII> res;
    sort(segs.begin(), segs.end()); // pair排序，先排first，再排second

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
    {
        if (ed < seg.first)
        {
            if (st != -2e9)
                res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else
            ed = max(ed, seg.second);
    }

    if (st != -2e9)
        res.push_back({st, ed});

    segs = res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        segs.push_back({x, y});
    }
    merge(segs);
    cout << segs.size() << endl;
}
