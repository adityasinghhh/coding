#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<b;++i)
int main()
{
	int T = 25;
	printf("25\n");
	while(T--)
	{
		printf("100\n");
		FOR(i,1,101)
		{
			printf("99 ");
			FOR(j,1,101)
			{
				if(i == j) { continue; }
				printf("%d ", j);
			}
			printf("\n");
		}
	}
}
