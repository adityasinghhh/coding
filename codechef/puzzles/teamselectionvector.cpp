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
	int n, i, j, k, sum, min, x, l, val, no, z, t1, t2;
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
		//int dp[101][501] = {0};

		vector<int> dp[n+2];

		sum = 0;
		for(i=1; i<=n; i++)
		{
			scanf("%d", &x);
			j=i;
			if(i>n/2)
				j=n/2;
			for(; j>=1; j--)
			{
				l = dp[j].size();
				for(k=0; k<l; k++)
					dp[j+1].push_back(dp[j][k]+x);
			}

			dp[1].push_back(x);
			sum += x;
		}

		j = n/2;
		l = dp[j].size();

		min = INT_MAX;
		for(k=0; k<l; k++)
		{
			if(k > sum)
				break;

			val = abs(2*dp[j][k]-sum);

			if(val < min)
			{
				t1 = dp[j][k];
				t2 = sum-dp[j][k];
				min = val;
			}
		}

		if(t1 > t2)
			printf("%d %d\n", t2, t1);
		else
			printf("%d %d\n", t1, t2);

		if(z != no-1)
			printf("\n");
	}

	return 0;
}

