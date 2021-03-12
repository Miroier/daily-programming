#include "algorithm"
#include "iostream"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int a[100];
    int b[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    /*
        先判断是什么排序
        可以找b有序的部分，如果有序部分之后的部分和a完全一样，说明是插入排序
     */
    int i, j;
    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++)
        ;
    for (j = i + 1; j < n && b[j] == a[j]; j++)
        ;
    if (j == n)
    {
        cout << "Insertion Sort" << endl;
        sort(a, a + i + 2);
    }
    else
    {
        cout << "Merge Sort" << endl;
        int k = 1;
        bool flag = 1;
        while (flag)
        {
            flag = 0;
            for (int i = 0; i < n; i++)
                if (a[i] != b[i])
                    flag = 1;
            k *= 2;
            for (i = 0; i + k < n; i += k)
                sort(a + i, a + i + k);
            sort(a + i, a + n);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            cout << " ";
        cout << a[i];
    }
}
