#include<cstdio>
#include<climits>
unsigned long long int a[101][2], b[101][2], r, t;
unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
{
	if(a%b == 0)
		return b;
	return gcd(b, a%b);
}

double max;
unsigned long long int maxnum, maxden;

void f(unsigned long long int i, unsigned long long int R, unsigned long long int num, unsigned long long int den)
{
	printf("here with i: %d\n", i);
	if(i == t)
	{
		if(r-1 == R)
		{
			unsigned long long int g = gcd(den, num);

			printf("%llu/%llu\n", num/g, den/g);

			double val = (double)(num/g)/(double)(den/g);

			if(val > max)
			{
				max = val;
				maxnum = num/g;
				maxden = den/g;
			}
		}
		return;
	}

	if(r-1 == R)
	{
		num *= b[i][0];
		den *= b[i][1];

		printf("there\n");
		printf("den: %llu, num: %llu\n", den, num);
		unsigned long long int g = gcd(den, num);

		printf("%llu\n", g);

		f(i+1, R, num/g, den/g);
	}
	else
	{
		unsigned long long int num1 = num*a[i][0], den1 = den*a[i][1];

		unsigned long long int g = gcd(den1, num1);

		f(i+1, R+1, num1/g, den1/g);

		num1 = num*b[i][0];
		den1 = den*b[i][1];

		g = gcd(den1, num1);

		f(i+1, R, num1/g, den1/g);
	}
}

int main()
{
	unsigned long long int no, i;

	scanf("%llu", &no);

	while(no--)
	{
		scanf("%llu %llu", &r, &t);

		for(i=0; i<t; i++)
		{
			scanf("%llu %llu", &a[i][1], &b[i][1]);

			a[i][0] = a[i][1]-1;
			b[i][0] = b[i][1]-1;
		}

		printf("here\n");

		max = -1.0;
		f(0, 0, 1, 1);

		printf("%llu/%llu\n", maxnum, maxden);
//		printf("\n");
	}
}
