#include "algorithm"
#include "iostream"
#include "map"
#include "vector"
using namespace std;
int k;
vector<pair<int, string>> v;
int a[54];
void inp()
{
    cin >> k;
    string c[4] = {"S", "H", "C", "D"};
    int cnt = 1;
    for (int i = 0; i < 4; i++)
        for (int j = 1; j <= 13; j++)
            v.push_back(make_pair(cnt++, c[i] + to_string(j)));
    v.push_back(make_pair(cnt++, "J1"));
    v.push_back(make_pair(cnt++, "J2"));
    for (int i = 0; i < 54; i++)
        cin >> a[i];
}
void work()
{
    while (k--)
    {
        for (int i = 0; i < 54; i++)
            v[i].first = a[i];
        sort(v.begin(), v.end());
    }
    cout << v[0].second;
    for (int i = 1; i < 54; i++)
        cout << " " << v[i].second;
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
