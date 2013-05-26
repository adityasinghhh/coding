#include<cstdio>
#include<cstring>
int main()
{
	int no, r, c, i, j, x, y, m, k;
	char ch;

	scanf("%d", &no);

	while(no--)
	{
		scanf("%d %d", &r, &c);

		c = c*2+1;
		char a[1001][1001];
		double p[1001][1001];

		for(i=0; i<r; i++)
		{
			if(i%2 == 0)
				ch = 'x';
			else
				ch = '.';

			for(j=0; j<c; j++)
			{
				a[i][j] = ch;

				if(ch == 'x')
					ch = '.';
				else
					ch = 'x';
			}
			a[i][j] = 0;
		}

		for(i=0; i<r; i++)
			printf("%s\n", a[i]);

		scanf("%d", &k);

		if(r%2 == 0)
			k = k*2 -1;
		else
			k *= 2;

		scanf("%d", &m);

		for(i=0; i<m; i++)
		{
			scanf("%d %d", &x, &y);

			if(x%2 == 0)
				a[x][y*2] = '.';
			else
				a[x][y*2+1] = '.';

		}

		for(i=0; i<r; i++)
		{		
			for(j=0; j<c; j++)
				printf("%c", a[i][j]);
			printf("\n");
		}

		double max = -1.0;
		int column = 0;
		for(int z=0; z<c; z+=2)
		{
			for(i=0; i<r; i++)
				for(j=0; j<c; j++)
					p[i][j] = 0.0;

			printf("Dropping on column: %d\n", z);
			p[0][z] = 1.0;

			for(i=0; i<r-1; i++)
			{
				j = 0;
				if(i%2 == 0)
					j = 0;
				else
					j = 1;

				for(; j<c; j+=2)
				{
					if(a[i][j] == '.')
					{
						p[i+2][j] += p[i][j];

						continue;
					}

					if(j == 0)
						p[i+1][j+1] += p[i][j];
					else if(j+2 >= c)
						p[i+1][j-1] += p[i][j];
					else
					{
						p[i+1][j-1] += p[i][j]*0.5;
						p[i+1][j+1] += p[i][j]*0.5;
					}
				}
			}

			for(i=0; i<r; i++)
			{
				for(j=0; j<c; j++)
					printf("%lf ", p[i][j]);
				printf("\n");
			}

			if(p[r-1][k] >= max)
			{
				column = z;
				max = p[r-1][k];
			}
		}

		printf("%d %lf\n", column, max);
	}
	return 0;
}
