#include "algorithm"
#include "iostream"
#include "set"
using namespace std;
struct date
{
    int year, month, day;
    date(int year, int month, int day)
    {
        if (year <= 59)
            year += 2000;
        else
            year += 1900;
        this->year = year;
        this->month = month;
        this->day = day;
    }
    bool friend operator<(date a, date b)
    {
        if (a.year != b.year)
            return a.year < b.year;
        if (a.month != b.month)
            return a.month < b.month;
        return a.day < b.day;
    }
};
set<date> st;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int year, int month, int day)
{
    if (year <= 59)
        year += 2000;
    else
        year += 1900;
    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;
    if (month != 2)
        return day <= days[month];
    if (month == 2)
    {
        if (year % 100 && year % 4 == 0 || year % 400 == 0)
            return day <= 29;
        else
            return day <= 28;
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);
    if (check(a, b, c))
        st.insert(date(a, b, c));
    if (check(c, a, b))
        st.insert(date(c, a, b));
    if (check(c, b, a))
        st.insert(date(c, b, a));
    for (auto x : st)
        printf("%d-%02d-%02d\n", x.year, x.month, x.day);
}
