#include "iostream"
#include "unordered_map"
#include "vector"
using namespace std;
typedef long long LL;
int n, m;
int a[10000];
int cnt = 0;
void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> a[i];
        int ind = i;
        while (ind / 2 > 0)
        {
            if (a[ind] > a[ind / 2])
                swap(a[ind], a[ind / 2]);
            ind /= 2;
        }
    }
}
unordered_map<int, int> mp;
void work()
{
    for (int i = 1; i <= n; i++)
        mp[a[i]] = i;
    getchar();
    string s;
    for (int i = 0; i < m; i++)
    {
        getline(cin, s);
        if (s.find("root") != string::npos)
        {
            int pos = s.find("is");
            int x = stoi(s.substr(0, pos));
            if (x == a[1])
                cout << 1;
            else
                cout << 0;
        }
        if (s.find("siblings") != string::npos)
        {
            int pos = s.find("and");
            int x = stoi(s.substr(0, pos));
            int pos2 = s.find("are");
            int y = stoi(s.substr(pos + 3, pos2));
            if (mp[x] / 2 == mp[y] / 2)
                cout << 1;
            else
                cout << 0;
        }
        if (s.find("parent") != string::npos)
        {
            int pos = s.find("is");
            int x = stoi(s.substr(0, pos));
            int pos2 = s.find("of");
            int y = stoi(s.substr(pos2 + 2));
            if (mp[x] == mp[y] / 2)
                cout << 1;
            else
                cout << 0;
        }
        if (s.find("left") != string::npos)
        {
            int pos = s.find("is");
            int x = stoi(s.substr(0, pos));
            int pos2 = s.find("of");
            int y = stoi(s.substr(pos2 + 2));
            if (mp[x] == mp[y] * 2)
                cout << 1;
            else
                cout << 0;
        }
        if (s.find("right") != string::npos)
        {
            int pos = s.find("is");
            int x = stoi(s.substr(0, pos));
            int pos2 = s.find("of");
            int y = stoi(s.substr(pos2 + 2));
            if (mp[x] == mp[y] * 2 + 1)
                cout << 1;
            else
                cout << 0;
        }
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
