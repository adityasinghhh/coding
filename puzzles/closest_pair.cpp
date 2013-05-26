#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
pair <int, int> closest_pair(pair<int, int> *p, int i, int j)
{

}

int main()
{
	int n, i, x, y;

	scanf("%d", &n);

	pair<int, int> p[n+1];

	for(i=0; i<n; i++)
	{
		scanf("%d %d", &x, &y);

		p[i] = make_pair(x, y);
	}

	sort(p, p+n);

	for(i=0; i<n; i++)
		printf("%d %d\n", p[i].first, p[i].second);

	pair <int, int> q = closest_pair(p, 0, n);

	printf("%d %d %d %d\n", p[q.first].first, p[q.first].second, p[q.second].first, p[q.second].second);

	return 0;
}
