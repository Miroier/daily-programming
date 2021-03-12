#include "algorithm"
#include "iostream"
#include "string"
#include "vector"
using namespace std;
struct stu
{
    string id;
    int score[4];
    int rank[4];
    int best;
};
stu v[2010];
int n, m;
int flag;
void inp()
{
    cin >> n >> m;
    string s;
    int a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].id >> v[i].score[1] >> v[i].score[2] >> v[i].score[3];
        v[i].score[0] = (v[i].score[1] + v[i].score[2] + v[i].score[3]) / 3;
    }
}
bool cmp1(stu &a, stu &b)
{
    return a.score[flag] > b.score[flag];
}
void Rank()
{
    for (flag = 0; flag < 4; flag++)
    {
        sort(v, v + n, cmp1);
        for (int i = 0; i < n; i++)
        {
            v[i].rank[flag] = i + 1;
            if (i && v[i].score[flag] == v[i - 1].score[flag])
                v[i].rank[flag] = v[i - 1].rank[flag];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int ind;
        int r = 2010;
        for (int j = 0; j < 4; j++)
            if (r > v[i].rank[j])
                r = v[i].rank[j], ind = j;
        v[i].best = ind;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%s %d %d %d %d %d %d %d %d %d\n", v[i].id.c_str(), v[i].score[0], v[i].score[1], v[i].score[2], v[i].score[3], v[i].rank[0], v[i].rank[1], v[i].rank[2], v[i].rank[3], v[i].best);
    // }
}
string mymap[4] = {"A", "C", "M", "E"};
void work()
{
    Rank();
    string t;
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        int ind = -1;
        for (int j = 0; j < n; j++)
            if (t == v[j].id)
            {
                ind = j;
                break;
            }
        if (ind != -1)
            cout << v[ind].rank[v[ind].best] << " " << mymap[v[ind].best] << endl;
        else
            cout << "N/A" << endl;
    }
}
int main()
{
    inp();
    work();
}
