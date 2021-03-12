#include "algorithm"
#include "iostream"
#include "map"
#include "vector"
using namespace std;
/*
    输出时间时要用%06d，否则错两个点
 */
struct peo
{
    string card;
    char level;
    int testSiteNumber;
    int testDate;
    int testee;
    int score;
};
int n, m;
vector<peo> v;
void inp()
{
    cin >> n >> m;
    string s;
    char level;
    int testSiteNumber;
    int testDate;
    int testee;
    int score;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> score;
        level = s[0];
        testSiteNumber = stoi(s.substr(1, 3));
        testDate = stoi(s.substr(4, 6));
        testee = stoi(s.substr(10));
        v.push_back({s, level, testSiteNumber, testDate, testee, score});
    }
}
bool cmp1(peo &a, peo &b)
{
    if (a.score != b.score)
        return a.score > b.score;
    return a.card < b.card;
}
bool cmp3(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}
void work()
{
    int type;
    for (int i = 1; i <= m; i++)
    {
        cin >> type;
        vector<peo> tmp;
        if (type == 1)
        {
            char level;
            cin >> level;
            for (auto x : v)
                if (x.level == level)
                    tmp.push_back(x);
            printf("Case %d: %d %c\n", i, type, level);
            if (tmp.size() == 0)
            {
                cout << "NA" << endl;
                continue;
            }
            sort(tmp.begin(), tmp.end(), cmp1);
            for (auto x : tmp)
                printf("%s %d\n", x.card.c_str(), x.score);
        }
        else if (type == 2)
        {
            int testSiteNumber;
            cin >> testSiteNumber;
            int cnt = 0, sum = 0;
            for (auto x : v)
                if (x.testSiteNumber == testSiteNumber)
                    cnt++, sum += x.score;
            printf("Case %d: %d %03d\n", i, type, testSiteNumber);
            if (cnt == 0)
            {
                cout << "NA" << endl;
                continue;
            }
            printf("%d %d\n", cnt, sum);
        }
        else if (type == 3)
        {
            map<int, int> mp;
            int testDate;
            cin >> testDate;
            for (auto x : v)
                if (x.testDate == testDate)
                    mp[x.testSiteNumber]++;
            vector<pair<int, int>> tmp;
            for (auto x : mp)
                tmp.push_back(x);
            printf("Case %d: %d %06d\n", i, type, testDate);
            if (tmp.size() == 0)
            {
                cout << "NA" << endl;
                continue;
            }
            sort(tmp.begin(), tmp.end(), cmp3);
            for (auto x : tmp)
                printf("%03d %d\n", x.first, x.second);
        }
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
