#include<iostream>
#include<stdio.h>


using namespace std;

int main()
{
	long long int T,n;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		if(n==1)
			printf("0\n");
		else
			printf("%lld\n",(n*n)/2-1);
	}
	return 0;
}
