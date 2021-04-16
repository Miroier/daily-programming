#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
typedef long long LL;
int n;
LL a[100];
LL gcd(LL x, LL y)
{
    return y ? gcd(y, x % y) : x;
}
struct node
{
    LL up, down;
    node(LL _up, LL _down)
    {
        up = _up, down = _down;
        LL d = gcd(up, down);
        up /= d;
        down /= d;
    }
};
vector<node> v;
LL gcd_sub(LL x, LL y)
{
    if (x < y)
        swap(x, y);
    if (y == 1)
        return x;
    return gcd_sub(y, x / y);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            v.push_back(node{a[i], a[0]});
    LL up = v[0].up, down = v[0].down;
    for (int i = 1; i < v.size(); i++)
    {
        up = gcd_sub(up, v[i].up);
        down = gcd_sub(down, v[i].down);
    }
    cout << up << "/" << down;
}
