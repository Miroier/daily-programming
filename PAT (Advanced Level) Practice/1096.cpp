#include "cmath"
#include "iostream"
using namespace std;
/*
    构造连乘，判断连乘是否整除n，并更新最大长度
 */
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    int first = 0, len = 0, maxn = sqrt(n);
    for (int i = 2; i <= maxn; i++)
    {
        int j, tmp = 1;
        for (j = i; j <= maxn; j++)
        {
            tmp *= j;
            if (n % tmp)
                break;
        }
        if (j - i > len)
        {
            len = j - i;
            first = i;
        }
    }
    if (first == 0)
        cout << 1 << endl
             << n;
    else
    {
        cout << len << endl;
        for (int i = 0; i < len; i++)
        {
            if (i != 0)
                cout << "*";
            cout << first + i;
        }
    }
}
