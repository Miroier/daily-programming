#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
struct peo
{
    string name;
    int age;
    int worth;
};
int n, k, m;
vector<peo> v;
void inp()
{
    cin >> n >> k;
    string name;
    int age, worth;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> age >> worth;
        v.push_back({name, age, worth});
    }
}
bool cmp(peo &a, peo &b)
{
    if (a.worth != b.worth)
        return a.worth > b.worth;
    else if (a.age != b.age)
        return a.age < b.age;
    return a.name < b.name;
}
void work()
{
    sort(v.begin(), v.end(), cmp);
    int mxnum, low, high;
    for (int i = 1; i <= k; i++)
    {
        cin >> mxnum >> low >> high;
        int cnt = 0;
        printf("Case #%d:\n", i);
        for (auto it = v.begin(); it != v.end(); it++)
        {
            if (it->age >= low && it->age <= high)
            {
                printf("%s %d %d\n", it->name.c_str(), it->age, it->worth);
                cnt++;
            }
            if (cnt == mxnum)
                break;
        }
        if (!cnt)
            cout << "None" << endl;
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    inp();
    work();
}
