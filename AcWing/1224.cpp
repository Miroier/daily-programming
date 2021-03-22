#include "algorithm"
#include "iostream"
using namespace std;
/*
    这里单纯想着用插入排序做了，没有考虑正确性
    正解是：
    可以将原数组看成若干个环
    例如
    ind: 1 2 3 4 5
    val: 2 1 3 5 4
    定义边为：一个数指向它应该在的位置上的数，例如2指向1，1指向2，3指向自己
    所以可以得到3个环，分别是：
    2->1->2
    3->3
    5->4->5
    我们的目标是：每个点都指向自己，即有n个环
    对于交换，有两种情况
    1 如果交换的点在一个环上
        裂成两个环
    2 如果交换的点不在一个环上
        合并两个环
    那么结果就明显了，假如输入有k个环，那么应该裂开n-k次
 */
const int N = 10005;
int a[N];
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
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == i)
            continue;
        int j = i + 1;
        while (a[j] != i)
            j++;
        swap(a[i], a[j]);
        cnt++;
    }
    cout << cnt;
}
