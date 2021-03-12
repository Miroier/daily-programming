#include "iostream"
#include "set"
#include "vector"
using namespace std;
int convert(int x)
{
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    set<int> st;
    vector<int> v;
    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        st.insert(convert(x));
    }
    cout << st.size() << endl;
    for (auto i : st)
        v.push_back(i);
    for (int i = 0; i < v.size(); i++)
        cout << (i > 0 ? " " : "") << v[i];
}
