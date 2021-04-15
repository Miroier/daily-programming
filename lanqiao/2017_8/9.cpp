#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, k;
int h[N], w[N];
bool check(int x)
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += (h[i] / x) * (w[i] / x);
  // cout<< x<<" "<<cnt<<endl;
  return cnt >= k;
}
int main()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> h[i] >> w[i];
  int left = 1, right = 1e5;
  while (left < right)
  {
    int mid = left + right + 1 >> 1;
    if (check(mid))
      left = mid;
    else
      right = mid - 1;
  }
  cout << left;
  return 0;
}
