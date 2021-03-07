#include "iostream"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        int t = s.size() / 2;
        int z = stoi(s);
        int a = stoi(s.substr(0, t));
        int b = stoi(s.substr(t));
        if (b == 0)
            puts("No");
        else if (z % (a * b) == 0)
            puts("Yes");
        else
            puts("No");
    }
}
