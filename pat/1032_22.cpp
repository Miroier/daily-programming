#include "iostream"
#include "vector"
using namespace std;
struct node
{
    char data;
    int next;
};
node v[100000];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int s1, s2, n;
    cin >> s1 >> s2 >> n;
    int add, next;
    char data;
    for (int i = 0; i < n; i++)
    {
        cin >> add >> data >> next;
        v[add].data = data;
        v[add].next = next;
    }
    int suffix = -1;
    for (int i = s1; i != -1; i = v[i].next)
    {
        for (int j = s2; j != -1; j = v[j].next)
            if (i == j)
            {
                suffix = i;
                break;
            }
        if (suffix != -1)
            break;
    }
    if (suffix == -1)
        cout << suffix;
    else
        printf("%05d", suffix);
}
