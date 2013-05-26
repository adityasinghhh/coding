#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int no, t, n, i, j;
	scanf("%d", &no);

	while(no--)
	{
		scanf("%d", &t);

		scanf("%d", &n);
		int a[n+1];

		for(i=1; i<=n; i++)
			scanf("%d", &a[i]);

		a[0] = -1;
		sort(a, a+n);

		int d[20001] = {0};

		for(i=1; i<=n; i++)
		{
		//	printf("%d\n", i);
			for(j=1; j<=20000; j++)
			{
				if(d[j] != 0)
				{
					if(j<t)
					{
						if(d[j+a[i]] == 0 || d[j+a[i]] > d[j]+1)
							d[j+a[i]] = d[j]+1;
					}
				}
			}
			
			if(d[a[i]] == 0)
				d[a[i]] = 1;
		}
		//printf("here\n");

		for(j=0; j<=20000; j++)
		{
			//printf("%d:%d ", j, d[j]);
			;
		}
		//printf("\n");

		for(j=t;j<=20000;j++)
			if(d[j]!=0)
			{
				printf("%d %d\n", j, d[j]);
				break;
			}
	}

	return 0;
}
