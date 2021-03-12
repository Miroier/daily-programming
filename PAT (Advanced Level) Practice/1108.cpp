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
    string s;
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        try
        {
            double x = stod(s);
            bool flag = false;
            if (x > 1000 || x < -1000)
                flag = true;
            int pos = s.find('.');
            if (pos != string::npos && s.size() - pos > 3)
                flag = true;
            if (flag)
                printf("ERROR: %s is not a legal number\n", s.c_str());
            else
                sum += x, cnt++;
        }
        catch (const std::exception &e)
        {
            printf("ERROR: %s is not a legal number\n", s.c_str());
            continue;
        }
    }
    if (cnt == 0)
        printf("The average of 0 numbers is Undefined");
    else if (cnt == 1)
        printf("The average of 1 number is %.2lf", sum);
    else
        printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
}
