/* 倍数问题 */
#include "vector"
#include <iostream>
using namespace std;
const int N = 1e5 + 5, K = 1e3 + 5;
;
vector<vector<int>> v(K, vector<int>(3));
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int id = x % k;
        if (x > v[id][0])
        {
            v[id][2] = v[id][1];
            v[id][1] = v[id][0];
            v[id][0] = x;
        }
        else if (x > v[id][1])
        {
            v[id][2] = v[id][1];
            v[id][1] = x;
        }
        else if (x > v[id][2])
        {
            v[id][2] = x;
        }
    }
    int sum = 0, v1, v2, v3;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            int kk = (k - i + k - j) % k;
            v1 = v[i][0];
            if (i == j)
            {
                v2 = v[j][1];
                if (i == kk)
                {
                    v3 = v[kk][2];
                }
                else
                {
                    v3 = v[kk][0];
                }
            }
            else
            {
                v2 = v[j][0];
                if (i == kk)
                {
                    v3 = v[kk][1];
                }
                else if (j == kk)
                {
                    v3 = v[kk][1];
                }
                else
                {
                    v3 = v[kk][0];
                }
            }
            if (v1 + v2 + v3 > sum)
                sum = v1 + v2 + v3;
        }
    cout << sum;
    return 0;
}
