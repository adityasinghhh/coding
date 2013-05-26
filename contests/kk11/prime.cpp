#include<cstdio>
long long int primes[10000001];
int main()
{
	long long int z=0, i, j;
	primes[z++] = 2;

	for(i=3; i<5*1100000; i+=2)
	{
		for(j=2; j*j<=i; j++)
			if(i%j == 0)
				break;

		if(j*j > i)
			primes[z++] = i;
	}

	long long int count = 0, find;
	for(i=1; i<z; i++)
	{
		if(primes[i] >= 5*1000000)
			break;

		j=i;
		find = primes[i]-6;

		while(primes[j] > find)
			j--;

		if(primes[j] != find)
			continue;

		j=i;
		find = primes[i]+6;

		while(primes[j] < find)
			j++;

		if(primes[j] == find)
			count += primes[i];
	}

	printf("%lld\n", count);

}
