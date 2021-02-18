#include "cmath"
#include "iostream"
using namespace std;
string s;
char c[30][30]; // (80+2)/3 ~ 27
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> s;
    int N = s.size();
    N += 2;
    /*
    1. N%3==0 n1=n2=n3
    2. N%3==1 多出来的1给n2
    3. N%3==2 多出来的2给n2
     */
    int n1 = N / 3, n2 = N / 3 + N % 3;
    int n3 = n1;
    int cnt = 0;
    for (int i = 0; i < 30; i++)
        for (int j = 0; j < 30; j++)
            c[i][j] = ' ';
    for (int i = 0; i < n1; i++, cnt++)
        c[i][0] = s[cnt];
    for (int i = 1; i < n2 - 1; i++, cnt++)
        c[n1 - 1][i] = s[cnt];
    for (int i = n3 - 1; i >= 0; i--, cnt++)
        c[i][n2 - 1] = s[cnt];
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            cout << c[i][j] << (j < n2 - 1 ? "" : "\n");
}
