#include "iostream"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int a[3];
    int b[3];
    scanf("%d.%d.%d %d.%d.%d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
    for (int i = 0; i < 3; i++)
        a[i] += b[i];
    a[1] += a[2] / 29, a[2] %= 29;
    a[0] += a[1] / 17, a[1] %= 17;
    printf("%d.%d.%d", a[0], a[1], a[2]);
}
