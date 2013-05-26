#include<cstdio>
#include<cstring>
int m[2001][2001];
int main()
{
	char a[2001], b[2001];
	int n, la, lb, i, j;

	while(scanf("%d", &n))
	{
		if(n == 0)
			return 0;

		scanf("%s", a);
		scanf("%s", b);

		la = strlen(a);
		lb = strlen(b);

		for(i=0; i<la; i++)
			m[i][0] = 0;
		for(j=0; j<lb; j++)
			m[0][j] = 0;

		for(i=1; i<=la; i++)
			for(j=1; j<=lb; j++)
				if(a[i-1] == b[j-1])
					m[i][j] = m[i-1][j-1]+1;
				else
				{
					if(m[i-1][j] > m[i][j-1])
						m[i][j] = m[i-1][j];
					else
						m[i][j] = m[i][j-1];
				}

		printf("%d\n", m[la][lb]);
	}
}
