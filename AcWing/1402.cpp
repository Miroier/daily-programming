#include "algorithm"
#include "cmath"
#include "iostream"
#include "string"
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 110;
const double eps = 1e-6;

int w, h;
char g[N][N];
PII q[N * N];
int top;
double Hash[30];
int id;

void inp()
{
    cin >> w >> h;
    for (int i = 0; i < h; i++)
        cin >> g[i];
}

double get_dist(PII a, PII b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double get_hash()
{
    double sum = 0;
    for (int i = 0; i < top; i++)
        for (int j = i + 1; j < top; j++)
            sum += get_dist(q[i], q[j]);
    return sum;
}

double get_id(double key)
{
    for (int i = 0; i < id; i++)
        if (fabs(Hash[i] - key) < eps)
            return 'a' + i;
    Hash[id++] = key;
    return 'a' + id - 1;
}

void dfs(int x, int y)
{
    q[top++] = {x, y};
    g[x][y] = '0';
    for (int i = x - 1; i <= x + 1; i++)
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i == x && j == y)
                continue;
            if (i >= 0 && i < h && j >= 0 && j < w && g[i][j] == '1')
                dfs(i, j);
        }
}

void work()
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (g[i][j] == '1')
            {
                top = 0;
                dfs(i, j);
                char c = get_id(get_hash());
                for (int k = 0; k < top; k++)
                    g[q[k].x][q[k].y] = c;
            }
    for (int i = 0; i < h; i++)
        cout << g[i] << endl;
}

int main()
{
    inp();
    work();
}
