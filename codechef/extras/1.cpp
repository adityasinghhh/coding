#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int no, r, c, er, ec, sr, sc, h, i, j, z, x, y, dist;
	scanf("%d", &no);

	while(no--)
	{
		scanf("%d %d %d %d %d %d %d", &r, &c, &sr, &sc, &er, &ec, &h);

		int a[r+1][c+1], dp[r+1][c+1], q[(r+1)*(c+1)+1][3];

		for(i=0; i<r; i++)
			for(j=0; j<c; j++)
				dp[i][j] = -1;

		z = 0;
		for(i=0; i<h; i++)
		{
			scanf("%d %d", &x, &y);

			q[z][0] =  x;
			q[z][1] = y;
			q[z++][2] = 0;

			dp[x][y] = 0;
		}

		y = 0;

		while(y<z)
		{
			i = q[y][0];
			j = q[y][1];
			dist = q[y][2];

			if(i != 0 && dp[i-1][j] == -1)
			{
				q[z][0] = i-1;
				q[z][1] = j;
				q[z++][2] = dist+1;
				dp[i-1][j] = dist+1;
			}

			if(i != r-1 && dp[i+1][j] == -1)
			{
				q[z][0] = i+1;
				q[z][1] = j;
				q[z++][2] = dist+1;
				dp[i+1][j] = dist+1;
			}

			if(j != 0 && dp[i][j-1] == -1)
			{
				q[z][0] = i;
				q[z][1] = j-1;
				q[z++][2] = dist+1;
				dp[i][j-1] = dist+1;
			}

			if(j != c-1 && dp[i][j+1] == -1)
			{
				q[z][0] = i;
				q[z][1] = j+1;
				q[z++][2] = dist+1;
				dp[i][j+1] = dist+1;
			}

			y++;
		}

		printf("%d %d\n", r, c);
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
				printf("%d ", dp[i][j]);
			printf("\n");
		}

		q[0][0] = sr;
		q[0][1] = se;
		z = 1;
		y = 0;

		for(i=1; i<=1 ; i++)
		{
			while(y < z)
			{
			}
		}

		
	}

	return 0;
}
