/*
    这题要从质因子分解的角度去做
    已知x可以被分解为p[1]^alpha[1]*p[2]^alpha[2]*...*p[k]^alpha[k]
    要求序列长度最大，所以序列每一项的值一定比前一项大一个质因子
    所以题目实际上相当于求x的所有质因子的排列数
    ans= (alpha[1]+alpha[2]+...+alpha[k])!/(alpha[1]!*alpha[2]!*...*alpha[k]!)
 */
#include "iostream"
using namespace std;
typedef long long LL;
const int N = (1 << 20) + 5;
bool isprime[N];
int prime[N];
int cnt;
struct factor
{
    int x;
    int cnt;
};
void Prime(int x)
{
    for (int i = 2; i <= x; i++)
        isprime[i] = true;
    for (LL i = 2; i <= x; i++)
    {
        if (isprime[i])
        {
            prime[cnt++] = i;
            for (LL j = i * i; j <= x; j += i)
                isprime[j] = false;
        }
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int x;
    Prime(1 << 20);
    while (cin >> x)
    {
        factor fac[10];
        int num = 0, totalnum = 0;
        for (int i = 0; prime[i] * prime[i] <= x; i++)
        {
            if (x % prime[i] == 0)
            {
                fac[num].x = x, fac[num].cnt = 0;
                while (x % prime[i] == 0)
                {
                    fac[num].cnt++;
                    x /= prime[i];
                    totalnum++;
                }
                num++;
            }
        }
        if (x != 1)
        {
            fac[num].x = x;
            fac[num].cnt++;
            totalnum++;
        }
        LL ans = 1;
        for (int i = 1; i <= totalnum; i++)
            ans *= i;
        for (int i = 0; i < num; i++)
            for (int j = fac[i].cnt; j >= 1; j--)
                ans /= j;
        cout << totalnum << " " << ans << endl;
    }
}
