#include "algorithm"
#include "iostream"
#include "string"
#include "vector"
using namespace std;
int n;
vector<string> v;
bool cmp(string &a, string &b)
{
    return a + b < b + a;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    string x;
    for (int i = 0; i < n; i++)
        cin >> x, v.push_back(x);
    sort(v.begin(), v.end(), cmp);
    string ans = "";
    for (int i = 0; i < n; i++)
        ans += v[i];
    int cnt = 0;
    while (ans[cnt] == '0')
        cnt++;
    if (cnt)
        ans.erase(0, cnt);
    if (ans.empty())
        cout << 0;
    else
        cout << ans;
}
