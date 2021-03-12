#include "algorithm"
#include "cmath"
#include "iostream"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    string x, y;
    cin >> n >> x >> y;
    string r1 = "", r2 = "";
    // 去前导零
    while (x.size() > 1 && x[0] == '0' && x[1] == '0')
        x.erase(1, 1);
    while (y.size() > 1 && y[0] == '0' && y[1] == '0')
        y.erase(1, 1);
    int pos1 = x.find(".");
    if (pos1 == string::npos)
        pos1 = x.length(), x.insert(x.end(), 1, '.');
    int pos2 = y.find(".");
    if (pos2 == string::npos)
        pos2 = y.length(), y.insert(y.end(), 1, '.');
    /*
        根据小数点的位置，有以下几种情况
        1. pos>1 向前移动小数点位置，直到pos=1，此时转2
        2. pos=1，此时有两种情况，第0位是0或者不是0
            2.1 如果不是0，num加1，小数点前移一位
            2.2 如果是0
                如果小数点后为0的话，向后找第一个不为0的位置并不断，并erase掉，如果找不到，也erase掉，但是后者的num不用减
     */
    int num1 = 0, num2 = 0;
    while (pos1 > 1)
    {
        swap(x[pos1 - 1], x[pos1]);
        pos1--, num1++;
    }
    if (pos1 == 1)
    {
        if (x[0] != '0')
        {
            swap(x[0], x[1]);
            x.insert(0, 1, '0');
            num1++;
        }
        else
        {
            int cnt = 1;
            while (pos1 + cnt < x.size() && x[pos1 + cnt] == '0')
                cnt++;
            if (pos1 + cnt < x.size() && x[pos1 + cnt] != '0')
                num1 -= cnt - 1;
            x.erase(pos1 + 1, cnt - 1);
        }
    }
    while (pos2 > 1)
    {
        swap(y[pos2 - 1], y[pos2]);
        pos2--, num2++;
    }
    if (pos2 == 1)
    {
        if (y[0] != '0')
        {
            swap(y[0], y[1]);
            y.insert(0, 1, '0');
            num2++;
        }
        else
        {
            int cnt = 1;
            while (pos2 + cnt < y.size() && y[pos2 + cnt] == '0')
                cnt++;
            if (pos2 + cnt < y.size() && y[pos2 + cnt] != '0')
                num2 -= cnt - 1;
            y.erase(pos2 + 1, cnt - 1);
        }
    }
    for (int i = 0; i < 2 + n; i++)
        r1 += (i <= x.size() - 1 ? x[i] : '0');
    for (int i = 0; i < 2 + n; i++)
        r2 += (i <= y.size() - 1 ? y[i] : '0');
    if (r1 == r2 && num1 == num2)
    {
        cout << "YES";
        printf(" %s*10^%d", r1.c_str(), num1);
    }
    else
    {
        cout << "NO";
        printf(" %s*10^%d", r1.c_str(), num1);
        printf(" %s*10^%d", r2.c_str(), num2);
    }
}
