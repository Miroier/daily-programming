#include <iostream>
using namespace std;
string s;
int len;
int pos;
int dfs()
{
    int tmp = 0;
    int mx = 0;
    while (pos < len)
    {
        if (s[pos] == '(')
        {
            pos++;
            tmp += dfs();
        }
        else if (s[pos] == 'x')
        {
            pos++, tmp++;
        }
        else if (s[pos] == '|')
        {
            pos++;
            mx = max(mx, tmp);
            tmp = 0;
        }
        else if (s[pos] == ')')
        {
            pos++;
            mx = max(mx, tmp);
            return mx;
        }
    }
    mx = max(mx, tmp);
    return mx;
}
int main()
{
    cin >> s;
    len = s.size();
    cout << dfs();
    return 0;
}
