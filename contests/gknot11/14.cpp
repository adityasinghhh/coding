#include<cstdio>
int main()
{
	long long int i, j, k, l, m, n, c, c1;
	c=c1=0;
	for(i=1; i<=20; i++)
		for(j=1; j<=20; j++)
			for(k=1; k<=20; k++)
				for(l=1; l<=20; l++)
					for(m=1; m<=20; m++)
						for(n=1; n<=20; n++)
							if(i^j^k^l^m^n == 0)
								c++;
							else
								c1++;
	printf("%lld\n", c);
	printf("%lld\n", c1);
	printf("%lld\n", c+c1);

}
