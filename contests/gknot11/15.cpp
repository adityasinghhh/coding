#include<cstdio>
int main()
{
	long double f=0.0;
	long long int n;
	char a[100000];

	for(n=1; n<21000000; n++)
	{
		if(n%2)
		{
			f += ((long double)(n*n))/((long double)(n*n*n+1));
		}
		else
		{
			f -= ((long double)(n*n))/((long double)(n*n*n+1));
		}
	}

	sprintf(a, "%.101llf", f);
	printf("%s\n", a);
}
