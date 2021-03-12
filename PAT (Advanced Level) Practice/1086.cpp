#include "iostream"
#include "stack"
#include "vector"
using namespace std;
int n;
vector<int> pre, in, post;
stack<int> st;
/*
    push顺序是中序，pop顺序是前序
    相当于是已知前中序转后序
*/
void inp()
{
    cin >> n;
    getchar();
    string s;
    int x;
    for (int i = 0; i < n * 2; i++)
    {
        cin >> s;
        if (s == "Push")
        {
            cin >> x;
            pre.push_back(x);
            st.push(x);
        }
        else
        {
            in.push_back(st.top());
            st.pop();
        }
    }
}
void postorder(int root, int start, int end)
{
    if (start > end)
        return;
    int i = start;
    while (i < end && in[i] != pre[root])
        i++;
    postorder(root + 1, start, i - 1);
    postorder(root + i - start + 1, i + 1, end);
    post.push_back(pre[root]);
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    inp();
    postorder(0, 0, n - 1);
    for (int i = 0; i < post.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << post[i];
    }
}
