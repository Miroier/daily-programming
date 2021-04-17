#include "iostream"
#include "set"
using namespace std;
const int N = 1100005;
int n;
int dad[N];
int a[N];
int anc(int x)
{
    if (dad[x] != x)
        dad[x] = anc(dad[x]);
    return dad[x];
}
int main()
{
    cin >> n;
    for (int i = 0; i < N; i++)
        dad[i] = i;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        x = anc(x);
        dad[x] = x + 1;
        a[i] = x;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
