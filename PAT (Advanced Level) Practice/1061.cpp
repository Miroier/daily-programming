#include "iostream"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    string s1, s2;
    string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cin >> s1 >> s2;
    int ind = 0;
    for (ind = 0; ind < min(s1.size(), s2.size()); ind++)
        if (s1[ind] == s2[ind] && s1[ind] >= 'A' && s1[ind] <= 'G')
            break;
    cout << week[s1[ind] - 'A'] << " ";
    for (ind++; ind < min(s1.size(), s2.size()); ind++)
        if (s1[ind] == s2[ind])
            if ((s1[ind] >= 'A' && s1[ind] <= 'N') || (s1[ind] >= '0' && s1[ind] <= '9'))
                break;
    printf("%02d:", (s1[ind] >= 'A' ? s1[ind] - 'A' + 10 : s1[ind] - '0'));
    cin >> s1 >> s2;
    for (ind = 0; ind < min(s1.size(), s2.size()); ind++)
        if (s1[ind] == s2[ind])
            if ((s1[ind] >= 'A' && s1[ind] <= 'Z') || (s1[ind] >= 'a' && s1[ind] <= 'z'))
                break;
    printf("%02d", ind);
}
