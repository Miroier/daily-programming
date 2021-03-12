#include "iostream"
#include "map"
#include "set"
#include "string"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int k;
    string s;
    map<char, bool> mp;  //是否是坏键
    map<char, bool> mp2; //是否判断过
    set<char> st;        //是否输出过
    cin >> k >> s;
    for (int i = 0; i < s.size(); i++)
        mp[s[i]] = true, mp2[s[i]] = false;
    int len = s.size() - k + 1;
    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        int pos = -1;
        while (pos = s.find(c, pos + 1), mp[c] && !mp2[c] && pos != string::npos)
        {
            for (int j = 1;; j++)
                if (s[i] != s[i + j])
                {
                    mp2[c] = true;
                    if (j % k != 0)
                        mp[c] = false;
                    break;
                }
        }
        if (mp[c] && st.find(c) == st.end())
        {
            cout << c;
            st.insert(c);
            string C(1, c);
            string tmp(k, c);
            int pos = -1;
            while (pos = s.find(tmp, pos + 1), pos != string::npos)
                s = s.replace(pos, k, C), len -= k - 1;
        }
    }
    cout << endl
         << s;
}
