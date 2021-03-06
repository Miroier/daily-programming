#include "iostream"
using namespace std;
int n, k, q;
int dad[10010];
bool bird[10010];
int cntbird;
int cntuni;
int anc(int x)
{
    if (dad[x])
        return dad[x] = anc(dad[x]); //路径压缩
    return x;
}
void uni(int x, int y)
{
    x = anc(x);
    y = anc(y);
    if (x != y)
        dad[x] = y, cntuni++;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    int tmp[10010];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        int x;
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &x);
            if (!bird[x])
            {
                cntbird++;
                bird[x] = 1;
            }
            tmp[j] = x;
        }
        for (int j = 1; j < k; j++)
            uni(tmp[j - 1], tmp[j]);
    }
    cout << cntbird - cntuni << " " << cntbird << endl;
    cin >> q;
    int x, y;
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &x, &y);
        if (anc(x) == anc(y))
            printf("Yes\n");
        else
            printf("No\n");
    }
}
