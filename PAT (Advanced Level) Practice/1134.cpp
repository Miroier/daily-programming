#include "iostream"
#include "set"
#include "vector"
using namespace std;
vector<pair<int, int>> v;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n, m, k;
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> y;
        int cnt = 0;
        set<int> st;
        while (y--)
        {
            cin >> x;
            st.insert(x);
        }
        for (int j = 0; j < v.size(); j++)
        {
            if (st.find(v[j].first) != st.end() || st.find(v[j].second) != st.end())
                cnt++;
        }
        if (cnt == m)
            puts("Yes");
        else
            puts("No");
    }
}
