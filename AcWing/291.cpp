#include "cstring"
#include "iostream"
#include "vector"
using namespace std;
/*
    核心：先放横着的，再放竖着的
    总方案数，等于只放横着的小方块的合法方案数
    判断合法
        剩余的位置能否填充满竖方块，可以按列来看，每一列内部所有连续的空着的小方块是偶数的1

    状态表示
        f[i,j]表示前i-1列摆好，从第i-1列伸到第i列的所有方案，j是一个二进制数，比如11001，表示1、2、5行伸出
    状态计算
        f[i,j]=f[i-1,k] k in [0,2^N-1]
 */
typedef long long LL;
const int N = 12, M = 1 << N;
LL f[N][M]; // 第一维表示列，第二维表示所有可能的状态
vector<int> state[M];
bool st[M];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    while (cin >> n >> m, n != 0 && m != 0)
    {
        // 预处理每种状态i，如果st[i]=true表示这种状态每列没有奇数个连续的0
        for (int i = 0; i < 1 << n; i++)
        {
            int cnt = 0;
            bool is_valid = true;
            for (int j = 0; j < n; j++)
                if (i & 1 << j)
                {
                    if (cnt & 1)
                    {
                        is_valid = false;
                        break;
                    }
                    cnt = 0;
                }
                else
                    cnt++;
            if (cnt & 1)
                is_valid = false;
            st[i] = is_valid;
        }
        //预处理，看第k-2列伸出来的和第k-1列伸出去的是否冲突
        for (int i = 0; i < 1 << n; i++) //对于第k-1列的所有状态，（这里k代表任意一列）
        {
            state[i].clear();
            for (int j = 0; j < 1 << n; j++) //对于第k-2列所有状态
                //如果第k-2列伸出来的 和第k-1列伸出来的不冲突(不在同一行)
                //st[]表示的是这一列没有连续奇数个0的情况
                //st[i|j]表示当前 第k-1列的到底有几个1，即哪几行是横着放格子的
                if ((i & j) == 0 && st[i | j])
                    state[i].push_back(j); //真正可行的状态，即没有连续奇数个0，也没有冲突
        }
        // dp部分
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 0; j < 1 << n; j++)
                for (auto k : state[j])
                    f[i][j] += f[i - 1][k];
        //f[m][0]表示 前m-1列都处理完，并且第m-1列没有伸出来的所有方案数。
        //即整个棋盘处理完的方案数
        cout << f[m][0] << endl;
    }
}
