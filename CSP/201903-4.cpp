#include "iostream"
#include "sstream"
#include "vector"
using namespace std;
const int N = 10005;
struct node
{
    bool type; //1:R 0:S
    int x;
};
int t, n;
vector<node> v[N];
bool work()
{
    bool flag = 1;
    while (flag)
    {
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i].size())
            {
                int ind = v[i][0].x;
                if (!v[ind].size())
                    return 1;
                if ((v[ind][0].x == i) && (v[ind][0].type ^ v[i][0].type))
                {
                    flag = 1;
                    v[i].erase(v[i].begin());
                    v[ind].erase(v[ind].begin());
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (v[i].size())
            return 1;
    return 0;
}
int string2int(string s)
{
    int x;
    stringstream ss;
    ss << s;
    ss >> x;
    return x;
}
int main()
{
    cin >> t >> n;
    getchar();
    while (t--)
    {
        for (int i = 0; i < N; i++)
            v[i].clear();
        for (int i = 0; i < n; i++)
        {
            string s;
            getline(cin, s);
            stringstream ssin(s);
            while (ssin >> s)
                v[i].push_back({s[0] == 'R', string2int(s.substr(1))});
        }
        cout << work() << endl;
    }
}
