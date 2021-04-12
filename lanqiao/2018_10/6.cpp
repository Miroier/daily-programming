/* 航班时间 */
#include <iostream>
using namespace std;
int sol(string s1, string s2)
{
    int hh1, mm1, ss1, hh2, mm2, ss2, day;
    int tt1, tt2;
    sscanf(s1.c_str(), "%d:%d:%d %d:%d:%d (%d)", &hh1, &mm1, &ss1, &hh2, &mm2, &ss2, &day);
    tt1 = hh2 * 3600 + mm2 * 60 + ss2 - hh1 * 3600 - mm1 * 60 - ss1 + day * 24 * 3600;
    sscanf(s2.c_str(), "%d:%d:%d %d:%d:%d (%d)", &hh1, &mm1, &ss1, &hh2, &mm2, &ss2, &day);
    tt2 = hh2 * 3600 + mm2 * 60 + ss2 - hh1 * 3600 - mm1 * 60 - ss1 + day * 24 * 3600;
    return (tt2 + tt1) / 2;
}
int main()
{
    int T;
    cin >> T;
    getchar();
    while (T--)
    {
        string s1 = "", s2 = "";
        getline(cin, s1);
        getline(cin, s2);
        if (s1[s1.size() - 1] != ')')
            s1 += " (+0)";
        if (s2[s2.size() - 1] != ')')
            s2 += " (+0)";
        int tt = sol(s1, s2);
        printf("%02d:%02d:%02d\n", tt / 3600, tt % 3600 / 60, tt % 60);
    }
    return 0;
}
