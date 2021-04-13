/* 跳蚱蜢 */
#include "queue"
#include "set"
#include <iostream>
using namespace std;
string st = "012345678";
string ed = "087654321";
struct state
{
    string s;
    int cnt;
    int pos0;
};
int main()
{
    // queue<state> q;
    // set<string> sett;
    // q.push({st, 0, 0});
    // int ans = 0;
    // while (q.size())
    // {
    //     state now = q.front();
    //     sett.insert(now.s);
    //     if (now.s == ed)
    //     {
    //         ans = now.cnt;
    //         break;
    //     }
    //     q.pop();
    //     int ind = now.pos0;
    //     string t = now.s;
    //     swap(t[ind], t[(ind + 1) % 9]);
    //     if (sett.find(t) == sett.end())
    //         q.push({t, now.cnt + 1, (ind + 1) % 9});
    //     t = now.s;
    //     swap(t[ind], t[(ind + 2) % 9]);
    //     if (sett.find(t) == sett.end())
    //         q.push({t, now.cnt + 1, (ind + 2) % 9});
    //     t = now.s;
    //     swap(t[ind], t[(ind - 1 + 9) % 9]);
    //     if (sett.find(t) == sett.end())
    //         q.push({t, now.cnt + 1, (ind - 1 + 9) % 9});
    //     t = now.s;
    //     swap(t[ind], t[(ind - 2 + 9) % 9]);
    //     if (sett.find(t) == sett.end())
    //         q.push({t, now.cnt + 1, (ind - 2 + 9) % 9});
    // }
    // cout << ans;
    cout << 20;
    return 0;
}
