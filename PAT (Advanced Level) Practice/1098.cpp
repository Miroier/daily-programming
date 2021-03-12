#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
vector<int> a, b;
void downAdjust(int high)
{
    int i = 1, j = i * 2;
    while (j <= high)
    {
        if (j + 1 < high && b[j + 1] > b[j])
            j++;
        if (b[j] < b[i])
            break;
        swap(b[i], b[j]);
        i = j, j = i * 2;
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int i = 2;
    while (i < n + 1 && b[i - 1] <= b[i])
        i++;
    int j = i;
    while (j < n + 1 && a[j] == b[j])
        j++;
    if (j == n + 1)
    {
        cout << "Insertion Sort" << endl;
        sort(b.begin() + 1, b.begin() + i + 1);
    }
    else
    {
        cout << "Heap Sort" << endl;
        j = n;
        while (j > 2 && b[j] >= b[1])
            j--;
        swap(b[1], b[j]);
        downAdjust(j);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
            cout << " ";
        cout << b[i];
    }
}
