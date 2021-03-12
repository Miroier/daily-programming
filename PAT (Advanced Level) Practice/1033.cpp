#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
struct sta
{
    double price;
    double dis;
};
vector<sta> v;
double cmax, d, davg;
int n;
void inp()
{
    cin >> cmax >> d >> davg >> n;
    double p, dis;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> dis;
        v.push_back({p, dis});
    }
    v.push_back({0, d}); //目的地当作一个特殊的加油站
}
bool cmp(sta &a, sta &b)
{
    return a.dis < b.dis;
}
void work()
{
    sort(v.begin(), v.end(), cmp);
    /*
        假设站点顺序是A B C
        1 如果油料不支持到下一个站，买可以支撑到B站的油料或油箱最大容量
            1.1 达到油箱最大容量，输出最大距离，结束
            1.2 未达到油箱最大距离，转2
        2 如果油料支持到下一个站，比较A站与B站的价格
            2.1 如果A站油更贵，不再购买
            2.2 如果B站油更贵，购买足够到B的油料或油箱最大容量
                2.2.1 如果C也比A贵，那么继续购买直到油箱满，后面类推
     */
    double cnow = 0;
    double maxdis = 0;
    double minpri = 0;
    if (v[0].dis > 0)
    {
        printf("The maximum travel distance = %.2lf", 0);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (cnow * davg < v[i + 1].dis - v[i].dis)
        {
            double c = (v[i + 1].dis - v[i].dis) / davg; //需要的油
            double diff;
            if (c > cmax)
            {
                diff = cmax - cnow;
                maxdis += diff * davg;
                printf("The maximum travel distance = %.2lf", maxdis);
                return;
            }
            diff = c - cnow;
            cnow += diff;
            minpri += diff * v[i].price;
            maxdis += diff * davg;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (v[j].price <= v[i].price)
                break;
            if (cnow < cmax)
            {
                double c = (v[j + 1].dis - v[j].dis) / davg; //需要的油
                double diff;
                if (c + cnow > cmax)
                    diff = cmax - cnow;
                else
                    diff = c;
                cnow += diff;
                minpri += diff * v[i].price;
                maxdis += diff * davg;
            }
        }
        cnow -= (v[i + 1].dis - v[i].dis) / davg;
    }
    printf("%.2lf", minpri);
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
