#include "algorithm"
#include "iostream"
#include "set"
using namespace std;
struct item
{
    int ind;
    int cnt;
    bool friend operator<(item a, item b)
    {
        if (a.cnt != b.cnt)
            return a.cnt > b.cnt;
        return a.ind < b.ind;
    }
};
int n, k;
set<item> st;
int book[50010];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;
    int x;
    cin >> x;
    st.insert({x, ++book[x]});
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        printf("%d:", x);
        int cnt = 0;
        for (auto it = st.begin(); cnt < k && it != st.end(); cnt++, it++)
            cout << " " << it->ind;
        puts("");
        auto it = st.find({x, book[x]});
        if (it != st.end())
            st.erase(it);
        st.insert({x, ++book[x]});
    }
}
