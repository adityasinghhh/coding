#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
int abs(int a)
{
	if(a<0)
		return (-1*a);
	return a;
}

int main()
{
//	printf("%d\n", abs(-5));
	int n, i, j, k, sum, min, x, l, val, no, z;
	char ch;

	scanf("%d", &no);
	getchar();

	for(z=0; z<no; z++)
	{
		while((ch=getchar()) != '\n');

		scanf("%d", &n);

		if(n == 1)
		{
			scanf("%d", &x);
			printf("0 %d\n", x);

			if(z != no-1)
				printf("\n");

			continue;
		}
//		int dp[101][501] = {0};

		vector<int> dp[n+2];

		sum = 0;	
		for(i=1; i<=n; i++)
		{
			scanf("%d", &x);

			j = i;

			if(j >= n/2)
				j = n/2;

			for(; j>=0; j--)
			{
				l = dp[j].size();
				for(k=0; k<l; k++)
					dp[j+1].push_back(dp[j][k]+x);
			}

			dp[1].push_back(x);
			sum += x;
		}


/*		for(i=1; i<=n/2; i++)
		{
			printf("%d: ", i);
			l = dp[i].size();
			for(j=0; j<l; j++)
				printf("%d ", dp[i][j]);
			printf("\n");
		}
*/



//		for(j=1; j<=n; j++)
//		{
//			printf("%d:\n", j);
//			for(k=1; k<=451; k++)
//				printf("%d ", dp[j][k]);
//			printf("\n");
//		}

		j = n/2;
		l = dp[j].size();
		sum /= 2;

//		printf("j:%d\nsum:%d\n", j, sum);

		min = INT_MAX;
		for(k=0; k<l; k++)
		{
		//	if(k > sum) 
		//		break;

//				printf("%d ", k);
			val = abs(dp[j][k]-sum);

			if(val < min)
				min = val;
		}
//		printf("\n");

//		printf("min:%d\n", min);

		printf("%d %d\n", sum-min, sum+min);

		if(z != no-1)
			printf("\n");
	}

	return 0;
}
