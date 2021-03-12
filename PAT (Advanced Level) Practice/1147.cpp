#include "iostream"
#include "vector"
using namespace std;
int m, n;
vector<int> v;
void postorder(int x)
{
    if (x > n)
        return;
    postorder(x * 2);
    postorder(x * 2 + 1);
    cout << v[x] << (x == 1 ? "\n" : " ");
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> m >> n;
    v.resize(n + 1);
    while (m--)
    {
        bool mx = 1, mn = 1;
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        for (int i = n; i >= 2; i--)
        {
            if (v[i] > v[i / 2])
                mx = 0;
            if (v[i] < v[i / 2])
                mn = 0;
        }
        if (mx)
            cout << "Max Heap" << endl;
        else if (mn)
            cout << "Min Heap" << endl;
        else
            cout << "Not Heap" << endl;
        postorder(1);
    }
}
