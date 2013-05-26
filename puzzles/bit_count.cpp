#include<cstdio>
void dense_ones ( int n)   {

	int count = 8 * sizeof(int) ;
	printf("Count: %d\n", count);
	n ^= ( int) - 1 ;

	printf("%d\n", n);
	while (n)  {
		count-- ;
		n &= (n - 1) ;
		printf("%d\n", n);
	}

	printf("Count: %d\n", count);
}

int main()
{
	int n;

	while(scanf("%d", &n) != EOF)
	{
		int count = 0;

		while(n)
		{
			count++;
			n &= (n-1);

			printf("%d\n", n);
		}

		printf("%d\n", count);

		dense_ones(n);
	}

	return 0;
}
