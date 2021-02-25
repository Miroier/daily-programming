#include "cmath"
#include "iostream"
#include "vector"
using namespace std;
typedef long long LL;
struct f
{
    LL up;
    LL low;
};
LL gcd(LL x, LL y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}
LL lcm(LL x, LL y)
{
    return x / gcd(x, y) * y;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    vector<f> v;
    cin >> n;
    v.resize(n);
    getchar();
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int pos = s.find('/');
        v[i].up = stoi(s.substr(0, pos));
        v[i].low = stoi(s.substr(pos + 1));
        int t = gcd(abs(v[i].up), v[i].low); //提前约分，否则会超long long错一个点
        v[i].up /= t;
        v[i].low /= t;
    }
    LL comlow = 1;
    for (int i = 0; i < n; i++)
        comlow = lcm(comlow, v[i].low);
    for (int i = 0; i < n; i++)
        v[i].up *= comlow / v[i].low;
    LL comup = 0;
    for (int i = 0; i < n; i++)
        comup += v[i].up;
    int tmp = gcd(abs(comup), comlow);
    comup /= tmp;
    comlow /= tmp;
    bool flag = 0;
    if (comup == 0)
        cout << "0";
    if (abs(comup) >= comlow)
    {
        cout << comup / comlow;
        comup %= comlow;
        flag = 1;
    }
    if (flag && comup)
        cout << " ";
    if (comup)
        cout << comup << '/' << comlow;
}
