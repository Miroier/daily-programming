#include "algorithm"
#include "cmath"
#include "iostream"
#include "vector"
using namespace std;
const int INF = 0x7fffffff;
struct custom
{
    int time, p, vip; //到达时间，服务时长，vip
    int served;       //服务开始时间
};
struct table
{
    int num;
    int vip;
    int endtime = 8 * 3600;
};
int n, k, m;
vector<custom> cus;
vector<table> tab;
bool cmp1(custom &a, custom &b)
{
    return a.time < b.time;
}
bool cmp2(custom &a, custom &b)
{
    return a.served < b.served;
}
void inp()
{
    cin >> n;
    int hh, mm, ss;
    int p, vip;
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &p, &vip);
        int time = hh * 3600 + mm * 60 + ss;
        if (time >= 21 * 3600)
            continue;
        p = (p <= 120) ? p * 60 : 120 * 60;
        cus.push_back({time, p, vip, 21 * 3600});
    }
    cin >> k >> m;
    tab.resize(k + 1);
    int x;
    for (int i = 1; i <= m; i++)
        cin >> x, tab[x].vip = 1;
}
void allocate(int cnt, int index)
{
    if (cus[cnt].time < tab[index].endtime)
        cus[cnt].served = tab[index].endtime;
    else
        cus[cnt].served = cus[cnt].time;
    tab[index].endtime = cus[cnt].served + cus[cnt].p;
    tab[index].num++;
}
int findnextvip(int vipid)
{
    vipid++;
    for (; vipid < cus.size(); vipid++)
        if (cus[vipid].vip)
            break;
    return vipid;
}
void work()
{
    sort(cus.begin(), cus.end(), cmp1);
    int time;
    int cnt = 0, vipid = -1;
    vipid = findnextvip(vipid);
    while (cnt < cus.size())
    {
        int index = 0, minendtime = INF;
        for (int j = 1; j <= k; j++)
            if (tab[j].endtime < minendtime)
                minendtime = tab[j].endtime, index = j;
        if (tab[index].endtime >= 21 * 3600)
            break;
        /*
            1 第一个空闲桌子是vip
                1.1 如果队列中有vip,分配给他
                    1.1.1 第一个是vip，直接分配
                    1.1.2 第一个不是vip，分给下一个vip，vip的位置用vipid维护
                1.2 否则分给队列中第一个
            2 第一个桌子不是vip
                2.1 如果队列第一个不是vip，直接分配
                2.2 如果是vip，判断vip到达的时间和vip桌子的空闲时间
                    2.2.1 如果vip到达的时间 >= vip桌子的空闲时间，此时和1.1.1一样
                    2.2.2 如果vip达到的时间 < vip桌子的空闲时间，进行分配，并更新vipid
        */
        //  3 在1.1.2中，vip会优先拿出来，因此可能循环到cnt时，他已经被分配过了，跳过这一个
        if (cus[cnt].vip == true && cnt < vipid)
        {
            cnt++;
            continue;
        }
        if (tab[index].vip)
        {
            if (cus[cnt].vip)
            {
                allocate(cnt, index);
                if (vipid == cnt)
                    vipid = findnextvip(vipid);
                cnt++;
            }
            else
            {
                if (vipid < cus.size() && cus[vipid].time <= tab[index].endtime)
                {
                    allocate(vipid, index);
                    vipid = findnextvip(vipid);
                }
                else
                {
                    allocate(cnt, index);
                    cnt++;
                }
            }
        }
        else
        {
            if (!cus[cnt].vip)
            {
                allocate(cnt, index);
                cnt++;
            }
            else
            {
                // 找第一个空闲的vip桌子
                int vipindex = -1, minvipendtime = INF;
                for (int j = 1; j <= k; j++)
                    if (tab[j].vip && tab[j].endtime < minvipendtime)
                        vipindex = j, minvipendtime = tab[j].endtime;
                // 如果存在vip桌子 并且 vip到达的时间 >= vip桌子的空闲时间
                if (vipindex != -1 && cus[cnt].time >= tab[vipindex].endtime)
                {
                    allocate(cnt, vipindex);
                    if (vipid == cnt)
                        vipid = findnextvip(vipid);
                    cnt++;
                }
                // 如果不存在vip桌子 或者 存在vip桌子但是vip达到的时间 < vip桌子的空闲时间
                else
                {
                    allocate(cnt, index);
                    if (vipid == cnt)
                        vipid = findnextvip(vipid);
                    cnt++;
                }
            }
        }
    }
    sort(cus.begin(), cus.end(), cmp2);
    for (int i = 0; i < cus.size() && cus[i].served < 21 * 3600; i++)
    {
        printf("%02d:%02d:%02d ", cus[i].time / 3600, cus[i].time % 3600 / 60, cus[i].time % 60);
        printf("%02d:%02d:%02d ", cus[i].served / 3600, cus[i].served % 3600 / 60, cus[i].served % 60);
        printf("%.0f\n", round((cus[i].served - cus[i].time) / 60.0));
    }
    for (int i = 1; i <= k; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", tab[i].num);
    }
    puts("");
}
int main()
{
    inp();
    work();
}
