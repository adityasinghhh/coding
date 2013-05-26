#include<cstdio>
char a[50][50];
int m, n, max;
int f(int i, int j, int count)
{
//	printf("%d %d: %d\n", i, j, count);
	//for(int i1=0; i1<m; i1++)
	//		printf("%s\n", a[i1]);

	if(count > max)
		max = count;

	int ii, jj;
	char ch1, ch2, ch3, ch4;

	if(j != n-1)
	{
		ii = i;
		jj = j+1;
	}
	else
	{
		ii = i+1;
		jj = 0;
	}	

	for(; ii<m; ii++, jj = 0)
	{
		for(; jj<n; jj++)
			if(a[ii][jj] == '.')
			{
				f(ii, jj, count);

				ch1 = a[ii+2][jj+1];
				a[ii+2][jj+1] = '#';
				ch2 = a[ii+1][jj+2];
				a[ii+1][jj+2] = '#';
				if(ii >= 2 && jj >=1)
				{
					ch3 = a[ii-2][jj-1];
					a[ii-2][jj-1] = '#';
				}
				if(ii >= 1 && jj >=2)
				{
					ch4 = a[ii-1][jj-2];
					a[ii-1][jj-2] = '#';
				}
				f(ii, jj, count+1);
				a[ii+2][jj+1] = ch1;
				a[ii+1][jj+2] = ch2;
				if(ii >= 2 && jj >=1)
					a[ii-2][jj-1] = ch3;
				if(ii >= 1 && jj >=2)
					a[ii-1][jj-2] = ch4;
			}
	}
}

int main()
{
	int no, i, j;
	char ch1, ch2, ch3, ch4;

	scanf("%d", &no);

	while(no--)
	{
		scanf("%d %d", &m, &n);

		for(i=0; i<m; i++)
			scanf("%s", a[i]);

		max = -1;
		for(i=0; i<m; i++)
			for(j=0; j<n; j++)
				if(a[i][j] == '.')
				{
					ch1 = a[i+2][j+1];
					a[i+2][j+1] = '#';
					ch2 = a[i+1][j+2];
					a[i+1][j+2] = '#';
					if(i >= 2 && j >=1)
					{
						ch3 = a[i-2][j-1];
						a[i-2][j-1] = '#';
					}
					if(i >= 1 && j >=2)
					{
						ch4 = a[i-1][j-2];
						a[i-1][j-2] = '#';
					}
					f(i, j, 1);
					a[i+2][j+1] = ch1;
					a[i+1][j+2] = ch2;
					if(i >= 2 && j >=1)
						a[i-2][j-1] = ch3;
					if(i >= 1 && j >=2)
						a[i-1][j-2] = ch4;
//					printf("\n");
					goto x;
				}
x:
		f(i, j, 0);

//		for(i=0; i<m; i++)
//			printf("%s\n", a[i]);

		printf("%d\n", max);					
	}

	return 0;
}
