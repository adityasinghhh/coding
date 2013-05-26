#include<cstdio>
int main()
{
	char a[1000000];
	long double sum = 0.0, x;
	int i;

	i = 1;

	while(i < 1000000)
	{
		x = (long double)i;

		sum = sum + (x+2.0)/x;
		i++;
	sprintf(a, "%.100llf", sum);
	printf("%s\n", a);
	}

	sprintf(a, "%.100llf", sum);
	printf("%s\n", a);
}
