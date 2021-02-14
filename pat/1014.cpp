#include "iostream"
#include "queue"
using namespace std;
int n, m, k, q;
int a[1010];
int b[1010];
queue<int> que[30];
int st[1010];
int ed[1010];
int times;
void inp()
{
    cin >> n >> m >> k >> q;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++)
        cin >> b[i];
}
void work()
{
    for (int i = 0, j = 0; i < n * m && i < k; i++, j++)
        que[j % n].push(i);
    for (int i = n * m, cnt = 0; cnt < k;)
    {
        int time = 10000;
        for (int j = 0; j < n; j++)
            if (!que[j].empty() && time > a[que[j].front()])
                time = a[que[j].front()];
        times += time;
        for (int j = 0; j < n; j++)
        {
            if (que[j].empty())
                continue;
            a[que[j].front()] -= time;
            if (a[que[j].front()] == 0)
            {
                ed[que[j].front()] = times;
                que[j].pop();
                cnt++;
                if (i < k)
                    que[j].push(i++);
                if (!que[j].empty())
                    st[que[j].front()] = times;
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        int res = ed[b[i] - 1];
        if (st[b[i] - 1] < 540) //开始服务时间在17:00前
            printf("%02d:%02d\n", 8 + res / 60, res % 60);
        else
            cout << "Sorry" << endl;
    }
}
int main()
{
    inp();
    work();
}
