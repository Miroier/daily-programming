#include "algorithm"
#include "iostream"
using namespace std;
struct stu
{
    string name;
    int in;
    int out;
};
stu a[110];
int m;
void inp()
{
    cin >> m;
    int hh, mm, ss;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].name;
        cin >> hh;
        getchar();
        cin >> mm;
        getchar();
        cin >> ss;
        a[i].in = hh * 3600 + mm * 60 + ss;
        cin >> hh;
        getchar();
        cin >> mm;
        getchar();
        cin >> ss;
        a[i].out = hh * 3600 + mm * 60 + ss;
    }
}
bool cmp1(stu &a, stu &b)
{
    return a.in < b.in;
}
bool cmp2(stu &a, stu &b)
{
    return a.out > b.out;
}
void work()
{
    sort(a, a + m, cmp1);
    cout << a[0].name << " ";
    sort(a, a + m, cmp2);
    cout << a[0].name;
}
int main()
{
    inp();
    work();
}
