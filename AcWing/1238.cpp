#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
const int N = 100005;
int n, d, k;
vector<int> v[N];
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> d >> k;
    for (int i = 0; i < n; i++)
    {
        int ts, id;
        cin >> ts >> id;
        v[id].push_back(ts);
    }
    for (int id = 0; id < N; id++)
        if (v[id].size())
        {
            sort(v[id].begin(), v[id].end());
            int i = 0, j = 0;
            while (j < v[id].size())
            {
                while (j < v[id].size() && v[id][j] - v[id][i] < d)
                    j++;
                if (j - i >= k)
                {
                    cout << id << endl;
                    break;
                }
                i++;
            }
        }
}
