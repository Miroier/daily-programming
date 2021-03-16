#include "algorithm"
#include "iostream"
using namespace std;
int n;
struct sum
{
    int s, c, d;
    bool operator<(const sum &t) const
    {
        if (s != t.s)
            return s < t.s;
        if (c != t.c)
            return c < t.c;
        return d < t.d;
    }
} sum[2500005];
int cnt = 0;
int main()
{
    cin >> n;
    for (int c = 0; c * c <= n; c++)
        for (int d = c; c * c + d * d <= n; d++)
            sum[cnt++] = {c * c + d * d, c, d};
    sort(sum, sum + cnt);
    for (int a = 0; a * a <= n; a++)
        for (int b = a; a * a + b * b <= n; b++)
        {
            int t = n - a * a - b * b;
            int left = 0, right = cnt;
            while (left < right)
            {
                int mid = left + right >> 1;
                if (sum[mid].s >= t)
                    right = mid;
                else
                    left = mid + 1;
            }
            if (sum[left].s == t)
            {
                printf("%d %d %d %d\n", a, b, sum[left].c, sum[left].d);
                return 0;
            }
        }
}
