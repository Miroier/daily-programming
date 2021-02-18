#include "iostream"
#include "map"
#include "set"
using namespace std;
int n, k;
map<string, set<int>> mp;
void inp()
{
    cin >> n >> k;
    int id, m;
    while (k--)
    {
        cin >> id >> m;
        string name;
        while (m--)
        {
            cin >> name;
            mp[name].insert(id);
        }
    }
}
void work()
{
    string name;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        if (!mp[name].empty())
        {
            cout << name << " " << mp[name].size();
            for (auto it = mp[name].begin(); it != mp[name].end(); it++)
                cout << " " << *it;
            cout << endl;
        }
        else
            cout << name << " 0" << endl;
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    inp();
    work();
}
