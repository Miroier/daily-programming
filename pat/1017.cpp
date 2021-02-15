#include "algorithm"
#include "cstdio"
#include "iostream"
#include "queue"
using namespace std;
struct person
{
    int st, time;
} p[10010];
int n, k;
int cnt;
double total;
priority_queue<int, vector<int>, greater<int>> pq;
bool cmp(person &a, person &b)
{
    return a.st < b.st;
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int hh, mm, ss, tt;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &tt);
        int sum = hh * 3600 + mm * 60 + ss;
        if (sum > 61200)
            continue;
        p[cnt].time = tt * 60;
        p[cnt++].st = sum;
    }
    sort(p, p + cnt, cmp);
    for (int i = 0; i < k; i++)
        pq.push(28800);
    for (int i = 0; i < cnt; i++)
        if (p[i].st >= pq.top())
        {
            pq.push(p[i].st + p[i].time);
            pq.pop();
        }
        else
        {
            total += pq.top() - p[i].st;
            pq.push(pq.top() + p[i].time);
            pq.pop();
        }
    printf("%.1lf", total / 60 / cnt);
}
