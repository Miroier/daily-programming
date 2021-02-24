#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n;
vector<string> v;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    getchar();
    v.resize(n + 1);
    for (int i = 0; i < n; i++)
        getline(cin, v[i]);
    string same = "";
    int mn = 300;
    for (int i = 0; i < n; i++)
        mn = min(mn, (int)v[i].size());
    for (int i = 1; i <= mn; i++)
    {
        int flag = 1;
        for (int j = 1; j < n; j++)
            if (v[j][v[j].size() - i] != v[j - 1][v[j - 1].size() - i])
            {
                flag = 0;
                break;
            }
        if (flag)
            same = v[0][v[0].size() - i] + same;
        else
            break;
    }
    if (same != "")
        cout << same;
    else
        cout << "nai";
}
