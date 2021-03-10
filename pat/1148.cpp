#include "iostream"
using namespace std;
int lie[105];
int a[105];
int n;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    //假设i,j是狼人
    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++)
        {
            fill(lie, lie + 105, 0);
            for (int k = 1; k <= n; k++)
            {
                if (a[k] > 0 && (a[k] == i || a[k] == j))
                    lie[k] = 1;
                if (a[k] < 0 && (-a[k] != i && -a[k] != j))
                    lie[k] = 1;
            }
            int sum = 0;
            for (int k = 1; k <= n; k++)
                sum += lie[k];
            if ((lie[i] || lie[j]) && !(lie[i] && lie[j]))
                if (sum == 2)
                {
                    cout << i << " " << j << endl;
                    return 0;
                }
        }
    cout << "No Solution" << endl;
}
