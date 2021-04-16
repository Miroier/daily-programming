#include "cmath"
#include <iostream>
using namespace std;
int main()
{
    int n = 1000;
    for (int a = 1; a * a <= n; a++)
        for (int b = a; a * a + b * b <= n; b++)
        {
            int cc = n - a * a - b * b;
            int c = sqrt(cc);
            if (c * c == cc)
            {
                if (a + b + c == 44)
                    continue;
                cout << min(a, c);
                return 0;
            }
        }
    return 0;
}
