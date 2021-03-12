#include "iostream"
using namespace std;
int r, g, b;
int a[5];
void dec213(int x)
{
    a[0] = x % 13;
    a[1] = x / 13;
    for (int i = 1; i >= 0; i--)
        printf("%c", (a[i] > 9 ? 'A' + a[i] - 10 : a[i] + '0'));
}
int main()
{
    cin >> r >> g >> b;
    cout << "#";
    dec213(r);
    dec213(g);
    dec213(b);
}
