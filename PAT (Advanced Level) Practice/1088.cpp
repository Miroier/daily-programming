#include "iostream"
using namespace std;
typedef long long LL;
LL al, ah, bl, bh;
LL gcd(LL a, LL b)
{
    if (b == 0)
        return a;
    gcd(b, a % b);
}
LL lcm(LL a, LL b)
{
    return a / gcd(a, b) * b;
}
void inp()
{
    string s1, s2;
    cin >> s1 >> s2;
    int pos;
    pos = s1.find('/');
    ah = stoi(s1.substr(0, pos));
    al = stoi(s1.substr(pos + 1));
    pos = s2.find('/');
    bh = stoi(s2.substr(0, pos));
    bl = stoi(s2.substr(pos + 1));
}
void show(LL high, LL low)
{
    LL tmp = gcd(abs(high), low);
    high /= tmp;
    low /= tmp;
    if (high == 0)
    {
        cout << "0";
        return;
    }
    bool flag = 0;
    bool neg = 0;
    if (high < 0)
        neg = 1;
    if (neg)
        cout << "(";
    if (abs(high) >= low)
    {
        cout << high / low;
        high %= low;
        flag = 1;
    }
    if (flag && high)
        cout << " ";
    if (high)
    {
        if (flag)
            cout << abs(high) << "/" << low;
        else
            cout << high << "/" << low;
    }
    if (neg)
        cout << ")";
}
void add()
{
    show(ah, al);
    cout << " + ";
    show(bh, bl);
    cout << " = ";
    LL ch = 0, cl = 0;
    cl = lcm(al, bl);
    ch = ah * cl / al + bh * cl / bl;
    show(ch, cl);
    cout << endl;
}
void sub()
{
    show(ah, al);
    cout << " - ";
    show(bh, bl);
    cout << " = ";
    LL ch = 0, cl = 0;
    cl = lcm(al, bl);
    ch = ah * cl / al - bh * cl / bl;
    show(ch, cl);
    cout << endl;
}
void mul()
{
    show(ah, al);
    cout << " * ";
    show(bh, bl);
    cout << " = ";
    LL ch = 0, cl = 0;
    cl = al * bl;
    ch = ah * bh;
    show(ch, cl);
    cout << endl;
}
void div()
{
    show(ah, al);
    cout << " / ";
    show(bh, bl);
    cout << " = ";
    LL ch = 0, cl = 0;
    cl = al * bh;
    ch = ah * bl;
    if (cl < 0)
        cl *= -1, ch *= -1;
    if (cl == 0)
        cout << "Inf";
    else
        show(ch, cl);
    cout << endl;
}
void work()
{
    LL tmp = gcd(abs(ah), al);
    ah /= tmp;
    al /= tmp;
    tmp = gcd(abs(bh), bl);
    bh /= tmp;
    bl /= tmp;
    add();
    sub();
    mul();
    div();
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    inp();
    work();
}
