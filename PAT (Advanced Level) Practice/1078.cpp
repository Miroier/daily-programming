#include "algorithm"
#include "cmath"
#include "iostream"
using namespace std;
int size, n;
bool hashTable[10010];
// bool is_prime[10010];
// int prime[10010];
int cnt = 0;
// void Prime(int n)
// {
//     for (int i = 2; i <= n; i++)
//         is_prime[i] = true;
//     for (int i = 2; i <= n; i++)
//     {
//         if (is_prime[i])
//         {
//             prime[cnt++] = i;
//             for (int j = i * i; j <= n; j += i)
//                 is_prime[j] = false;
//         }
//     }
// }
void insert(int key)
{
    // 平方探测法
    for (int step = 0; step < size; step++)
    {
        int index = (key + step * step) % size;
        if (hashTable[index] == 0)
        {
            hashTable[index] = 1;
            cout << index;
            return;
        }
    }
    cout << '-';
}
bool IsPrime(int n)
{
    if (n == 1)
        return false;
    int sqr = sqrt(n);
    for (int i = 2; i <= sqr; i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> size >> n;
    // 后面两个点会错，原因不明
    // Prime(10000);
    // int *p = lower_bound(prime, prime + cnt, size);
    // size = *p;
    while (!IsPrime(size))
        size++;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insert(x);
        if (i < n - 1)
            cout << " ";
    }
}
