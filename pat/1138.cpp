#include "iostream"
#include "vector"
using namespace std;
vector<int> in, pre, post;
int cnt = 1;
void getPost(int preL, int preR, int inL, int inR)
{
    if (preL > preR)
        return;
    int i = inL;
    while (i < inR && in[i] != pre[preL])
        i++;
    getPost(preL + 1, preL + (i - inL), inL, i - 1);
    getPost(preL + (i - inL) + 1, preR, i + 1, inR);
    post[cnt++] = pre[preL];
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    pre.resize(n + 1);
    in.resize(n + 1);
    post.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> pre[i];
    for (int i = 1; i <= n; i++)
        cin >> in[i];
    getPost(1, n, 1, n);
    cout << post[1];
}
