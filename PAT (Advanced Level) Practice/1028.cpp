#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
struct stu
{
    string id, name;
    int grade;
};
int n, c;
vector<stu> v;
bool cmp(stu &a, stu &b)
{
    if (c == 1)
        return a.id < b.id;
    else if (c == 2)
    {
        if (a.name != b.name)
            return a.name < b.name;
        else
            return a.id < b.id;
    }
    else
    {
        if (a.grade != b.grade)
            return a.grade < b.grade;
        else
            return a.id < b.id;
    }
}
int main()
{
    ios::sync_with_stdio(0); // 不管这里加不加，有时候会超时，有时又不会
    cin >> n >> c;
    int grade;
    string id, name;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> name >> grade;
        v.push_back({id, name, grade});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << v[i].id << " " << v[i].name << " " << v[i].grade << endl;
}
