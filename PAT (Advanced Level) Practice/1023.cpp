#include "cstring"
#include "iostream"
using namespace std;
int a[15];
int b[15];
int num[25];
int main()
{
    string t;
    cin >> t;
    int k = t.size();
    for (int i = 0, j = k - 1; j >= 0; i++, j--)
        num[i] = t[j] - '0';
    for (int i = 0; i < k; i++)
        a[num[i]]++;
    for (int i = 0; i < k; i++)
        num[i] *= 2;
    for (int i = 0; i < k; i++)
        num[i + 1] += num[i] / 10, num[i] %= 10;
    if (num[k])
        k++;
    for (int i = 0; i < k; i++)
        b[num[i]]++;
    bool flag = true;
    for (int i = 0; i <= 9; i++) // 0-9
        if (a[i] != b[i])
            flag = false;
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for (int i = k - 1; i >= 0; i--)
        cout << num[i];
}
