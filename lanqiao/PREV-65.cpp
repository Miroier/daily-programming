#include "iostream"
#include "map"
using namespace std;
string s;
map<char, int> mp;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        mp[s[i]]++;
    char ind;
    int cnt;
    for (map<char, int>::iterator c = mp.begin(); c != mp.end(); c++)
        if (cnt < c->second)
            ind = c->first, cnt = c->second;
        else if (cnt == c->second && ind > c->first)
            ind = c->first;
    cout << ind << endl
         << cnt << endl;
}
