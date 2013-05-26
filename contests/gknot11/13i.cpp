#include<cstdio>
long long int T[100][100];
long long int t(long long int n, long long int k)
{
	if(T[n][k] != -1)
		return T[n][k];

	if(n == 1 && k == 1)
	{
		T[n][k] = 1;
		return 1;
	}

	T[n][k] = k*t(n-1, k) + (n-k+1)*t(n-1, k-1);
	return T[n][k];
}

int main()
{
	long long int i, j;

	for(i=0; i<100; i++)
		for(j=0; j<100; j++)
			T[i][j] = -1;

	for(i=1; i<=10; i++)
	{
		for(j=1; j<=i; j++)
			printf("%lld ", t(i, j));
		printf("\n");
	}


	for(i=1; i<=10; i++)
	{
		for(j=1; j<=i; j++)
			printf("%lld ", T[i][j]);
		printf("\n");
	}

}
