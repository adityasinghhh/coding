#include<cstdio>
#include<algorithm>
using namespace std;
int  main()
{
	int n, m, i, j, c;

	scanf("%d %d", &n, &m);

	int a[n+1];

	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);

	i=0;
	j=n-1;
	c=0;
	while(i<j)
	{
		if(a[j] + a[i] >= m)
		{
			c++;
			i++;
			j--;
		}
		else
		{
			i++;
		}
	}

	printf("%d\n", c);
}
