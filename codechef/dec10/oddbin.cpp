#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int t, m, i;

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &m);

		long long int a[m+1], b[m+1];

		for(i=0; i<m; i++)
			scanf("%lld", &a[i]);

		sort(a, a+m);

		for(i=0; i<m; i++)
		{
			b[i] = (long long int)pow(2.0, (double)__builtin_popcount(a[i]-1));
			printf("%lld\n", b[i]);
		}
	}

	return 0;
}
