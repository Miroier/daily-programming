#include "iostream"
#include "map"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    string s1, s2;
    map<char, int> mp;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++)
        mp[s1[i]]++;
    int less = 0;
    for (int i = 0; i < s2.size(); i++)
    {
        if (mp[s2[i]])
            mp[s2[i]]--;
        else
            less++;
    }
    if (!less)
        cout << "Yes " << s1.size() - s2.size();
    else
        cout << "No " << less;
}
