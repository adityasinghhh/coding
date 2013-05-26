#include<cstdio>
int c;
void f(double x)
{
	printf("%lf: %d\n", x, c);
	if(x/2.0 >= 1.0)
	{
		c++;
		f(x/2.0);
		f(x/2.0);
	}
}

int main()
{
	int n, no;
	double x;

	scanf("%d", &no);

	while(no--)
	{
		scanf("%d", &n);

		c = 0;
		while(n--)
		{
			scanf("%lf", &x);
			printf("%lf\n", x);
			f(x);
		}

		printf("%d\n", c);
	}

	return 0;
}
