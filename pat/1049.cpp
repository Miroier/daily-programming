#include "iostream"
using namespace std;
int n;
int cnt;
/*
    假设now为当前位的数字，left是高位到now+1的数，right是now-1到低位的数
    a表示现在的位，例如a=1表示个位，a=10表示十位
    遍历每一位，将每一位贡献的1的数量累加
    有以下几种情况
    1 now==0
        此时now位会出现1的情况是
        1.1 左边为0~left-1，共left次，右边为0~9xxx，出现a次
            ans+=left*a
    2 now==1
        此时now位会出现1的情况是
        2.1 左边为0~left-1，共left次，右边为0~9xxx，出现a次
            ans+=left*a
        2.2 左边为left，共1次，右边为0~right，共right+1次
            ans+=right+1
        共ans+=left*a+right+1
    3 now>=2
        此时now位会出现1的情况是
        3.1 左边为0~left，共left次，右边为0~9xxx，出现a次
            ans+=(left+1)*a
    下面以1030为例，已知答案是344
    从高位到低位(反过来也行)
    千位为1，left=0，right=30，a=1000
        ans+= 31
    百位为0，left=1，right=30，a=100
        ans+= 100=1*100
    十位为3，left=10，right=0，a=10
        ans+= 110=11*10
    个位为0，left=103，right=0，a=1
        ans+= 103
    ans=344
 */
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    int a = 1;
    int ans = 0;
    while (n / a)
    {
        int left = n / (a * 10), right = n % a;
        int now = n % (a * 10) / a;
        if (now == 0)
            ans += left * a;
        else if (now == 1)
            ans += left * a + right + 1;
        else
            ans += (left + 1) * a;
        a *= 10;
    }
    cout << ans;
}
