#include "iostream"
using namespace std;
int main()
{
    int n;
    int w, score;
    int sum = 0;
    cin >> n;
    while (n--)
    {
        cin >> w >> score;
        sum += w * score;
    }
    cout << max(0, sum) << endl;
    return 0;
}
