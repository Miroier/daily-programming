#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
typedef long long LL;
struct peo
{
    int in, out;
};
int n;
vector<peo> v;
void inp()
{
    cin >> n;
    int hh0, mm0, ss0;
    int hh, mm, ss;
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d:%d:%d", &hh0, &mm0, &ss0, &hh, &mm, &ss);
        int in = hh0 * 3600 + mm0 * 60 + ss0, out = hh * 3600 + mm * 60 + ss;
        if (in < out && out <= 23 * 3600 + 59 * 60 + 59)
            v.push_back({in, out});
    }
}
bool cmp(peo a, peo b)
{
    if (a.out != b.out)
        return a.out < b.out;
    return a.in < b.in;
}
void work()
{
    sort(v.begin(), v.end(), cmp);
    // for (int i = 0; i < v.size(); i++)
    //     cout << v[i].in << " " << v[i].out << endl;
    int pretime = 0x3fffffff;
    int cnt = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i].out <= pretime)
        {
            cnt++;
            pretime = v[i].in;
        }
    }
    cout << cnt;
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
