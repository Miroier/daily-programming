/* 四平方和 */
#include "unordered_map"
#include <iostream>
using namespace std;
int n;
struct node
{
    int c, d;
};
unordered_map<int, node> mp;
int main()
{
    cin >> n;
    for (int c = 0; c * c <= n / 2; c++)
        for (int d = c; c * c + d * d <= n; d++)
            if (!mp.count(c * c + d * d))
                mp[c * c + d * d] = {c, d};
    for (int a = 0; a * a <= n / 4; a++)
        for (int b = a; a * a + b * b <= n / 2; b++)
        {
            if (mp.count(n - a * a - b * b))
            {
                int c = mp[n - a * a - b * b].c;
                int d = mp[n - a * a - b * b].d;
                printf("%d %d %d %d", a, b, c, d);
                return 0;
            }
        }
    return 0;
}
