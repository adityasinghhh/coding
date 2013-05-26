#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);

	vector<pair<double, double> > points;

	int i;
	double x, y;
	for(i=0; i<n; i++)
	{
		scanf("%lf %lf", &x, &y);

		points.push_back(make_pair(x, y));
	}

	scanf("%lf %lf", &x, &y);

	int size = points.size();
	double sum = 0.0000000, d1, d2, d3, angle;

	for(i=0; i<size; i++)
	{
		d1 = (x-points[i].first)*(x-points[i].first) + (y-points[i].second)*(y-points[i].second);
		d2 = (points[i].first-points[(i+1)%size].first)*(points[i].first-points[(i+1)%size].first) + (points[i].second-points[(i+1)%size].second)*(points[i].second-points[(i+1)%size].second);
		d3 = (points[(i+1)%size].first-x)*(points[(i+1)%size].first-x) + (points[(i+1)%size].second-y)*(points[(i+1)%size].second-y);

		angle = (d1 + d3 - d2)/(sqrt(d1*d3)*2.0);

		sum += acos(angle);
	}

	if(fabs(2.0*M_PI - sum) < 0.000000001)
		printf("Inside\n");
	else
		printf("Outside\n");

	return 0;
}
