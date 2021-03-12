#include "iostream"
#include "map"
#include "set"
using namespace std;
bool sureNoBroken[256];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int k, cnt;
    string s;
    cin >> k >> s;
    map<char, bool> mp;
    set<int> printed;
    char pre = '#';
    s += '#';
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == pre)
            cnt++;
        else
        {
            if (cnt % k != 0)
                sureNoBroken[pre] = true;
            cnt = 1;
        }
        if (i != s.length() - 1)
            mp[s[i]] = (cnt % k == 0);
        pre = s[i];
    }
    for (int i = 0; i < s.length() - 1; i++)
        if (sureNoBroken[s[i]])
            mp[s[i]] = false;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (mp[s[i]] && printed.find(s[i]) == printed.end())
        {
            printf("%c", s[i]);
            printed.insert(s[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < s.length() - 1; i++)
    {
        printf("%c", s[i]);
        if (mp[s[i]])
            i = i + k - 1;
    }
}
