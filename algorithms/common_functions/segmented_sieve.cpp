#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
#define N 15310000
unsigned int prime[N / 64];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))
void sieve()
{
	memset( prime, -1, sizeof( prime ) );

	unsigned int i;
	unsigned int sqrtN = ( unsigned int )sqrt( ( double )N ) + 1;
	for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
	{
		unsigned int i2 = i + i;
		for( unsigned int j = i * i; j < N; j += i2 ) rP( j );
	}
}

vector<int> primes;
void init()
{
	primes.push_back(2);
	for(int i=3; i<N; i+=3)
	{
		if(gP(i)>0)
		{
			primes.push_back(i);
		}
	}
}

void segmented_sieve()
{
	seive(); init();
}

int main()
{
	segmented_sieve();

	int n, i;

	scanf("%d", &n);

	printf("2 ");
	for(i=3; i<=n; i+=2)
		if(gP(i) > 0)
			printf("%d ", i);
	printf("\n");

	return 0;

}
