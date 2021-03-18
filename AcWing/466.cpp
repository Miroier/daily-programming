#include "iostream"
using namespace std;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int x)
{
    int year = x / 10000;
    int month = x % 10000 / 100;
    int day = x % 100;
    if (month == 0 || month > 12)
        return false;
    if (month != 2)
        return day <= days[month];
    if (year % 100 && year % 4 == 0 || year % 400 == 0)
        return day <= 29;
    else
        return day <= 28;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int st, ed;
    int cnt = 0;
    cin >> st >> ed;
    for (int year = 1000; year <= 9999; year++)
    {
        int date = year, tmp = year;
        for (int i = 0; i < 4; i++)
            date = date * 10 + tmp % 10, tmp /= 10;
        if (st <= date && date <= ed && check(date))
            cnt++;
    }
    cout << cnt;
}
