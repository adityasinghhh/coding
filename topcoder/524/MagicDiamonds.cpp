#include <vector>
#include<cstring>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class MagicDiamonds {
public:
	long long minimalTransfer(long long);
};

#define N 1000100
long long int prime[N / 64];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))
void sieve()
{
	memset( prime, -1, sizeof( prime ) );

	long long int  i, sqrtN = ( long long int )sqrt( ( double )N ) + 1;
	for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
	{
		long long int i2 = i + i;
		for( long long int j = i * i; j < N; j += i2 ) rP( j );
	}
}

vector<long long int> primes;
void init()
{
	primes.push_back(2);
	for(long long int i=3; i<N; i+=2)
	{
		if(gP(i)>0)
		{
			primes.push_back(i);
		}
	}
}

long long MagicDiamonds::minimalTransfer(long long n) {

	if(n < 5) { return n; } 

	long long v = (long long)sqrt((double)n), i;

	for(i=2; i<=v; ++i)
	{
		if(n % i == 0)
		{
			break;
		}
	}

	if(i == v+1) { return 2; }
	return 1;
}
