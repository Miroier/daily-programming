#include "iostream"
using namespace std;
typedef long long LL;
LL n, k;
int num[100]; //10^10 * 2^100 ~41, but 50 is not enough
int len;
void add()
{
    int tmp[100];
    for (int i = 0, j = len - 1; j >= 0; i++, j--)
        tmp[i] = num[j];
    for (int i = 0; i < len; i++)
        num[i] += tmp[i], num[i + 1] += num[i] / 10, num[i] %= 10;
    if (num[len])
        len++;
}
bool check()
{
    int tmp[100];
    for (int i = 0, j = len - 1; j >= 0; i++, j--)
        tmp[i] = num[j];
    for (int i = 0; i < len; i++)
        if (num[i] != tmp[i])
            return false;
    return true;
}
int main()
{
    cin >> n >> k;
    while (n)
    {
        num[len++] = n % 10;
        n /= 10;
    }
    int i;
    // 有可能输入就是回文数，这种情况i=0
    for (i = 0; i < k; i++)
    {
        if (check())
        {
            for (int j = max(len - 1, 0); j >= 0; j--)
                cout << num[j];
            cout << endl
                 << i;
            break;
        }
        add();
    }
    if (i == k)
    {
        for (int j = max(len - 1, 0); j >= 0; j--)
            cout << num[j];
        cout << endl
             << k;
    }
}
