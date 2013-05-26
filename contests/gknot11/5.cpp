#include<cstdio>
int gcd(int a, int b)
{
	if(a%b == 0)
		return b;
	return gcd(b, a%b);
}

int main()
{
//	int n = 10;
	int n = 26372;
	int i, j, c, lcm;

	c = 0;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
		{
			lcm = i*j/gcd(i, j);
			if(lcm == n)
				c++;
		}

	printf("%d\n", c);
}
