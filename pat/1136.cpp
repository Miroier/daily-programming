#include "iostream"
using namespace std;
int a[1005], b[1005], sum[1005];
int len;
struct Bigint
{
    int a[1015], len = 1;
    Bigint(int x = 0)
    {
        fill(a, a + 1015, 0);
        for (; x; len++)
            a[len] = x % 10, x /= 10;
        len--;
    }
    Bigint(string s)
    {
        fill(a, a + 1015, 0);
        for (; len <= s.size(); len++)
            a[len] = s[s.size() - len] - '0';
        len--;
    }
    int &operator[](int i)
    {
        return a[i];
    }
    void flatten(int L)
    {
        len = L;
        for (int i = 1; i <= len; i++)
            a[i + 1] += a[i] / 10, a[i] %= 10;
        while (!a[len])
            len--;
    }
    void print()
    {
        for (int i = max(1, len); i >= 1; i--)
            cout << a[i];
    }
};
Bigint operator+(Bigint a, Bigint b)
{
    Bigint c;
    int len = max(a.len, b.len);
    for (int i = 1; i <= len; i++)
        c[i] += a[i] + b[i];
    c.flatten(len + 1);
    return c;
}
bool operator==(Bigint a, Bigint b)
{
    if (a.len != b.len)
        return false;
    for (int i = 1; i <= a.len; i++)
        if (a[i] != b[i])
            return false;
    return true;
}
Bigint reverse(Bigint a)
{
    Bigint c;
    int len = a.len;
    for (int i = 1; i <= len; i++)
        c[i] = a[len - i + 1];
    c.len = len;
    return c;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    bool flag = 0;
    string s;
    cin >> s;
    Bigint a(s);
    for (int i = 0; i < 10; i++)
    {
        if (a == reverse(a)) //先判断，如果是的话就不用继续了，这里有3个测试点
        {
            flag = 1;
            a.print();
            printf(" is a palindromic number.\n");
            break;
        }
        Bigint b = reverse(a);
        Bigint sum = a + b;
        a.print();
        cout << " + ";
        b.print();
        cout << " = ";
        sum.print();
        puts("");
        a = sum;
    }
    if (!flag)
        printf("Not found in 10 iterations.");
}
