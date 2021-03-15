#include "iostream"
using namespace std;
string s1, s2;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> s1 >> s2;
    int n = s1.size();
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s1[i] != s2[i])
        {
            cnt++;
            s1[i] = s2[i];
            s1[i + 1] = s1[i + 1] == 'o' ? '*' : 'o';
        }
    }
    cout << cnt;
}
