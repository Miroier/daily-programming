#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
int n, k, m;
struct stu
{
    int id;
    int score[6] = {-1, -1, -1, -1, -1, -1};
    int total;
    int rank;
    int cnt;  //完美解决
    int flag; //是否都是-1
};
int q[6];
vector<stu> v;
void inp()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++)
        cin >> q[i];
    int id, ques, score;
    v.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> id >> ques >> score;
        v[id].id = id;
        v[id].score[ques] = max(v[id].score[ques], score);
        if (score != -1)
            v[id].flag = true;
        else if (v[id].score[ques] == -1)
            v[id].score[ques] = -2;
    }
}
bool cmp(stu &a, stu &b)
{
    if (a.total != b.total)
        return a.total > b.total;
    else if (a.cnt != b.cnt)
        return a.cnt > b.cnt;
    return a.id < b.id;
}
void work()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (v[i].score[j] > 0)
                v[i].total += v[i].score[j];
            if (v[i].score[j] == q[j])
                v[i].cnt++;
        }
    }
    sort(v.begin() + 1, v.begin() + n + 1, cmp);

    v[1].rank = 1;
    for (int i = 2; i < v.size(); i++)
    {
        v[i].rank = i;
        if (v[i].total == v[i - 1].total)
            v[i].rank = v[i - 1].rank;
    }
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].flag)
        {
            printf("%d %05d %d", v[i].rank, v[i].id, v[i].total);
            for (int j = 1; j <= k; j++)
            {
                if (v[i].score[j] != -1 && v[i].score[j] != -2)
                    printf(" %d", v[i].score[j]);
                else if (v[i].score[j] == -1)
                    printf(" -");
                else
                    printf(" 0");
            }
            puts("");
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
