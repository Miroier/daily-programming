#include "algorithm"
#include "cstdio"
#include "iostream"
#include "map"
#include "vector"
using namespace std;
int rate[25];
int n;
struct call
{
    string name;
    int month;
    int day;
    int hour;
    int minute;
    int time;
    string type;
};
vector<call> v;
void inp()
{
    for (int i = 0; i < 24; i++)
        cin >> rate[i], rate[24] += rate[i];
    cin >> n;
    string name;
    int month;
    int day;
    int hour;
    int minute;
    int time;
    string type;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        scanf("%d:%d:%d:%d", &month, &day, &hour, &minute);
        cin >> type;
        time = day * 24 * 60 + hour * 60 + minute;
        v.push_back({name, month, day, hour, minute, time, type});
    }
}
bool cmp(call &a, call &b)
{
    if (a.name != b.name)
        return a.name < b.name;
    else
        return a.time < b.time;
}
double billfromzero(call call)
{
    double sum = rate[24] * 60 * call.day + rate[call.hour] * call.minute;
    for (int i = 0; i < call.hour; i++)
        sum += rate[i] * 60;
    return sum / 100;
}
void work()
{
    sort(v.begin(), v.end(), cmp);
    map<string, vector<call>> custom;
    for (int i = 1; i < n; i++)
    {
        if (v[i].name == v[i - 1].name && v[i - 1].type == "on-line" && v[i].type == "off-line")
        {
            custom[v[i - 1].name].push_back(v[i - 1]);
            custom[v[i].name].push_back(v[i]);
        }
    }
    for (auto it : custom)
    {
        vector<call> tmp = it.second;
        cout << it.first;
        printf(" %02d\n", tmp[0].month);
        double billsum = 0;
        for (int i = 1; i < tmp.size(); i += 2)
        {
            int minsum = tmp[i].time - tmp[i - 1].time;
            double per = billfromzero(tmp[i]) - billfromzero(tmp[i - 1]);
            printf("%02d:%02d:%02d %02d:%02d:%02d", tmp[i - 1].day, tmp[i - 1].hour, tmp[i - 1].minute, tmp[i].day, tmp[i].hour, tmp[i].minute);
            printf(" %d $%.2lf\n", minsum, per);
            billsum += per;
        }
        printf("Total amount: $%.2lf\n", billsum);
    }
}
int main()
{
    inp();
    work();
}
