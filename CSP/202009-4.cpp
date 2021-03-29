#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100 + 5;
const int M = 2000 + 5;
struct p
{
	double a[N];
	double dis[M];
} p[M];
int n, m;
double r;
double O[N];
double d[M], rd[M];
int main()
{
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> O[i];
	for (int j = 1; j <= m; j++)
		for (int i = 1; i <= n; i++)
			cin >> p[j].a[i];
	for (int i = 1; i <= m; i++)
	{
		double temp = 0;
		for (int j = 1; j <= n; j++)
		{
			temp += (p[i].a[j] - O[j]) * (p[i].a[j] - O[j]);
		}
		d[i] = sqrt(temp);
		rd[i] = sqrt(d[i] * d[i] - r * r);
	}
	for (int i = 1; i < m; i++)
		for (int j = i + 1; j <= m; j++)
		{
			double temp = 0;
			for (int k = 1; k <= n; k++)
				temp += (p[i].a[k] - p[j].a[k]) * (p[i].a[k] - p[j].a[k]);
			double x = sqrt(temp);
			double pp = (x + d[i] + d[j]) / 2;
			double s = sqrt(pp * (pp - x) * (pp - d[i]) * (pp - d[j]));
			double h = 2 * s / x;
			if (h >= r || (x * x + d[i] * d[i] <= d[j] * d[j]) || (x * x + d[j] * d[j] <= d[i] * d[i]))
			{
				p[i].dis[j] = p[j].dis[i] = x;
				continue;
			}
			double angle1 = acos((d[i] * d[i] + d[j] * d[j] - x * x) / (2 * d[i] * d[j]));
			double angle2 = acos(r / d[i]);
			double angle3 = acos(r / d[j]);
			p[i].dis[j] = p[j].dis[i] = (angle1 - angle2 - angle3) * r + rd[i] + rd[j];
		}
	for (int i = 1; i <= m; i++)
	{
		double sum = 0;
		for (int j = 1; j <= m; j++)
		{
			if (i == j)
				continue;
			sum += p[i].dis[j];
		}
		printf("%.14f\n", sum);
	}
}
