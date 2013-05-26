#include<cstdio>
#include<cmath>
long long int mod = 1000000007;
long long int **multiply(long long int **a, long long int **b)
{
	long long int **c;

	c = new long long int*[3];
	c[0] = new long long int[3];
	c[1] = new long long int[3];
	c[2] = new long long int[3];

	c[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0] + a[0][2]*b[2][0])%mod;
	c[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1] + a[0][2]*b[2][1])%mod;
	c[0][2] = (a[0][0]*b[0][2] + a[0][1]*b[1][2] + a[0][2]*b[2][2])%mod;

	c[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0] + a[1][2]*b[2][0])%mod;
	c[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1] + a[1][2]*b[2][1])%mod;
	c[1][2] = (a[1][0]*b[0][2] + a[1][1]*b[1][2] + a[1][2]*b[2][2])%mod;

	c[2][0] = (a[2][0]*b[0][0] + a[2][1]*b[1][0] + a[2][2]*b[2][0])%mod;
	c[2][1] = (a[2][0]*b[0][1] + a[2][1]*b[1][1] + a[2][2]*b[2][1])%mod;
	c[2][2] = (a[2][0]*b[0][2] + a[2][1]*b[1][2] + a[2][2]*b[2][2])%mod;

	return c;
}

long long int **power(long long int **a, long long int n)
{
	if(n == 1)
		return a;
	if(n == 2)
		return multiply(a, a);
	if(n%2 == 0)
		return power(power(a, n/2), 2);
	return multiply(a, power(a, n-1));
}

int main()
{
	long long int **a = new long long int*[3];
	a[0] = new long long int[3];
	a[1] = new long long int[3];
	a[2] = new long long int[3];

	a[0][0] = 1; a[0][1] = 3; a[0][2] = -1;
	a[1][0] = 0; a[1][1] = 3; a[1][2] = -1;
	a[2][0] = 0; a[2][1] = 1; a[2][2] = 0;

	long long int no;
	long long int n, m, **na, **ma;

	long long int q = 1ll*1000*1000*1000*1000*1000*100;

	printf("%lld\n", q);

	long long int **p = power(a, q-2);

	long long int **b = new long long int*[3];
	b[0] = new long long int[1];
	b[1] = new long long int[1];
	b[2] = new long long int[1];

	b[0][0] = 0;
	b[1][0] = 3;
	b[2][0] = 1;

	int i, j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
			printf("%lld ", p[i][j]);
		printf("\n");
	}

	long long int v = (p[0][0]*11 + p[0][1]*8 + p[0][2]*3)%mod;

//	long long int **m = multiply(p, b);

	if(v < 0)
		printf("%lld\n", v+mod);
	else
		printf("%lld\n", v);

	return 0;
}


