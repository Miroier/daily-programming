#include "iostream"
using namespace std;
int w, m, n;
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> w >> m >> n;
    m--, n--; //编号从0开始，方便取余操作
    int x1 = m / w;
    int y1 = (x1 % 2 == 0 ? m % w : w - m % w - 1);
    int x2 = n / w;
    int y2 = (x2 % 2 == 0 ? n % w : w - n % w - 1);
    cout << abs(x1 - x2) + abs(y1 - y2) << endl;
}
