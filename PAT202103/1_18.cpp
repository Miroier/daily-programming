#include "iostream"
#include "vector"
using namespace std;
int n, maxn;
// int prime[100005];
// bool isprime[100005];
// int cnt = 0;
// void Pirme(int x)
// {
//     for (int i = 0; i <= x; i++)
//         isprime[i] = true;
//     isprime[0] = isprime[1] = false;
//     for (int i = 2; i <= x; i++)
//     {
//         if (isprime[i])
//             prime[cnt++] = i;
//         for (int j = i * i; j <= x; j += i)
//             isprime[j] = false;
//     }
// }
bool isprime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
void inp()
{
    cin >> n >> maxn;
    // Pirme(maxn);
}
int mxfirst, mxdiff;
vector<int> ans;
void work()
{
    for (int diff = maxn / 2; diff >= 2; diff--)
    {
        bool flag = 0;
        for (int first = 1; first + diff * (n - 1) <= maxn; first++)
        {
            vector<int> tmp;
            for (int i = 0; i < n; i++)
            {
                int num = first + diff * i;
                if (num > maxn)
                    break;
                if (!isprime(num))
                    break;
                tmp.push_back(num);
            }
            if (tmp.size() == n)
            {
                flag = 1;
                if (mxfirst < first)
                {
                    mxfirst = first;
                    ans = tmp;
                }
            }
        }
        if (flag == 1)
            break;
    }
    if (ans.size() == 0)
    {
        for (int i = maxn; i >= 2; i--)
            if (isprime(i))
            {
                cout << i;
                break;
            }
    }
    else
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << (i < ans.size() - 1 ? " " : "\n");
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    inp();
    work();
}
