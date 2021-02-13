#include "iostream"
using namespace std;

int main()
{
    double sum = 1;
    string s[3] = {"W", "T", "L"};
    for (int i = 0; i < 3; i++)
    {
        double x;
        double r = 0;
        int ind;
        for (int j = 0; j < 3; j++)
        {
            cin >> x;
            if (r < x)
                r = x, ind = j;
        }
        cout << s[ind] << " ";
        sum *= r;
    }
    printf("%.2lf", (sum * 0.65 - 1) * 2);
}
