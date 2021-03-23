#include "iostream"
#include "vector"
using namespace std;
struct node
{
    int x;
    int ind;
};
vector<node> v;
int n;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    getchar();
    int ind = 1;
    char c;
    int k, x;
    while (n--)
    {
        scanf(" %c", &c);
        if (c == 'H')
        {
            scanf("%d", &x);
            v.insert(v.begin(), {x, ind++});
        }
        if (c == 'I')
        {
            scanf("%d%d", &k, &x);
            for (auto it = v.begin(); it != v.end(); it++)
                if (it->ind == k)
                {
                    v.insert(it + 1, {x, ind++});
                    break;
                }
        }
        if (c == 'D')
        {
            scanf("%d", &k);
            if (k == 0)
                v.erase(v.begin());
            else
                for (auto it = v.begin(); it != v.end(); it++)
                    if (it->ind == k)
                    {
                        v.erase(it + 1);
                        break;
                    }
        }
        // for (int i = 0; i < v.size(); i++)
        //     cout << v[i].x << "_" << v[i].ind << " ";
        // cout << endl;
    }
    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i].x);
}
