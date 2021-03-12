#include "iostream"
using namespace std;
bool check(long long x)
{
    if (x <= 1)
        return false;
    if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;
    for (long long i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    string s, tmp;
    int l, k;
    cin >> l >> k;
    cin >> s;
    bool flag = 0;
    if (l < k) //最后一个点
    {
        cout << 404 << endl;
        return 0;
    }
    for (int i = 0; i <= s.size() - k; i++)
    {
        tmp = s.substr(i, k);
        if (check(stoll(tmp)))
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        cout << tmp << endl;
    else
        cout << 404 << endl;
}
