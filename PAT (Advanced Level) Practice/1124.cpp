#include "iostream"
#include "set"
using namespace std;
int m, n, s;
set<string> st;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> m >> n >> s;
    string str;
    for (int i = 1; i <= m; i++)
    {
        cin >> str;
        if (i >= s && (i - s) % n == 0)
        {
            if (st.find(str) == st.end())
            {
                cout << str << endl;
                st.insert(str);
            }
            else
                s++;
        }
    }
    if (st.size() == 0)
        cout << "Keep going..." << endl;
}
