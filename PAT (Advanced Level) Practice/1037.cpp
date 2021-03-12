#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
typedef long long LL;
int nc, np;
vector<int> a1, a2;
vector<int> b1, b2;
void inp()
{
    cin >> nc;
    int x;
    for (int i = 0; i < nc; i++)
    {
        cin >> x;
        if (x >= 0)
            a1.push_back(x);
        else
            a2.push_back(x);
    }
    cin >> np;
    for (int i = 0; i < np; i++)
    {

        cin >> x;
        if (x >= 0)
            b1.push_back(x);
        else
            b2.push_back(x);
    }
}
bool cmp1(int a, int b)
{
    return a > b;
}
bool cmp2(int a, int b)
{
    return a < b;
}
void work()
{
    LL sum = 0;
    sort(a1.begin(), a1.end(), cmp1);
    sort(a2.begin(), a2.end(), cmp2);
    sort(b1.begin(), b1.end(), cmp1);
    sort(b2.begin(), b2.end(), cmp2);
    for (int i = 0; i < min(a1.size(), b1.size()); i++)
        sum += a1[i] * b1[i];
    for (int i = 0; i < min(a2.size(), b2.size()); i++)
        sum += a2[i] * b2[i];
    cout << sum;
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
