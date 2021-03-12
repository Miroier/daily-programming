#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
struct stu
{
    string name, id;
    int grade;
};
vector<stu> f;
vector<stu> m;
int n;
void inp()
{
    cin >> n;
    string name, id, sex;
    int grade;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> sex >> id >> grade;
        if (sex == "F")
            f.push_back({name, id, grade});
        if (sex == "M")
            m.push_back({name, id, grade});
    }
}
bool cmp1(stu &a, stu &b)
{
    return a.grade > b.grade;
}
bool cmp2(stu &a, stu &b)
{
    return a.grade < b.grade;
}
void work()
{
    if (f.size())
    {
        sort(f.begin(), f.end(), cmp1);
        cout << f[0].name << " " << f[0].id << endl;
    }
    else
        cout << "Absent" << endl;
    if (m.size())
    {
        sort(m.begin(), m.end(), cmp2);
        cout << m[0].name << " " << m[0].id << endl;
    }
    else
        cout << "Absent" << endl;
    if (f.size() && m.size())
        cout << f[0].grade - m[0].grade;
    else
        cout << "NA";
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
