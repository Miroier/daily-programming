#include "iostream"
#include "vector"
using namespace std;
int n;
vector<int> v;
bool mx = 1, mn = 1;
vector<int> tmp;
void dfs(int ind)
{
    if (ind > n)
        return;
    if (2 * ind > n)
    {
        tmp.push_back(v[ind]);
        for (int i = 0; i < tmp.size(); i++)
            cout << tmp[i] << (i < tmp.size() - 1 ? " " : "\n");
        for (int i = 1; i < tmp.size(); i++)
        {
            if (tmp[i] > tmp[i - 1])
                mx = 0;
            if (tmp[i] < tmp[i - 1])
                mn = 0;
        }
        tmp.pop_back();
        return;
    }
    tmp.push_back(v[ind]);
    dfs(ind * 2 + 1);
    dfs(ind * 2);
    tmp.pop_back();
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    dfs(1);
    if (mx)
        cout << "Max Heap" << endl;
    else if (mn)
        cout << "Min Heap" << endl;
    else
        cout << "Not Heap" << endl;
}
