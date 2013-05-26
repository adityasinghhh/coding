#include<cstdio>
#include<climits>
#include<cmath>
#include<map>
using namespace std;
map<unsigned long long int, int> m1;
map<unsigned long long int, int>::iterator it;
int abs(int a)
{
	if(a<0)
		return -a;
	return a;
}

int main()
{

	int no, n, i, j, sum, k, m, sum1, max, t1, t2, min, q_sum, c, val, v;
	unsigned long long int p, q, r, x;

	for(i=1; i<=64; i++)
		m1[1llu<<i] = i;
	m1[1] = 1llu;

//	for(it = m1.begin(); it != m1.end(); it++)
//		printf("%llu: %d\n", (*it).first, (*it).second);

	scanf("%d", &no);

	while(no--)
	{
		unsigned long long int dp[51][10000] = {0};

		scanf("%d", &n);

		int a[n+1];

		m = n/2;
		if(n%2 == 1)
			m++;

		sum = 0;
		for(i=1; i<=n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}

		if(n == 1)
		{
			printf("0 %d\n", a[1]);

			if(no)
				printf("\n");

			continue;
		}

		//printf("sum: %d\n", sum);
		q_sum = sum/64+1;
		for(i=1; i<=n; i++)
		{
			for(j=i<m?i:m; j>0; j--)
				for(k=0; k<=q_sum; k++)
					if(dp[j][k])
					{
						x = dp[j][k];

						while(x)
						{
							v = m1[x & ~(x-1)];
							val = k*64+v+a[i];

							q = val/64;
							r = val%64;

							p = 1llu<<r;

							dp[j+1][q] |= p;

							x = x-(x & ~(x-1));
						}
					}

			q = a[i]/64;
			r = a[i]%64;

			p = 1llu<<r;

			dp[1][q] |= p;
		}

	/*	for(i=0; i<=n; i++)
		{
			printf("%d: ", i);

			for(j=0; j<=q_sum; j++)
				if(dp[i][j])
				{
					x = dp[i][j];

					while(x)
					{
						v = m1[x & ~(x-1)];
						val = j*64+v;

						printf("%d ", val);
						x = x-(x & ~(x-1));
					}
				}
			printf("\n");
		}
*/
		if(n%2 == 1)
		{
			min = INT_MAX;
			for(i=0; i<2; i++)
				for(j=0; j<=q_sum; j++)
					if(dp[i+n/2][j])
					{
						x = dp[i+n/2][j];

						while(x)
						{
							v = m1[x & ~(x-1)];
							val = j*64+v;

							if(abs(sum-2*val) < min)
							{
								t1 = sum-val;
								t2 = val;
								min = abs(sum-2*val);
							}

							x = x-(x & ~(x-1));
						}
					}
		}
		else
		{
			min = INT_MAX;
			for(j=0; j<=q_sum; j++)
				if(dp[n/2][j])
				{
					x = dp[n/2][j];

					while(x)
					{
						v = m1[x & ~(x-1)];
						val = j*64+v;

						if(abs(sum-2*val) < min)
						{
							t1 = sum-val;
							t2 = val;
							min = abs(sum-2*val);
						}

						x = x-(x & ~(x-1));
					}
				}
		}

		if(t1 < t2)
			printf("%d %d\n", t1, t2);
		else
			printf("%d %d\n", t2, t1);

		if(no)
			printf("\n");
	}

	return 0;
}

