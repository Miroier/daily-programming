#include "algorithm"
#include "iostream"
#include "map"
#include "vector"
using namespace std;
struct car
{
    string number;
    int time, status;
};
int n, k;
vector<car> tmp, v;
void inp()
{
    cin >> n >> k;
    string number, sta;
    int hh, mm, ss;
    int time;
    int status;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        scanf(" %d:%d:%d ", &hh, &mm, &ss);
        cin >> sta;
        time = hh * 3600 + mm * 60 + ss;
        status = sta == "in" ? 1 : -1;
        tmp.push_back({number, time, status});
    }
}
bool cmp1(car &a, car &b)
{
    if (a.number != b.number)
        return a.number < b.number;
    else
        return a.time < b.time;
}
bool cmp2(car &a, car &b)
{
    return a.time < b.time;
}
void work()
{
    sort(tmp.begin(), tmp.end(), cmp1);
    map<string, int> mp;
    int maxtime = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (tmp[i].number == tmp[i + 1].number && tmp[i].status == 1 && tmp[i + 1].status == -1)
        {
            v.push_back(tmp[i]);
            v.push_back(tmp[i + 1]);
            mp[tmp[i].number] += tmp[i + 1].time - tmp[i].time;
            if (maxtime < mp[tmp[i].number])
                maxtime = mp[tmp[i].number];
        }
    }
    sort(v.begin(), v.end(), cmp2);

    vector<int> cnt(n);
    cnt[0] = v[0].status;
    for (int i = 1; i < n; i++)
        cnt[i] = cnt[i - 1] + v[i].status;

    int hh, mm, ss;
    int time;
    int tmpind = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        time = hh * 3600 + mm * 60 + ss;
        int j;
        for (j = tmpind; j < v.size(); j++)
        {
            if (time < v[j].time)
            {
                cout << cnt[j - 1] << endl;
                break;
            }
            else if (j == v.size() - 1)
                cout << cnt[j] << endl;
        }
        tmpind = j;
    }
    for (auto it : mp)
    {
        if (it.second == maxtime)
            cout << it.first << " ";
    }
    printf("%02d:%02d:%02d\n", maxtime / 3600, maxtime / 60 % 60, maxtime % 60);
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
