#include "algorithm"
#include "cmath"
#include "iostream"
#include "vector"
using namespace std;
int N;
vector<int> v;
int mat[1010][1010];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> N;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++)
        scanf("%d", &v[i]);
    sort(v.begin() + 1, v.end(), cmp);
    int n, m;
    for (n = sqrt(double(N)); n >= 1; n--)
    {
        if (N % n == 0)
        {
            m = N / n;
            break;
        }
    }
    /*  测试点1 3超时
    int n = sqrt(N);
    int m = N / n; */
    int ind = 1;
    int cnt = 1;
    while (ind <= N)
    {
        for (int i = cnt; i <= n - cnt + 1 && ind <= N; i++)
            mat[cnt][i] = v[ind++];
        for (int i = cnt + 1; i <= m - cnt + 1 && ind <= N; i++)
            mat[i][n - cnt + 1] = v[ind++];
        for (int i = n - cnt; i >= cnt && ind <= N; i--)
            mat[m - cnt + 1][i] = v[ind++];
        for (int i = m - cnt; i >= cnt + 1 && ind <= N; i--)
            mat[i][cnt] = v[ind++];
        cnt++;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j != 1)
                printf(" ");
            printf("%d", mat[i][j]);
        }
        puts("");
    }
}
