/* 星期一 */
#include <iostream>
using namespace std;
bool check(int x)
{
    return (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0));
}
int main()
{
    int day = 0;
    for (int i = 1901; i <= 2000; i++)
    {
        if (check(i))
            day += 366;
        else
            day += 365;
    }
    day -= 6;
    int ans = 0;
    for (; day > 0; day -= 7)
        ans++;
    cout << ans;
    return 0;
}
