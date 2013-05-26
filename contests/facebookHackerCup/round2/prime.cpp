#include<cstdio>
int main()
{
	int p = 247747;

	int c = 0, c1 = 0, i, j;
	for(i=0; i<p; i++)
		for(j=i; j<p; j++)
			if((i*j)%p < 10010)
			{
			//	printf("%d %d\n", i, j);

				if(i == j)
					c1++;
				else
					c++;
			}

	printf("%d\n", 2*c+c1);
}
