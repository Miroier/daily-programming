#include "iostream"
using namespace std;
const int N = 100010;
int son[N][26]; //当前节点的儿子
int idx;        //下标为0的点既是空节点，也是根节点
int cnt[N];     //计数
int n;
void insert(string s)
{
    int p = 0; //从根节点开始遍历
    for (int i = 0; i < s.size(); i++)
    {
        int u = s[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx; //没有该子结点就创建一个
        p = son[p][u];         //走到p的子结点
    }
    cnt[p]++;
}
int query(string s)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int u = s[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main()
{
    cin >> n;
    while (n--)
    {
        char op;
        string s;
        cin >> op >> s;
        if (op == 'I')
            insert(s);
        else
            cout << query(s) << endl;
    }
}
