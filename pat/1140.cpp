#include "iostream"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    string s;
    int n;
    cin >> s >> n;
    n--;
    while (n--)
    {
        string tmp = "";
        char c = s[0];
        int cnt = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            if (c != s[i] || i == s.size())
            {
                tmp += c + to_string(cnt);
                cnt = 1;
                c = s[i];
            }
            else if (c == s[i])
                cnt++;
        }
        s = tmp;
    }
    cout << s;
}
