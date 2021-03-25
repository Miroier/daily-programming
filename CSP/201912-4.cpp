/*
    为了避免频繁复制链表带来的时间复杂度
    可以将链表统一存储起来，每个节点存储链表的编号
 */
#include "cstring"
#include "iostream"
#include "queue"
#include "sstream"
#include "vector"
using namespace std;
const int N = 505, M = 20005;
int h[N], e[M], ne[M], idx; //存图
int n, m;
int w, k;
vector<vector<int>> g; //存链表
int node[N];           //存储每个点对应的链表的编号
struct Op
{
    int t, id, pid, hid; //id:更新哪个节点 pid:从哪个节点过来 hid:过来链表的编号
    bool friend operator<(Op a, Op b)
    {
        return a.t > b.t; //小根堆
    }
};
priority_queue<Op> heap;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void eval()
{
    Op t = heap.top();
    heap.pop();
    vector<int> &a = g[node[t.id]], &b = g[t.hid];
    if (b.size() > a.size() || (b.size() == a.size() && b.back() < a.back()))
    {
        node[t.id] = t.hid;
        for (int i = h[t.id]; ~i; i = ne[i])
            if (e[i] != t.pid && e[i] != t.id)
                heap.push({t.t + w, e[i], t.id, node[t.id]});
    }
}
int main()
{
    cin >> n >> m;
    g.push_back({0}); //node[N]初始都是0，所以会指向 0 这个链表
    memset(h, -1, sizeof h);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    cin >> w >> k;
    getchar();
    char str[100];
    while (k--)
    {
        fgets(str, 100, stdin);
        stringstream ssin(str);
        int a[3], cnt = 0;
        while (ssin >> a[cnt])
            cnt++;
        if (cnt == 3)
        {
            while (heap.size() && heap.top().t <= a[1])
                eval();
            g.push_back(g[node[a[0]]]); //复制
            g.back().push_back(a[2]);   //更新链表
            node[a[0]] = g.size() - 1;  //更新节点记录的链表编号
            for (int i = h[a[0]]; ~i; i = ne[i])
                if (e[i] != a[0]) //防止自环
                    heap.push({a[1] + w, e[i], a[0], node[a[0]]});
        }
        else
        {
            while (heap.size() && heap.top().t <= a[1])
                eval();
            printf("%d ", g[node[a[0]]].size());
            for (auto x : g[node[a[0]]])
                printf("%d ", x);
            cout << endl;
        }
    }
}
