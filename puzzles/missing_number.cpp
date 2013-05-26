#include<cstdio>
int main()
{
	int n, x, s, i;

	scanf("%d", &n);
	scanf("%d", &s);

	for(i=1; i<n; i++)
	{
		scanf("%d", &x);

		s ^= x;
	}

	printf("%d\n", s);
}
