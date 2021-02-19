#include "iostream"
#include "map"
#include "vector"
using namespace std;
int n;
vector<int> v;
map<int, int> mp;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    int x;
    while (n--)
    {
        cin >> x;
        if (mp[x])
            mp[x]++;
        else
        {
            mp[x] = 1;
            v.push_back(x);
        }
    }
    for (int i = 0; i < v.size(); i++)
        if (mp[v[i]] == 1)
        {
            cout << v[i];
            return 0;
        }
    cout << "None";
    return 0;
}
