#include<cstdio>
int gcd(int a, int b)
{
	if(a%b==0)
		return b;
	return gcd(b, a%b);
}
int main()
{
	int a = 34398, b = 2132;
	int g = gcd(a, b);

	printf("%d\n", g);

	int i;
	for(i=-100000; i<10000; i++)
		if((a*i-g)%b == 0)
		{

	printf("%d %d\n", i, (a*i-g)/b);
		}

	
}
