/* 方格填数 */
#include "algorithm"
#include "vector"
#include <iostream>
using namespace std;
int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<vector<int>> v({{1, 3, 4, 5},
                       {2, 4, 5, 6},
                       {5, 6},
                       {4, 7, 8},
                       {5, 7, 8, 9},
                       {6, 8, 9},
                       {9},
                       {8},
                       {9},
                       {}});
bool check()
{
    bool flag = 1;
    for (int i = 0; i < 9; i++)
    {
        int t1 = a[i] + 1;
        int t2 = a[i] - 1;
        for (int j = 0; j < v[i].size(); j++)
            if (a[v[i][j]] == t1 || a[v[i][j]] == t2)
            {
                flag = 0;
                break;
            }
    }
    return flag;
}
int main()
{
    int ans = 0;
    do
    {
        if (check())
            ans++;
    } while (next_permutation(a, a + 10));
    cout << ans;
    return 0;
}
