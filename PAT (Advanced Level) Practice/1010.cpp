#include "algorithm"
#include "iostream"
#include "string"
using namespace std;
typedef long long LL;
string n1, n2;
LL tag, radix;
LL any2dec(string x, LL r)
{
    LL res = 0;
    for (int i = 0; i < x.length(); i++)
        res = res * r + (x[i] >= 'a' ? x[i] - 'a' + 10 : x[i] - '0');
    return res;
}
LL sol(string n1, string n2)
{
    LL x = any2dec(n1, radix);
    char it = *max_element(n2.begin(), n2.end());
    LL low = (it >= 'a' ? it - 'a' + 10 : it - '0') + 1;
    LL high = max(x, low);
    while (low <= high)
    {
        LL mid = (low + high) >> 1;
        LL t = any2dec(n2, mid);
        if (t > x || t < 0) //t<0是溢出的情况
            high = mid - 1;
        else if (t < x)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    cin >> n1 >> n2 >> tag >> radix;
    LL res = tag == 1 ? sol(n1, n2) : sol(n2, n1);
    if (res != -1)
        cout << res;
    else
        cout << "Impossible";
}
