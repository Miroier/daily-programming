#include <iostream>
#include <unordered_map>
using namespace std;
const int MOD = 1e9 + 7;
using LL = long long;
int n;
LL ans = 1;
unordered_map<int, int> mp; // 存所有数乘积的分解质因子底数和指数
int main()
{
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++) // 分解质因子
            if (x % i == 0)
                while (x % i == 0)
                {
                    x /= i;
                    mp[i]++;
                }
        if (x > 1)
            mp[x]++;
    }
    for (auto t : mp)
    {
        LL tmp = 1;
        LL a = t.first, b = t.second;
        while (b--)
            tmp = (tmp * a + 1) % MOD;
        ans = (ans * tmp) % MOD;
    }
    cout << ans;
}
