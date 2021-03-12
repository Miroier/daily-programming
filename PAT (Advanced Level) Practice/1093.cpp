#include "iostream"
using namespace std;
/*
    首先遍历一遍，计算T的个数cnt_t
    然后再一边，遇到P则cnt_p++，遇到T则cnt_t--，这样遇到A时，cnt_p代表A前面的p的个数，cnt_t代表后面的t的个数，相乘即可
 */
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    int cnt_t = 0, cnt_p = 0, res = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'T')
            cnt_t++;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'P')
            cnt_p++;
        else if (s[i] == 'T')
            cnt_t--;
        else
            res = (res + (cnt_t * cnt_p) % 1000000007) % 1000000007;
    cout << res;
}
