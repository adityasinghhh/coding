#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int no, i, j, s, e, l, b, c;
	scanf("%d", &no);

	while(no--)
	{
		int d[10][501] = {0};

		scanf("%d", &b);

		for(i=0; i<b; i++)
		{
			scanf("%d %d %d", &s, &e, &l);

			for(j=s; j<=e; j++)
				d[l][j]++;
		}

		c=0;
		for(i=1; i<=500; i++)
		{
			for(j=1; j<10; j++)
			{
//				printf("%d ", d[j][i]);
				if(d[j][i] == 1 && d[j-1][i] == 1)
				{
//					printf("%d %d %d\n", j, i, d[j][i]);
					break;
				}
			}
//			printf("\n");

			if(j == 10)
				c++;
		}

		printf("%d\n", c);
	}

	return 0;
}
