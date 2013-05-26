#include<cstdio>
const int con = 100000007;
long long int m(long long int a, long long int b)
{
	long long int x = 1, y = a;

	while(b > 0)
	{
		if(b%2 == 1)
		{
			x = (x*y)%con;
		}

		y = (y*y)%con;
		b /= 2;
	}

//	return x;
	return x%con;

}

long long inverse(long long a) {
	return m(a,con-2);
}

int main()
{
	long long int no, n, r1, r2;

	scanf("%lld", &no);

	long long mult = inverse(2ll); //printf("%Ld\n",mult);
	while(no--)
	{
		scanf("%lld", &n);

		r1 = ((((m(3, n) - m(2, n+1) + 1)))%con);

		if(r1 < 0)
			r1 += con;

		r1 *= mult; r1 %= con;

		++n;
		r2 = (((m(4, n-1)) - (m(3, n))  + (3*m(2, n-1)) - 1))%con;
		
		if(r2 < 0)
			r2 += con;

		r2 *= mult; r2 %= con;

		printf("%lld %lld\n", r1, r2);
	}
}
