#include<cstdio>
int main()
{
	int a[1000000];

	int i, sum, diff, c, j, min;
	for(i=0; i<100000; i++)
		a[i] = i*(3*i-1)/2;

	for(i=0; i<1000; i++)
		for(j=0; j<1000; j++)
		{
			sum = a[i]+a[j];

			diff = a[i]-a[j];
			if(diff < 0)
				diff = -diff;

			c = 0;
			for(i=0; i<100000; i++)
				if(sum == a[i] || diff == a[i])
					c++;

			if(c == 2)
				if(min > diff)
					min = diff;
		}

	printf("%d\n", min);


}
