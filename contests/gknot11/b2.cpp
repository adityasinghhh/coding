#include<cstdio>
int main()
{
	long long int det = 3, i, sum = 3;

	for(i=2; i<100; i++)
	{
		printf("%lld: %lld\t\t%lld\n", i-1, det, sum);

		det = (3*det-1)%1000000007;
		sum = (sum+det)%1000000007;
	}
}
