#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int a[N], b[N];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
            i++, j++;
        else
        {
            j++;
        }
    }
    if (i == n)
        cout << "Yes";
    else
        cout << "No";
}
