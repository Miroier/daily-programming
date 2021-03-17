#include "iostream"
using namespace std;
/*
    假如第一个蚂蚁向右走
        右边向左走，必然被感染
        右边向右走，必然不被感染
        左边向左走，必然不被感染
        左边向右走
            右边存在向左走，则必然被感染
            右边不存在向左走，则必然不被感染
 */
int a[55];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int left = 0, right = 0; //left:->, right:<-
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i]) < abs(a[0]) && a[i] > 0)
            left++;
        if (abs(a[i]) > abs(a[0]) && a[i] < 0)
            right++;
    }
    if (a[0] > 0)
    {
        if (right == 0)
            cout << 1;
        else
            cout << left + right + 1;
    }
    else if (a[0] < 0)
    {
        if (left == 0)
            cout << 1;
        else
            cout << left + right + 1;
    }
}
