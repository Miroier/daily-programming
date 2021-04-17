/* 手链样式 */
#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;

int main()
{
    string s = "aaabbbbccccc";
    int ans = 0;
    vector<string> v;
    do
    {
        int i;
        for (i = 0; i < v.size(); i++)
            if (v[i].find(s) != string::npos)
                break;
        if (i != v.size())
            continue;
        string s2 = s + s;
        v.push_back(s2);
        reverse(s2.begin(), s2.end());
        v.push_back(s2);
        ans++;
    } while (next_permutation(s.begin(), s.end()));
    cout << ans;
}
