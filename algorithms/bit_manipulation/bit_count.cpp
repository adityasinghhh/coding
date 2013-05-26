#include<cstdio>
int main()
{
	int n, x;

	while(scanf("%d", &n) != EOF)
	{
		printf("Number of trailing zeroes: %d\n", __builtin_ctz(n));
		printf("Number of leading zeroes: %d\n", __builtin_clz(n));
		printf("Number of set bits: %d\n", __builtin_popcount(n));

		printf("Last Bit: %d\n", n & ~(n-1));
	}
}
