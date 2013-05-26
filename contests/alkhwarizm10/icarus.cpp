#include<cstdio>
int **a;
int main()
{
	int no, n, s, i, j, count, degree, c, d, x, y;
	char ch;

	int q[100000][2];

	scanf("%d", &no);

	while(no--)
	{
		scanf("%d %d", &n, &s);
		getchar();

		a = new int*[n+1];
		for(i=0; i<=n; i++)
			a[i] = new int[n+1];

		for(i=0; i<s; i++)
		{
			scanf("%c %d %d", &ch, &x, &y);
			getchar();

			//printf("%c %d %d\n", ch, x, y);

			if(ch == 'B')
				a[x][y] = 'B';
			else if(ch == 'W')
				a[x][y] = 'W';
		}

		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
				printf("%d ", a[i][j]);
			printf("\n");
		}

		int B[n*n+1][2], W[n*n+1][2], zb = 0, zw = 0, ii, jj;

		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				if(a[i][j] == 'B')
				{
					a[i][j] = 1;
					q[0][0] = i;
					q[0][1] = j;

					c = 0; 
					d = 1;

					count = 0;
					degree = 0;

					while(c < d)
					{
						ii = q[c][0];
						jj = q[c][1];

						if(ii > 1 && a[ii-1][jj] == 0)
							degree++;
						if(jj > 1 && a[ii][jj-1] == 0)
							degree++;
						if(ii < n && a[ii+1][jj] == 0)
							degree++;
						if(jj < n && a[ii][jj+1] == 0)
							degree++;

						if(ii > 1 && a[ii-1][jj] == 'B')
						{
							a[ii-1][jj] = 1;
							q[d][0] = ii-1;
							q[d++][1] = jj;
						}

						if(jj > 1 && a[ii][jj-1] == 'B')
						{
							a[ii][jj-1] = 1;
							q[d][0] = ii;
							q[d++][1] = jj-1;
						}

						if(ii < n && a[ii+1][jj] == 'B')
						{
							a[ii+1][jj] = 1;
							q[d][0] = ii+1;
							q[d++][1] = jj;
						}
						
						if(jj < n && a[ii][jj+1] == 'B')
						{
							a[ii][jj+1] = 1;
							q[d][0] = ii;
							q[d++][1] = jj+1;
						}

						c++;
					}

//					printf("%d %d %c %d %d\n", i, j, a[i][j], d, degree);

					B[zb][0] = d;
					B[zb++][1] = degree;
				}
				else if(a[i][j] == 'W')
				{
					a[i][j] = 1;
					q[0][0] = i;
					q[0][1] = j;

					c = 0; 
					d = 1;

					count = 0;
					degree = 0;

					while(c < d)
					{
						ii = q[c][0];
						jj = q[c][1];

						printf("%d %d: %d\n", ii, jj, degree);
						

						if(ii > 1 && a[ii-1][jj] == 0)
							degree++;
						if(jj > 1 && a[ii][jj-1] == 0)
							degree++;
						if(ii < n && a[ii+1][jj] == 0)
							degree++;
						if(jj < n && a[ii][jj+1] == 0)
							degree++;
					
						printf("%d %d: %d\n", ii, jj, degree);

						if(ii > 1 && a[ii-1][jj] == 'W')
						{
							a[ii-1][jj] = 1;
							q[d][0] = ii-1;
							q[d++][1] = jj;
						}

						if(jj > 1 && a[ii][jj-1] == 'W')
						{
							a[ii][jj-1] = 1;
							q[d][0] = ii;
							q[d++][1] = jj-1;
						}

						if(ii < n && a[ii+1][jj] == 'W')
						{
							a[ii+1][jj] = 1;
							q[d][0] = ii+1;
							q[d++][1] = jj;
						}
						
						if(jj < n && a[ii][jj+1] == 'W')
						{
							a[ii][jj+1] = 1;
							q[d][0] = ii;
							q[d++][1] = jj+1;
						}

						c++;
					}
					
//					printf("%d %d %c %d %d\n", i, j, a[i][j], d, degree);

					W[zw][0] = d;
					W[zw++][1] = degree;
				}

		for(i=0; i<zb; i++)
			printf("B %d %d\n", B[i][0], B[i][1]);
		for(i=0; i<zw; i++)
			printf("W %d %d\n", W[i][0], W[i][1]);
	}

	return 0;
}
