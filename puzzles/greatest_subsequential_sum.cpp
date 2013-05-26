//Kadane's Algorithm
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, max_so_far, max_ending_here, x, i, begin, end, maxbegin, maxend;

	while(scanf("%d", &n) != EOF)
	{
		int a[n+1];
		max_so_far = max_ending_here = begin = end = 0;

		for(i=0; i<n; i++)
		{
			scanf("%d", &a[i]);

			if(max_ending_here+a[i] > 0)
			{
				max_ending_here += a[i];
				end++;
			}
			else
			{
				max_ending_here = 0;
				begin = i+1;
				end = i+1;
			}

			if(max_so_far < max_ending_here)
			{
				max_so_far = max_ending_here;
				maxbegin = begin;
				maxend = end;
			}

//			max_ending_here = max(0, max_ending_here+x);
//			max_so_far = max(max_ending_here, max_so_far);
		}

		printf("%d\n", max_so_far);

		printf("%d %d\n", maxbegin, maxend);

		for(i=maxbegin; i<maxend; i++)
			printf("%d ", a[i]);
		printf("\n");
	}

	return 0;
}
