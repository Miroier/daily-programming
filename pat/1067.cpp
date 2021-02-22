#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
/*
    1 如果0不在0位在i位，那么将0和i所在的位置进行交换
    2 如果0在0位，查找有无数字i不在第i位的，如果有则将第一个符合要求的数和0进行交换，没有则结束
 */
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    vector<int> pos;
    int cnt = 0;
    cin >> n;
    pos.resize(n);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pos[x] = i; //表示x的位置是i
    }
    int index = 1; //这里需要放在外面，否则会超时两个点
    while (true)
    {
        while (pos[0] != 0)
        {
            swap(pos[0], pos[pos[0]]); //pos[pos[0]]表示应该在pos[0]的数的位置，比如pos[0]=7，那就是7的位置
            cnt++;
        }
        for (; index < n; index++)
            if (pos[index] != index)
            {
                swap(pos[0], pos[index]);
                cnt++;
                break;
            }
        if (index == n)
            break;
    }

    cout << cnt;
}
