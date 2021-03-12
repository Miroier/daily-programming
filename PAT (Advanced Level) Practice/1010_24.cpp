#include "iostream"
using namespace std;
typedef long long LL;
string n1, n2;
int tag, radix;
LL any2dec(string x, int r)
{
    LL res = 0;
    for (int i = 0; i < x.length(); i++)
        res = res * r + (x[i] >= 'a' ? x[i] - 'a' + 10 : x[i] - '0');
    return res;
}
int findMax(string x)
{
    int mx = 0;
    for (int i = 0; i < x.length(); i++)
        mx = max(mx, (x[i] >= 'a' ? x[i] - 'a' + 10 : x[i] - '0'));
    return mx;
}
void sol(string n1, string n2)
{
    LL x = any2dec(n1, radix);
    bool flag = false;
    int st = findMax(n2);
    for (int i = st + 1; i <= 100; i++)
        if (x == any2dec(n2, i))
        {
            cout << i << endl;
            flag = true;
            break;
        }
    if (!flag)
        cout << "Impossible" << endl;
}
int main()
{
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 1)
        sol(n1, n2);
    else
        sol(n2, n1);
}
