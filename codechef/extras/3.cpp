#include<cstdio>
#include<limits.h>
int abs(int a, int b)
{
	if(a-b < 0)
		return b-a;
	return a-b;
}

int main()
{
	int no, n, x, y, t, i, j, v, v1, dist, maxi, mini, temp, dist1;

	scanf("%d", &no);
	while(no--)
	{
		scanf("%d", &n);
		int q[1000000][4];
		for(i=0; i<n; i++)
		{
			scanf("%d %d %d", &x, &y, &t);

			q[i][0] = x;
			q[i][1] = y;
			q[i][2] = t;

			dist = abs(x, 0)+ abs(y, 0);
			if(dist <= t)
				q[i][3] = 1;
			else
			{
				i--;
				n--;
			}
		}
		
		if(n == 0)
		{
			printf("No Photos\n");
			continue;
		}
/*
		for(i=0; i<n; i++)
		{
			for(j=0; j<4; j++)
				printf("%d ", q[i][j]);
			printf("\n");
		}
*/
		for(i=0; i<n; i++)
			for(j=i+1; j<n; j++)
				if(q[i][2] > q[j][2])
				{
					temp = q[i][0];
					q[i][0] = q[j][0];
					q[j][0] = temp;
					temp = q[i][1];
					q[i][1] = q[j][1];
					q[j][1] = temp;
					temp = q[i][2];
					q[i][2] = q[j][2];
					q[j][2] = temp;
					temp = q[i][3];
					q[i][3] = q[j][3];
					q[j][3] = temp;
				}
/*
		printf("Time Sorted\n");
		for(i=0; i<n; i++)
		{
			for(j=0; j<4; j++)
				printf("%d ", q[i][j]);
			printf("\n");
		}
*/
		for(i=0; i<n; i++)
			for(j=i+1; j<n; j++)
			{
				dist = abs(q[i][0]-q[j][0], 0)+abs(q[i][1]-q[j][1], 0);
				dist1 = abs(q[j][2] - q[i][2], 0);

				if(dist1 >= dist && q[j][3] < q[i][3]+1)
					q[j][3] = q[i][3]+1;
			}
/*
		printf("DPed\n");
		for(i=0; i<n; i++)
		{
			for(j=0; j<4; j++)
				printf("%d ", q[i][j]);
			printf("\n");
		}
*/
		maxi = 0;
		mini = INT_MAX;
		for(i=0; i<n; i++)
			if(maxi < q[i][3])
			{
				maxi = q[i][3];
				mini = q[i][2];
			}
			else if(maxi == q[i][3] && mini > q[i][2])
				mini = q[i][2];

		if(maxi == 0)
			printf("No Photos\n");
		else
			printf("%d %d\n", maxi, mini);
	}
	return 0;
}
