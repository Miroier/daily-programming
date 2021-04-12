/* 第几个幸运数 */
#include "algorithm"
#include "set"
#include <iostream>
using namespace std;
typedef long long LL;
set<LL> st;
int main()
{
    LL a[3] = {3, 5, 7};
    st.insert(3);
    st.insert(5);
    st.insert(7);
    LL tt = 1;
    LL cnt = 0;
    while (1)
    {
        tt = *upper_bound(st.begin(), st.end(), tt);
        if (tt > 59084709587505)
            break;
        cnt++;
        st.insert(tt * a[0]);
        st.insert(tt * a[1]);
        st.insert(tt * a[2]);
    }
    cout << cnt;
    return 0;
}
