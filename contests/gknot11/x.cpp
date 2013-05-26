#include<cstdio>
int main()
{
	long long int s =0, x;
	while(scanf("%lld", &x) != EOF)
		s += x;
	printf("%lld\n",s);
}
