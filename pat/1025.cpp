#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
struct stu
{
    string id;
    int score;
    int final_rank;
    int location_number;
    int local_rank;
};
int n, k;
vector<stu> res;
vector<stu> tmp;
bool cmp(stu &a, stu &b)
{
    if (a.score != b.score)
        return a.score > b.score;
    return a.id < b.id;
}
int main()
{
    cin >> n;
    for (int j = 1; j <= n; j++)
    {
        cin >> k;
        string id;
        int score;
        tmp.clear();
        while (k--)
        {
            getchar();
            cin >> id >> score;
            tmp.push_back({id, score, 0, j, 0});
        }
        sort(tmp.begin(), tmp.end(), cmp);
        for (int i = 0; i < tmp.size(); i++)
        {
            tmp[i].local_rank = i + 1;
            if (i > 0 && tmp[i].score == tmp[i - 1].score) //注意i>0
                tmp[i].local_rank = tmp[i - 1].local_rank;
            res.push_back(tmp[i]);
        }
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i++)
    {
        res[i].final_rank = i + 1;
        if (i > 0 && res[i].score == res[i - 1].score)
            res[i].final_rank = res[i - 1].final_rank;
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i].id << " " << res[i].final_rank << " " << res[i].location_number << " " << res[i].local_rank << endl;
}
