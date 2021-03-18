#include "iostream"
using namespace std;
int tt(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}
int h, m, s;
int h1, m1, s1;
string str;
int x;
int getTime()
{
    getline(cin, str);
    if (str.back() != ')')
        str += " (+0)";
    sscanf(str.c_str(), "%d:%d:%d %d:%d:%d (+%d)", &h, &m, &s, &h1, &m1, &s1, &x);
    int time1 = tt(h1, m1, s1) - tt(h, m, s) + x * 24 * 3600;
    return time1;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++)
    {
        int res = getTime() + getTime() >> 1;
        printf("%02d:%02d:%02d\n", res / 3600, res % 3600 / 60, res % 60);
    }
}
