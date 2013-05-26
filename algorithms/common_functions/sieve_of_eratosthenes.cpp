
#define RANGE 100000000

char isPrime[RANGE+10];
int primes[RANGE/10 + 10], p_cnt;

void sieve()
{
	isPrime[0] = isPrime[1] = 1;
	p_cnt = 0;

	REP(i,RANGE+10)
	{
		if(isPrime[i]) { continue; }

		primes[p_cnt++] = i;

		for(int j=2; j<RANGE/i; ++j)
		{
			isPrime[j*i] = 1;
		}
	}
}

