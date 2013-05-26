#include<cstdio>
int main()
{
	long double f=0.0;
	long long int n;
	char a[100000];

	for(n=1; n<1000000000; n++)
	{
		if(n%2)
		{
			f += (((long double)(1))/((long double)(1+n)) + ((long double)(2*n-1))/((long double)(n*n-n+1)))/3.0;
		}
		else
		{
			f -= (((long double)(1))/((long double)(1+n)) + ((long double)(2*n-1))/((long double)(n*n-n+1)))/3.0;
		}
	}

	sprintf(a, "%.101llf", f);
	printf("%s\n", a);
}
