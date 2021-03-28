#include "iostream"
using namespace std;
int k;
string s;
int dfs()
{
    int res = 0;
    while (k < s.size())
    {
        if (s[k] == '(')
        {
            k++;
            res += dfs();
            k++;
        }
        else if (s[k] == '|')
        {
            k++;
            res = max(res, dfs());
        }
        else if (s[k] == ')')
            break;
        else
            res++, k++;
    }
    return res;
}
int main()
{
    cin >> s;
    cout << dfs();
}
