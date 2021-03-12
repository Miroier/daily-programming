#include "iostream"
#include "string"
using namespace std;

int a, b, c;
string res;

int main()
{
    cin >> a >> b;
    c = a + b;
    if (!c)
        res = '0';
    while (c)
    {
        char tmp[10];
        if (c >= 1000 || c <= -1000)
            sprintf(tmp, "%03d", abs(c % 1000));
        else
            sprintf(tmp, "%d", c % 1000);
        res = string(tmp) + (res == "" ? "" : ",") + res;
        c /= 1000;
    }
    cout << res;
}
