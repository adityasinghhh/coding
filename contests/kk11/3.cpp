#include<cstdio>
int main()
{
	int n = 44242532;

	int i=0;
	int k=1;

	while(i<n)
	{
		i+=k;
		printf("%d: %d\n", k, i);
		k++;
	}

	printf("%d %d\n", k, n-k);
}
