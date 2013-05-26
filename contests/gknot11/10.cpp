#include<cstdio>
#include<cmath>
#include<cstring>
long long int mod(long long int a, long long int b, long long int c)
{
	long long int x = 1, y = a;

	while(b > 0)
	{
		if(b%2 == 1)
		{
			x = (x*y)%c;
		}

		y = (y*y)%c;
		b /= 2;
	}

	return x%c;
}
	long long int factors[10000001];

int main()
{
	long long int p, n, x, m , phi_p, z, i, j, a, flag, c;
	scanf("%lld", &p);

	x = phi_p = p-1;

	z = 0;
	for(i=2; i*i<=x; i++)
		if(x%i == 0)
		{
			factors[z++] = i;
			while(!(x%i))
				x/=i;
		}
	if(x>1)
		factors[z++] = x;

	c = 0;
	for(j=0; j<p; j++)
	{
		a = j;
		for(i=0; i<z; i++)
			if(mod(a, phi_p/factors[i], p) == 1)
				break;

		if(i == z)
			c++;
	}

	printf("%lld\n", c);
}
