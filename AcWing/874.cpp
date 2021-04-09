#include "iostream"
using namespace std;
typedef long long LL;
const int N = 1000005;
int prime[N], cnt;
int phi[N]; //欧拉函数
bool st[N];
LL get_eulers(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            prime[cnt++] = i;
            phi[i] = i - 1; //质数i的欧拉函数就是i-1
        }
        for (int j = 0; prime[j] <= n / i; j++)
        {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0)
            {
                //prime[j]是i的一个质因子，欧拉函数的值只和质因子是否出现有关，和质因子出现的次数无关
                //所以有下面这个式子
                phi[prime[j] * i] = prime[j] * phi[i];
                break;
            }
            //如果不是质因子，等号左边多了prime[j]这个质因子，值要额外乘上(1-1/prime[j])这一项
            phi[prime[j] * i] = (prime[j] - 1) * phi[i];
        }
    }
    LL res = 0;
    for (int i = 1; i <= n; i++)
        res += phi[i];
    return res;
}
int main()
{
    int n;
    cin >> n;
    cout << get_eulers(n) << endl;
}
