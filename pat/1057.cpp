#include "algorithm"
#include "iostream"
#define lowbit(x) ((x) & (-x))
using namespace std;
const int maxn = 100010;
int st[maxn], cnt;
int c[maxn];
int n;
void update(int x, int v)
{
    for (int i = x; i < maxn; i += lowbit(i))
        c[i] += v;
}
int getSum(int x)
{
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}
void PeekMedian()
{
    int low = 1, high = maxn, k = ((cnt + 1) / 2);
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (getSum(mid) >= k)
            high = mid;
        else
            low = mid + 1;
    }
    printf("%d\n", low);
}
// void update(int x, int v)
// {
//     for (int i = x; i < maxn; i += lowbit(i))
//         c[i] += v;
// }
// int getsum(int x)
// {
//     int sum = 0;
//     for (int i = x; i >= 1; i -= lowbit(i))
//         sum += c[i];
//     return sum;
// }
// void PeekMedian()
// {
//     int left = 1, right = maxn, mid, k = (cnt + 1) / 2;
//     while (left < right)
//     {
//         mid = (left + right) / 2;
//         if (getsum(mid) >= k)
//             right = mid;
//         else
//             left = mid + 1;
//     }
//     printf("%d\n", left);
// }
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    string s;
    int x;
    while (n--)
    {
        cin >> s;
        if (s == "Push")
        {
            cin >> x;
            st[++cnt] = x;
            update(x, 1);
        }
        else if (s == "Pop")
        {
            if (cnt == 0)
                printf("Invalid\n");
            else
            {
                update(st[cnt], -1);
                printf("%d\n", st[cnt--]);
            }
        }
        else if (s == "PeekMedian")
        {
            if (cnt == 0)
                printf("Invalid\n");
            else
                PeekMedian();
        }
    }
}
