#include "iostream"
#include "vector"
using namespace std;
int tsize, n, m;
// int a[100005];
vector<int> a; //这里不用vector就会报错，理论上数组也可以的啊，原因不知
bool isprime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
bool insert(int x)
{
    for (int i = 0; i < tsize; i++)
    {
        if (a[(x + i * i) % tsize] == 0)
        {
            a[(x + i * i) % tsize] = x;
            return 1;
        }
    }
    return 0;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> tsize >> n >> m;
    while (!isprime(tsize))
        tsize++;
    a.resize(tsize);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!insert(x))
            printf("%d cannot be inserted.\n", x);
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j <= tsize; j++)
        {
            ans++;
            if (a[(x + j * j) % tsize] == x || a[(x + j * j) % tsize] == 0)
                break;
        }
    }
    printf("%.1lf\n", (double)ans / m);
}
