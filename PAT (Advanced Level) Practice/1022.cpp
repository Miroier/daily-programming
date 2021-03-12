#include "iostream"
#include "map"
#include "set"
#include "vector"
using namespace std;
int n;
map<string, set<string>> mymap; //这里假设title、author这几个属性不会重名，如果重名的话就分开存，根据输入时的数字判断从哪个map里找
void inp()
{
    scanf("%d\n", &n);
    string id, title, author, key, publisher, year;
    for (int i = 0; i < n; i++)
    {
        getline(cin, id);
        getline(cin, title);
        mymap[title].insert(id);
        getline(cin, author);
        mymap[author].insert(id);
        while (cin >> key)
        {
            mymap[key].insert(id);
            char c = getchar();
            if (c == '\n')
                break;
        }
        getline(cin, publisher);
        mymap[publisher].insert(id);
        getline(cin, year);
        mymap[year].insert(id);
    }
}
int m;
void work()
{
    scanf("%d\n", &m);
    string query;
    for (int i = 0; i < m; i++)
    {
        getline(cin, query);
        cout << query << endl;
        query.erase(0, 3);
        if (mymap[query].empty())
            cout << "Not Found" << endl;
        else
        {
            for (auto it = mymap[query].begin(); it != mymap[query].end(); it++)
                cout << *it << endl;
        }
    }
}
int main()
{
    inp();
    work();
}
