#include "iostream"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    string tmp;
    string ans;
    int i;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == 'E')
            break;
        tmp += s[i];
    }
    bool flag = false; //标记正负
    ans = tmp;
    if (ans[0] == '+')
        flag = true;
    ans.erase(0, 1);
    tmp = "";
    for (i++; i < s.size(); i++)
        tmp += s[i];
    int e = stoi(tmp);
    /*
        小数点在s[2]
        如果e>0
            将小数点向后移动，如果小数点在最后一位的话加0
        如果e<0
            将小数点前移
     */
    int ind = 1;
    while (e > 0)
    {
        swap(ans[ind], ans[ind + 1]);
        ind++;
        e--;
        if (ind == ans.size() - 1 && e)
            ans += '0';
        else if (ind == ans.size() - 1)
            ans.erase(ind);
    }
    while (e < 0)
    {
        swap(ans[ind], ans[ind - 1]);
        ind--;
        e++;
        if (ind == 0)
            ans = '0' + ans, ind++;
    }
    if (!flag)
        ans = '-' + ans;
    cout << ans;
}
