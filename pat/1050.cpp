#include "iostream"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s2.size(); i++)
    {
        char c = s2[i];
        int pos = 0;
        while (pos = s1.find(c), pos != string::npos)
            s1.erase(pos, 1);
    }
    cout << s1;
}
