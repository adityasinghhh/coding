#include<cstdio>
#include<cmath>
char a[10000000];
int main()
{
	long double v = 0.0, val;
	int m, n, sqrt_n;

	for(m=2; m<=1000000; m++)
	{
		n = 1;
		while(true)
		{
			val = sqrt(n)-floor(sqrt(n));

			if(val < 0.500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000)
				sqrt_n = floor(sqrt(n));
			else
				sqrt_n = ceil(sqrt(n));

			val = (pow((long double)m, 2.0*(long double)sqrt_n) + 1.0)/(pow((long double)m, (long double)(n+sqrt_n)));

			if(val < 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001)
				break;

			v += val;
			n++;
		}
	//	printf("%d\n", m);
	}

	sprintf(a, "%.100llf", v);
	printf("%s\n", a);
}

