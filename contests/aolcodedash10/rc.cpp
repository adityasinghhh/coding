#include<cstdio>
#include<cmath>
int main()
{
	int n, i, j;
	double x;

	scanf("%d", &n);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%lf", &x);

	for(i=n-1; i>=0; i--)
		printf("%d %d\n", (i+1)%n, (i)%n);
}
