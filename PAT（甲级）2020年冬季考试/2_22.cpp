#include "iostream"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    string s, p;
    cin >> s >> p;
    int left, right, len = 100000;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != p[0])
            continue;

        int ind = 0; //记录最右边的下标
        int pos = i;
        int k;
        for (int j = 0; j < p.size(); j++)
        {
            for (k = pos; k < s.size(); k++)
            {
                if (s[k] == p[j])
                {
                    if (j == p.size() - 1)
                    {
                        ind = k;
                        break;
                    }
                    pos = k + 1;
                    break;
                }
            }
        }
        if (ind == 0)
            continue;
        if (len > ind - i + 1)
        {
            len = ind - i + 1;
            left = i;
        }
    }
    cout << s.substr(left, len);
}
