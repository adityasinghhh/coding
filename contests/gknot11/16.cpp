#include<cstdio>
#include<cmath>
int inline gcd(int a, int b)
{
	if(a%b)
		return gcd(b, a%b);
	return b;
}
int main()
{
	int a, b, c,count=0, g;
	double s, area, x;

	int prev_a = 4;
	a= 14;

	while(true)
	{
		int t = a;
		a = 4*a - prev_a;
		prev_a = t;

		if(3*a > 1000000000)
			break;
		
		count++;
	}

	printf("%d\n", count);
}
