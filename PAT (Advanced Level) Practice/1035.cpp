#include "iostream"
#include "map"
#include "string"
using namespace std;
int n;
int cnt;
pair<string, string> p[1010];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    string a, b;
    int pos;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        bool flag = false;
        while (pos = b.find("1"), pos != string::npos)
            b.replace(pos, 1, "@"), flag = true;
        while (pos = b.find("0"), pos != string::npos)
            b.replace(pos, 1, "%"), flag = true;
        while (pos = b.find("l"), pos != string::npos)
            b.replace(pos, 1, "L"), flag = true;
        while (pos = b.find("O"), pos != string::npos)
            b.replace(pos, 1, "o"), flag = true;
        if (flag)
            p[cnt++] = make_pair(a, b);
    }
    if (!cnt)
    {
        if (n == 1)
            printf("There is 1 account and no account is modified", n);
        else
            printf("There are %d accounts and no account is modified", n);
    }
    else
    {
        cout << cnt << endl;
        for (int i = 0; i < cnt; i++)
            cout << p[i].first << " " << p[i].second << endl;
    }
}
