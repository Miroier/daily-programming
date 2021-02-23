#include "iostream"
#include "map"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    string s;
    string tmp;
    map<string, int> mp;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        s[i] |= 0x20;
    for (int i = 0; i < s.size(); i++)
        if (!(s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'z'))
            s[i] = ' ';
    s = ' ' + s + ' ';
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            tmp += s[i];
        }
        if (s[i] == ' ')
        {
            if (!tmp.empty())
                mp[tmp]++;
            tmp = "";
        }
    }
    int cnt = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
        if (cnt < it->second)
        {
            tmp = it->first;
            cnt = it->second;
        }
    cout << tmp << " " << cnt << endl;
}
