#include "algorithm"
#include "iostream"
using namespace std;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    string n;
    cin >> n;
    n.insert(0, 4 - n.size(), '0'); //需要加这句
    do
    {
        sort(n.begin(), n.end());
        int x = stoi(n);
        reverse(n.begin(), n.end());
        int y = stoi(n);
        printf("%04d - %04d = %04d\n", y, x, y - x);
        n = to_string(y - x);
        n.insert(0, 4 - n.size(), '0');
    } while (n != "0000" && n != "6174");
}
