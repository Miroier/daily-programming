#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], s[N]; // s[N]记录每个数出现的次数，判重

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        s[a[i]]++; // a[i]出现次数加1
        while (s[a[i]] > 1)
        { //如果a[i]出现次数大于1，说明目前的序列有重复，删除掉j指向的元素，并且j++
            s[a[j]]--;
            j++;
        }
        //目前序列没有重复的元素，计算序列长度
        res = max(res, i - j + 1);
    }
    cout << res;
}
