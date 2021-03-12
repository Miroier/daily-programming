#include "iostream"
#include "map"
using namespace std;
string ge[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string shi[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int n;
map<string, int> s2i;
void inp()
{
    for (int i = 0; i < 13; i++)
        s2i[ge[i]] = i;
    for (int i = 0; i < 13; i++)
        s2i[shi[i]] = i * 13;
    cin >> n;
    getchar();
    string tmp;
    int x;
    for (int i = 0; i < n; i++)
    {
        getline(cin, tmp);
        if (tmp[0] >= '0' && tmp[0] <= '9')
        {
            x = stoi(tmp);
            if (x / 13)
                cout << shi[x / 13];
            if (x / 13 && x % 13)
                cout << " ";
            if (x % 13)
                cout << ge[x % 13];
            if (x == 0)
                cout << "tret";
            cout << endl;
        }
        else
        {
            if (tmp.size() > 3)
            {
                string s1, s2;
                s1 = tmp.substr(0, 3);
                s2 = tmp.substr(4, 3);
                cout << s2i[s1] + s2i[s2] << endl;
            }
            else
            {
                cout << s2i[tmp] << endl;
            }
        }
    }
}
void work()
{
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    inp();
}
