#include "iostream"
#include "map"
using namespace std;
map<char, int> mp;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    string s1, s2;
    cin >> s1 >> s2;
    int ind1 = 0, ind2 = 0;
    while (ind1 < s1.size() || ind2 < s2.size())
    {
        if (s1[ind1] == s2[ind2])
            ind1++, ind2++;
        else
        {
            char tmp = toupper(s1[ind1]);
            // char tmp = s1[ind1] & 0xdf; 不能这么写
            if (!mp[tmp])
            {
                cout << tmp;
                mp[tmp] = 1;
            }
            ind1++;
        }
    }
}
