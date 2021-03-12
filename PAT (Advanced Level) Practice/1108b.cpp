#include "cstring"
#include "iostream"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    char s[50], s2[50];
    double sum = 0, tmp;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        sscanf(s, "%lf", &tmp);
        sprintf(s2, "%.2lf", tmp);
        bool flag = 0;
        for (int j = 0; j < strlen(s); j++)
            if (s[j] != s2[j])
                flag = 1;
        if (flag || tmp < -1000 || tmp > 1000)
            printf("ERROR: %s is not a legal number\n", s);
        else
            sum += tmp, cnt++;
    }
    if (cnt == 0)
        printf("The average of 0 numbers is Undefined");
    else if (cnt == 1)
        printf("The average of 1 number is %.2lf", sum);
    else
        printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
}
