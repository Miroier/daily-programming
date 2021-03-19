#include "algorithm"
#include "iostream"
#include "map"
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

PII a[100005];
int s[2][100005];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;

    sort(a + 1, a + n + 1);
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= n; j++)
            s[i][j] = s[i][j - 1] + (a[j].y == i);

    int ind = 0, mx = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = s[0][i - 1] + s[1][n] - s[1][i - 1];
        if (tmp >= mx)
            mx = tmp, ind = a[i].x;
        while (i + 1 <= n && a[i + 1].x == a[i].x)
            i++;
    }
    cout << ind;
}
