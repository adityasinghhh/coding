#include<cstdio>
#include<cmath>
int main()
{
	double p = (1.0+sqrt(5.0))/2.0;
	int i, c, x, y;

	i = c = 0;

	while(1)
	{
		x = floor(p*(double)i);
		y = floor(p*p*(double)i);

		if(x > 100000000)
			break;

		if( x == y)
			c+=1;
		else
			c+=2;

		i++;
	}

	printf("%d\n", c);
}
