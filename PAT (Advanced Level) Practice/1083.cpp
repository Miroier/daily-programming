#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
struct stu
{
    string name;
    string id;
    int grade;
};
int n;
int low, high;
vector<stu> v;
bool cmp(stu &a, stu &b)
{
    return a.grade > b.grade;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    getchar();
    string name, id;
    int grade;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> id >> grade;
        v.push_back({name, id, grade});
    }
    cin >> low >> high;
    sort(v.begin(), v.end(), cmp);
    bool flag = 0;
    for (int i = 0; i < v.size(); i++)
        if (v[i].grade >= low && v[i].grade <= high)
        {
            cout << v[i].name << " " << v[i].id << endl;
            flag = 1;
        }
    if (!flag)
        cout << "NONE";
}
