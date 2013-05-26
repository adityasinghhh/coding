#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int i, n, ch;

	printf("1.String\n2.Integer Array\n");
	while(scanf("%d", &ch) != EOF)
	{
		if(ch == 1)
		{
			scanf("%d", &n);
			int a[n+1];

			for(i=0; i<n; i++)
				scanf("%d", &a[i]);

			while(next_permutation(a, a+n))
			{
				for(i=0; i<n; i++)
					printf("%d ", a[i]);
				printf("\n");			
			}
		}
		else if(ch == 2)
		{
			scanf("%d", &n);

			char a[n+1];

			scanf("%s", a);

			while(next_permutation(a, a+n))
			{
				printf("%s\n", a);
			}
		}
		else
			printf("1 or 2\n");
	}

	return 0;
}
